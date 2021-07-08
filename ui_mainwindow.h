/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView_DispWindow;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_PointCloudFilePath;
    QLineEdit *lineEdit_ModelPath;
    QPushButton *pushButton_SelectPointCloud;
    QPushButton *pushButton_SelectModel;
    QGroupBox *groupBox_2;
    QTableView *tableView_DataList;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_CPMatch;
    QPushButton *pushButton_DataExport;
    QProgressBar *progressBar_MatchingProgress;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(935, 606);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView_DispWindow = new QGraphicsView(centralwidget);
        graphicsView_DispWindow->setObjectName(QString::fromUtf8("graphicsView_DispWindow"));
        graphicsView_DispWindow->setGeometry(QRect(10, 10, 571, 541));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        graphicsView_DispWindow->setPalette(palette);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(590, 10, 331, 101));
        lineEdit_PointCloudFilePath = new QLineEdit(groupBox);
        lineEdit_PointCloudFilePath->setObjectName(QString::fromUtf8("lineEdit_PointCloudFilePath"));
        lineEdit_PointCloudFilePath->setGeometry(QRect(10, 20, 201, 21));
        lineEdit_ModelPath = new QLineEdit(groupBox);
        lineEdit_ModelPath->setObjectName(QString::fromUtf8("lineEdit_ModelPath"));
        lineEdit_ModelPath->setGeometry(QRect(10, 60, 201, 21));
        pushButton_SelectPointCloud = new QPushButton(groupBox);
        pushButton_SelectPointCloud->setObjectName(QString::fromUtf8("pushButton_SelectPointCloud"));
        pushButton_SelectPointCloud->setGeometry(QRect(230, 17, 93, 28));
        pushButton_SelectModel = new QPushButton(groupBox);
        pushButton_SelectModel->setObjectName(QString::fromUtf8("pushButton_SelectModel"));
        pushButton_SelectModel->setGeometry(QRect(230, 57, 93, 28));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(590, 120, 331, 341));
        tableView_DataList = new QTableView(groupBox_2);
        tableView_DataList->setObjectName(QString::fromUtf8("tableView_DataList"));
        tableView_DataList->setGeometry(QRect(10, 20, 311, 311));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(590, 470, 331, 81));
        pushButton_CPMatch = new QPushButton(groupBox_3);
        pushButton_CPMatch->setObjectName(QString::fromUtf8("pushButton_CPMatch"));
        pushButton_CPMatch->setGeometry(QRect(10, 20, 93, 28));
        pushButton_DataExport = new QPushButton(groupBox_3);
        pushButton_DataExport->setObjectName(QString::fromUtf8("pushButton_DataExport"));
        pushButton_DataExport->setGeometry(QRect(200, 20, 93, 28));
        progressBar_MatchingProgress = new QProgressBar(groupBox_3);
        progressBar_MatchingProgress->setObjectName(QString::fromUtf8("progressBar_MatchingProgress"));
        progressBar_MatchingProgress->setGeometry(QRect(11, 50, 311, 23));
        progressBar_MatchingProgress->setMaximum(100);
        progressBar_MatchingProgress->setValue(50);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 935, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\351\200\211\346\213\251", nullptr));
        pushButton_SelectPointCloud->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\347\202\271\344\272\221", nullptr));
        pushButton_SelectModel->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\250\241\345\236\213", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\351\242\204\350\247\210", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\244\204\347\220\206", nullptr));
        pushButton_CPMatch->setText(QCoreApplication::translate("MainWindow", "\345\214\271\351\205\215", nullptr));
        pushButton_DataExport->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
