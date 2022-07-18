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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView_DispWindow;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_PointCloudFilePath;
    QPushButton *pushButton_SelectPointCloud;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_ModelPath;
    QPushButton *pushButton_SelectModel;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QTableView *tableView_DataList;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_CPMatch;
    QPushButton *pushButton_DataExport;
    QProgressBar *progressBar_MatchingProgress;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1268, 831);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView_DispWindow = new QGraphicsView(centralwidget);
        graphicsView_DispWindow->setObjectName(QString::fromUtf8("graphicsView_DispWindow"));
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

        gridLayout->addWidget(graphicsView_DispWindow, 0, 0, 1, 1);


        horizontalLayout_4->addLayout(gridLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_PointCloudFilePath = new QLineEdit(groupBox);
        lineEdit_PointCloudFilePath->setObjectName(QString::fromUtf8("lineEdit_PointCloudFilePath"));

        horizontalLayout->addWidget(lineEdit_PointCloudFilePath);

        pushButton_SelectPointCloud = new QPushButton(groupBox);
        pushButton_SelectPointCloud->setObjectName(QString::fromUtf8("pushButton_SelectPointCloud"));

        horizontalLayout->addWidget(pushButton_SelectPointCloud);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit_ModelPath = new QLineEdit(groupBox);
        lineEdit_ModelPath->setObjectName(QString::fromUtf8("lineEdit_ModelPath"));

        horizontalLayout_2->addWidget(lineEdit_ModelPath);

        pushButton_SelectModel = new QPushButton(groupBox);
        pushButton_SelectModel->setObjectName(QString::fromUtf8("pushButton_SelectModel"));

        horizontalLayout_2->addWidget(pushButton_SelectModel);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout_4->addLayout(verticalLayout, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tableView_DataList = new QTableView(groupBox_2);
        tableView_DataList->setObjectName(QString::fromUtf8("tableView_DataList"));

        gridLayout_3->addWidget(tableView_DataList, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_CPMatch = new QPushButton(groupBox_3);
        pushButton_CPMatch->setObjectName(QString::fromUtf8("pushButton_CPMatch"));

        horizontalLayout_3->addWidget(pushButton_CPMatch);

        pushButton_DataExport = new QPushButton(groupBox_3);
        pushButton_DataExport->setObjectName(QString::fromUtf8("pushButton_DataExport"));

        horizontalLayout_3->addWidget(pushButton_DataExport);


        verticalLayout_2->addLayout(horizontalLayout_3);

        progressBar_MatchingProgress = new QProgressBar(groupBox_3);
        progressBar_MatchingProgress->setObjectName(QString::fromUtf8("progressBar_MatchingProgress"));
        progressBar_MatchingProgress->setMaximum(0);
        progressBar_MatchingProgress->setValue(0);

        verticalLayout_2->addWidget(progressBar_MatchingProgress);


        gridLayout_5->addLayout(verticalLayout_2, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox_3);


        horizontalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_4->setStretch(0, 2);
        horizontalLayout_4->setStretch(1, 1);

        horizontalLayout_5->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1268, 23));
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
