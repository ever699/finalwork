/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_main;
    QVBoxLayout *verticalLayout_left;
    QCalendarWidget *calendarWidget;
    QListWidget *taskListWidget;
    QVBoxLayout *verticalLayout_right;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QLabel *label_time;
    QLineEdit *lineEdit_time;
    QLabel *label_priority;
    QLineEdit *lineEdit_priority;
    QSpacerItem *verticalSpacer;
    QPushButton *btnAdd;
    QPushButton *btnDelete;
    QLabel *lblStatus;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(900, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_main = new QHBoxLayout(centralwidget);
        horizontalLayout_main->setObjectName(QString::fromUtf8("horizontalLayout_main"));
        verticalLayout_left = new QVBoxLayout();
        verticalLayout_left->setObjectName(QString::fromUtf8("verticalLayout_left"));
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy);

        verticalLayout_left->addWidget(calendarWidget);

        taskListWidget = new QListWidget(centralwidget);
        taskListWidget->setObjectName(QString::fromUtf8("taskListWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(taskListWidget->sizePolicy().hasHeightForWidth());
        taskListWidget->setSizePolicy(sizePolicy1);

        verticalLayout_left->addWidget(taskListWidget);


        horizontalLayout_main->addLayout(verticalLayout_left);

        verticalLayout_right = new QVBoxLayout();
        verticalLayout_right->setObjectName(QString::fromUtf8("verticalLayout_right"));
        label_name = new QLabel(centralwidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        verticalLayout_right->addWidget(label_name);

        lineEdit_name = new QLineEdit(centralwidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setReadOnly(true);

        verticalLayout_right->addWidget(lineEdit_name);

        label_time = new QLabel(centralwidget);
        label_time->setObjectName(QString::fromUtf8("label_time"));

        verticalLayout_right->addWidget(label_time);

        lineEdit_time = new QLineEdit(centralwidget);
        lineEdit_time->setObjectName(QString::fromUtf8("lineEdit_time"));
        lineEdit_time->setReadOnly(true);

        verticalLayout_right->addWidget(lineEdit_time);

        label_priority = new QLabel(centralwidget);
        label_priority->setObjectName(QString::fromUtf8("label_priority"));

        verticalLayout_right->addWidget(label_priority);

        lineEdit_priority = new QLineEdit(centralwidget);
        lineEdit_priority->setObjectName(QString::fromUtf8("lineEdit_priority"));
        lineEdit_priority->setReadOnly(true);

        verticalLayout_right->addWidget(lineEdit_priority);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_right->addItem(verticalSpacer);

        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));

        verticalLayout_right->addWidget(btnAdd);

        btnDelete = new QPushButton(centralwidget);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));

        verticalLayout_right->addWidget(btnDelete);

        lblStatus = new QLabel(centralwidget);
        lblStatus->setObjectName(QString::fromUtf8("lblStatus"));
        lblStatus->setAlignment(Qt::AlignCenter);

        verticalLayout_right->addWidget(lblStatus);


        horizontalLayout_main->addLayout(verticalLayout_right);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "My Schedule Manager", nullptr));
        MainWindow->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"    /* \346\225\264\344\270\252\347\252\227\345\217\243\347\232\204\350\203\214\346\231\257\350\211\262 */\n"
"    QMainWindow { background-color: #f4f4f9; }\n"
"\n"
"    /* \346\227\245\345\216\206\346\216\247\344\273\266\347\232\204\346\240\267\345\274\217 */\n"
"    QCalendarWidget { background-color: white; border: 1px solid #ddd; border-radius: 8px; padding: 5px; }\n"
"\n"
"    /* \344\273\273\345\212\241\345\210\227\350\241\250\347\232\204\346\240\267\345\274\217 */\n"
"    QListWidget { background-color: white; border: 1px solid #ddd; border-radius: 8px; padding: 5px; }\n"
"\n"
"    /* \350\276\223\345\205\245\346\241\206\347\232\204\346\240\267\345\274\217 */\n"
"    QLineEdit { background-color: #ffffff; border: 1px solid #ccc; border-radius: 4px; padding: 5px; }\n"
"\n"
"    /* \346\267\273\345\212\240\346\214\211\351\222\256\347\232\204\346\240\267\345\274\217 */\n"
"    QPushButton#btnAdd { background-color: #4CAF50; color: white; border: none; border-radius: 5px; padding: 10px; font-weight: b"
                        "old; }\n"
"    QPushButton#btnAdd:hover { background-color: #45a049; }\n"
"\n"
"    /* \345\210\240\351\231\244\346\214\211\351\222\256\347\232\204\346\240\267\345\274\217 */\n"
"    QPushButton#btnDelete { background-color: #f44336; color: white; border: none; border-radius: 5px; padding: 10px; font-weight: bold; }\n"
"    QPushButton#btnDelete:hover { background-color: #da190b; }\n"
"   ", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow", "\360\237\223\235 \344\273\273\345\212\241\345\220\215\347\247\260\357\274\232", nullptr));
        label_time->setText(QCoreApplication::translate("MainWindow", "\342\217\260 \345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", nullptr));
        label_priority->setText(QCoreApplication::translate("MainWindow", "\360\237\224\245 \344\274\230\345\205\210\347\272\247\357\274\232", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "\342\236\225 \346\267\273\345\212\240\344\273\273\345\212\241", nullptr));
        btnDelete->setText(QCoreApplication::translate("MainWindow", "\342\235\214 \345\210\240\351\231\244\344\273\273\345\212\241", nullptr));
        lblStatus->setText(QCoreApplication::translate("MainWindow", "\360\237\222\241 \346\217\220\347\244\272\357\274\232\345\217\214\345\207\273\344\273\273\345\212\241\345\217\257\346\237\245\347\234\213\350\257\246\346\203\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
