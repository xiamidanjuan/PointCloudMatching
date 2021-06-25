#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif
#include <QStandardItemModel>

QStandardItemModel* model = new QStandardItemModel();
QStringList nameList, scoreList, xList, yList, zList;

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
    nameList = QFileDialog::getOpenFileNames(this, "选择点云文件", ".", "PointCloud(*ply)");
    scoreList = nameList;
    xList = nameList;
    yList = nameList;
    zList = nameList;
}

void MainWindow::TableViewData()
{
    if (nameList.length()== scoreList.length()&& nameList.length() == xList.length()&& nameList.length() == yList.length()&& nameList.length() == zList.length())
    {
        for (int i = 0; i < nameList.length(); i++) 
        {
            model->setItem(i, 0, new QStandardItem(nameList[i]));
            model->setItem(i, 1, new QStandardItem(scoreList[i]));
            model->setItem(i, 2, new QStandardItem(xList[i]));
            model->setItem(i, 3, new QStandardItem(yList[i]));
            model->setItem(i, 4, new QStandardItem(zList[i]));

            if (scoreList[i].toDouble() < 0.15) 
            {
                model->item(i, 0)->setForeground(QBrush(QColor(255, 0, 0)));
            }
        }
    }
    else
    {
        QMessageBox::warning(NULL, QStringLiteral("warning"), QString("输入数据不相等！"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
}
