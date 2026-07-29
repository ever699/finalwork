#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QtConcurrent/QtConcurrent>
#include <QFutureWatcher>
#include "taskmanager.h"
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddTaskClicked();
    void onDeleteTaskClicked();
    void onTaskClicked(QListWidgetItem* item);
    void onTasksLoaded();

private:
    Ui::MainWindow *ui;
    TaskManager taskManager;

    void refreshTaskList();
    void loadTasksAsync();

    QFutureWatcher<void> taskWatcher;
};

#endif // MAINWINDOW_H
