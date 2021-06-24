#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
}
