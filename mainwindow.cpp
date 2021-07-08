#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include "HalconCpp.h"
#include "HDevThread.h"
#include "halconvisualize.h"

#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif
#include <QStandardItemModel>

HalconVisualize halconVisualize;

QStandardItemModel* model = new QStandardItemModel();
QString modelPath;
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
    modelPath = QFileDialog::getOpenFileName(this, "选择模型文件", ".", "Model(*om3);;Model(*stl);;All(*.*)");
    //QMessageBox::critical(NULL, QStringLiteral("Test"), QString(modelPath), QMessageBox::Yes| QMessageBox::No, QMessageBox::Yes);
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
                model->item(i, 1)->setForeground(QBrush(QColor(255, 0, 0)));
            }
        }
    }
    else
    {
        QMessageBox::warning(NULL, QStringLiteral("warning"), QString("输入数据不相等！"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
}

void MainWindow::on_pushButton_CPMatch_clicked()
{
    Matching();
    TableViewData();
}

void MainWindow::on_pushButton_DataExport_clicked()
{
    QString curPath = QDir::currentPath();
    QString dlgTitle = "Save File";
    QString filter = "TXT(*.txt)";
    QString aFileName = QFileDialog::getSaveFileName(this, dlgTitle, curPath, filter);
    if (aFileName.isEmpty()) { return; }
    QFile afile(aFileName);
    if (!afile.open(QIODevice::WriteOnly | QIODevice::Text)) { return; }
    for (int i = 0; i < nameList.length(); i++) 
    {
        QString str = xList[i] + "," + yList[i] + "," + zList[i] + ",\r";
        QByteArray strBytes = str.toUtf8();
        afile.write(strBytes, strBytes.length());
    }
    afile.close();
}

void MainWindow::Matching() 
{
    HTuple  hv_WindowHandle;
    HTuple  hv_ObjectModel3D, hv_Status, hv_SurfaceModelID;
    HTuple  hv_Index, hv_ObjectModel3D1, hv_Status1, hv_ObjectModel3DThresholded;
    HTuple  hv_Pose, hv_Score, hv_SurfaceMatchingResultID, hv_ObjectModel3DRigidTrans;
    HTuple  hv_PoseOut;

    Hlong windowID = (Hlong)this->ui->graphicsView_DispWindow->winId();
    /*if (HDevWindowStack::IsOpen())
        CloseWindow(HDevWindowStack::Pop());*/
    CloseWindow(hv_WindowHandle);
    OpenWindow(0, 0, ui->graphicsView_DispWindow->width(), ui->graphicsView_DispWindow->height(), windowID, "visible", "", &hv_WindowHandle);
    SetWindowAttr("background_color", "black");
    /*OpenWindow(0, 0, 512, 512, 0, "visible", "", &hv_WindowHandle);*/
    HDevWindowStack::Push(hv_WindowHandle);

    QByteArray ba = modelPath.toLatin1();
    const char * hv_ModelPath = ba.data();

    ReadObjectModel3d(hv_ModelPath, "m", HTuple(), HTuple(), &hv_ObjectModel3D, &hv_Status);
    CreateSurfaceModel(hv_ObjectModel3D, 0.03, HTuple(), HTuple(), &hv_SurfaceModelID);
    for (int i=0;i<nameList.length();i++)
    {
        QByteArray qba = nameList[i].toLatin1();
        const char* hv_CloudPath = qba.data();
        ReadObjectModel3d(hv_CloudPath, "m", HTuple(), HTuple(), &hv_ObjectModel3D1, &hv_Status1);
        SelectPointsObjectModel3d(hv_ObjectModel3D1, "point_coord_z", 0.5, 1, &hv_ObjectModel3DThresholded);
        FindSurfaceModel(hv_SurfaceModelID, hv_ObjectModel3D1, 0.05, 0.2, 0, "false", HTuple(), HTuple(), &hv_Pose, &hv_Score, &hv_SurfaceMatchingResultID);
        RigidTransObjectModel3d(hv_ObjectModel3D, hv_Pose, &hv_ObjectModel3DRigidTrans);
        halconVisualize.visualize_object_model_3d(hv_WindowHandle, hv_ObjectModel3DRigidTrans.TupleConcat(hv_ObjectModel3D1),
            HTuple(), HTuple(), (HTuple("color_0").Append("color_1")), (HTuple("green").Append("gray")), HTuple(), HTuple(), HTuple(), &hv_PoseOut);
    }
}