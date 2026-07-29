#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QDateTime>
#include <ctime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 绑定多线程加载结束信号
    connect(&taskWatcher, &QFutureWatcher<void>::finished, this, &MainWindow::onTasksLoaded);

    // 绑定按钮和列表的点击信号
    connect(ui->btnAdd, &QPushButton::clicked, this, &MainWindow::onAddTaskClicked);
    connect(ui->btnDelete, &QPushButton::clicked, this, &MainWindow::onDeleteTaskClicked);
    connect(ui->taskListWidget, &QListWidget::itemClicked, this, &MainWindow::onTaskClicked);

    // 后台多线程读取 CSV 文件
    loadTasksAsync();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadTasksAsync()
{
    ui->lblStatus->setText("⏳ 正在后台加载任务数据...");

    QFuture<void> future = QtConcurrent::run([this]() {
        taskManager.loadFile("data/tasks.csv");
    });

    taskWatcher.setFuture(future);
}

void MainWindow::onTasksLoaded()
{
    refreshTaskList();
    ui->lblStatus->setText("✅ 数据加载完成！当前共有 " + QString::number(taskManager.getTasks().size()) + " 个任务");
}

void MainWindow::refreshTaskList()
{
    ui->taskListWidget->clear();

    for (const auto& task : taskManager.getTasks()) {
        QString displayText = QString::fromStdString(task.GetTaskName()) +
                              " | " +
                              QDateTime::fromSecsSinceEpoch(task.GetStartTime()).toString("yyyy-MM-dd hh:mm");
        ui->taskListWidget->addItem(displayText);
    }
}

void MainWindow::onAddTaskClicked()
{
    bool ok;
    QString taskName = QInputDialog::getText(this, "添加新任务", "请输入任务名称:", QLineEdit::Normal, "", &ok);

    if (ok && !taskName.isEmpty()) {
        time_t currentTime = std::time(nullptr);

        bool success = taskManager.addTask(
            taskName.toStdString(),
            currentTime,
            Priority::MEDIUM,
            Category::LIFE,
            currentTime + 3600
        );

        if (success) {
            refreshTaskList();
            ui->lblStatus->setText("✅ 任务 [" + taskName + "] 添加成功！");
        } else {
            QMessageBox::warning(this, "添加失败", "任务时间冲突或添加失败！");
        }
    }
}

void MainWindow::onDeleteTaskClicked()
{
    int currentRow = ui->taskListWidget->currentRow();

    if (currentRow == -1) {
        ui->lblStatus->setText("⚠️ 请先在列表中选中一个任务再删除！");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "确认删除", "确定要删除这个任务吗？",
        QMessageBox::Yes | QMessageBox::No, QMessageBox::No
    );

    if (reply == QMessageBox::Yes) {
        int taskID = taskManager.getTasks()[currentRow].GetID();

        bool success = taskManager.deleteTask(taskID);

        if (success) {
            refreshTaskList();
            ui->lblStatus->setText("❌ 任务已删除！");

            ui->lineEdit_name->setText("（暂无选中任务）");
            ui->lineEdit_time->setText("（暂无选中任务）");
            ui->lineEdit_priority->setText("（暂无选中任务）");
        }
    }
}

void MainWindow::onTaskClicked(QListWidgetItem* item)
{
    int row = ui->taskListWidget->row(item);
    const Task& task = taskManager.getTasks()[row];

    ui->lineEdit_name->setText(QString::fromStdString(task.GetTaskName()));
    ui->lineEdit_time->setText(QDateTime::fromSecsSinceEpoch(task.GetStartTime()).toString("yyyy-MM-dd hh:mm:ss"));

    QString priorityStr = (task.GetPriority() == Priority::HIGH) ? "🔴 高" :
                          (task.GetPriority() == Priority::MEDIUM) ? "🟡 中" : "🟢 低";
    ui->lineEdit_priority->setText(priorityStr);

    ui->lblStatus->setText("💡 你选中了任务，可以查看详情或删除它");
}
