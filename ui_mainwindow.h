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
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_PointCloudFilePath;
    QPushButton *pushButton_SelectPointCloud;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_ModelPath;
    QPushButton *pushButton_SelectModel;
    QGroupBox *groupBox_2;
    QTableView *tableView_DataList;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_CPMatch;
    QPushButton *pushButton_DataExport;
    QProgressBar *progressBar_MatchingProgress;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView_DispWindow;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1186, 779);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(760, 10, 411, 111));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 17, 391, 81));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_PointCloudFilePath = new QLineEdit(layoutWidget);
        lineEdit_PointCloudFilePath->setObjectName(QString::fromUtf8("lineEdit_PointCloudFilePath"));

        horizontalLayout->addWidget(lineEdit_PointCloudFilePath);

        pushButton_SelectPointCloud = new QPushButton(layoutWidget);
        pushButton_SelectPointCloud->setObjectName(QString::fromUtf8("pushButton_SelectPointCloud"));

        horizontalLayout->addWidget(pushButton_SelectPointCloud);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit_ModelPath = new QLineEdit(layoutWidget);
        lineEdit_ModelPath->setObjectName(QString::fromUtf8("lineEdit_ModelPath"));

        horizontalLayout_2->addWidget(lineEdit_ModelPath);

        pushButton_SelectModel = new QPushButton(layoutWidget);
        pushButton_SelectModel->setObjectName(QString::fromUtf8("pushButton_SelectModel"));

        horizontalLayout_2->addWidget(pushButton_SelectModel);


        verticalLayout->addLayout(horizontalLayout_2);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(760, 126, 411, 481));
        tableView_DataList = new QTableView(groupBox_2);
        tableView_DataList->setObjectName(QString::fromUtf8("tableView_DataList"));
        tableView_DataList->setGeometry(QRect(10, 20, 391, 441));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(760, 610, 411, 111));
        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 391, 71));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_CPMatch = new QPushButton(layoutWidget1);
        pushButton_CPMatch->setObjectName(QString::fromUtf8("pushButton_CPMatch"));

        horizontalLayout_3->addWidget(pushButton_CPMatch);

        pushButton_DataExport = new QPushButton(layoutWidget1);
        pushButton_DataExport->setObjectName(QString::fromUtf8("pushButton_DataExport"));

        horizontalLayout_3->addWidget(pushButton_DataExport);


        verticalLayout_2->addLayout(horizontalLayout_3);

        progressBar_MatchingProgress = new QProgressBar(layoutWidget1);
        progressBar_MatchingProgress->setObjectName(QString::fromUtf8("progressBar_MatchingProgress"));
        progressBar_MatchingProgress->setMaximum(0);
        progressBar_MatchingProgress->setValue(0);

        verticalLayout_2->addWidget(progressBar_MatchingProgress);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 741, 711));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView_DispWindow = new QGraphicsView(gridLayoutWidget);
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

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1186, 26));
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
