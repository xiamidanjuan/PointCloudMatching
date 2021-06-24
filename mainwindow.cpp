#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif
#include <QStandardItemModel>

QStandardItemModel* model = new QStandardItemModel();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    ui->tableView_DataList->setModel(model);
    model->setColumnCount(5);
    model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("Name"));
    model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("Score"));
    model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("X"));
    model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("Y"));
    model->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("Z"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_SelectModel_clicked()
{
    QString filepath = QString::null;
    filepath = QFileDialog::getOpenFileName(this, "选择模型文件", ".", "Model(*om3);;Model(*stl);;All(*.*)");
    QMessageBox::critical(NULL, QStringLiteral("Test"), QString(filepath), QMessageBox::Yes| QMessageBox::No, QMessageBox::Yes);
}

void MainWindow::on_pushButton_SelectPointCloud_clicked()
{
    QStringList filePathList;
    filePathList = QFileDialog::getOpenFileNames(this, "选择点云文件", ".", "PointCloud(*ply)");

    for (int i = 0; i < filePathList.length(); i++) 
    {
        model->setItem(i, 0, new QStandardItem(filePathList[i]));
    }
    model->item(3, 0)->setForeground(QBrush(QColor(255, 0, 0)));
}
