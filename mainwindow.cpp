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

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	ui->tableView_DataList->setModel(model);
	ui->tableView_DataList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	model->setColumnCount(5);
	model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("Name"));
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("Score"));
	model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("X"));
	model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("Y"));
	model->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("Z"));

	ui->progressBar_MatchingProgress->setOrientation(Qt::Horizontal);
	ui->progressBar_MatchingProgress->setMinimum(0);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_SelectModel_clicked()
{
	try
	{
		modelPath = QFileDialog::getOpenFileName(this, "Select Model", ".", "Model(*om3);;Model(*stl);;All(*.*)");
		ui->lineEdit_ModelPath->setText(modelPath);
	}
	catch (const std::exception& e)
	{
		QMessageBox::critical(NULL, QStringLiteral("Critical"), QString(e.what()), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	}
}

void MainWindow::on_pushButton_SelectPointCloud_clicked()
{
	try
	{
		ui->progressBar_MatchingProgress->reset();
		nameList.clear();
		nameList = QFileDialog::getOpenFileNames(this, "Select Point Cloud", ".", "PointCloud(*ply)");
		if (nameList.size() == 0) 
		{
			return;
		}
		ui->lineEdit_PointCloudFilePath->setText(nameList[0]);
		ui->progressBar_MatchingProgress->setMaximum(nameList.length());
	}
	catch (const std::exception& e)
	{
		QMessageBox::critical(NULL, QStringLiteral("Critical"), QString(e.what()), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	}
}

void MainWindow::TableViewData(int i)
{
	try
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
	catch (const std::exception& e)
	{
		QMessageBox::critical(NULL, QStringLiteral("Critical"), QString(e.what()), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	}
}

void MainWindow::on_pushButton_CPMatch_clicked()
{
	scoreList.clear();
	xList.clear();
	yList.clear();
	zList.clear();
	model->clear();
	Matching();
}

void MainWindow::on_pushButton_DataExport_clicked()
{
	try
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
			QString str;
			if (i < nameList.length() - 1)
			{
				str = xList[i] + "," + yList[i] + "," + zList[i] + ",1,\r";
			}
			else
			{
				str = xList[i] + "," + yList[i] + "," + zList[i] + ",1,";
			}
			QByteArray strBytes = str.toUtf8();
			afile.write(strBytes, strBytes.length());
		}
		afile.close();
	}
	catch (const std::exception& e)
	{
		QMessageBox::critical(NULL, QStringLiteral("Critical"), QString(e.what()), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	}
}

void MainWindow::Matching()
{
	try
	{

		if (modelPath.isEmpty() || nameList[0].isEmpty())
		{
			QMessageBox::critical(NULL, QStringLiteral("Critical"), QString("Please import model and point cloud files!"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
			return;
		}
		HTuple  hv_WindowHandle;
		HTuple  hv_ObjectModel3D, hv_Status, hv_SurfaceModelID;
		HTuple  hv_SampledObjectModel3D, hv_ObjectModel3DNormals;
		HTuple  hv_ObjectModel3D1, hv_Status1, hv_ObjectModel3DThresholded;
		HTuple  hv_Pose, hv_Score, hv_SurfaceMatchingResultID, hv_ObjectModel3DRigidTrans;
		HTuple  hv_PoseOut;

		Hlong windowID = (Hlong)this->ui->graphicsView_DispWindow->winId();
		CloseWindow(hv_WindowHandle);
		OpenWindow(0, 0, ui->graphicsView_DispWindow->width(), ui->graphicsView_DispWindow->height(), windowID, "visible", "", &hv_WindowHandle);
		SetWindowAttr("background_color", "black");
		HDevWindowStack::Push(hv_WindowHandle);

		QByteArray ba = modelPath.toLatin1();
		const char* hv_ModelPath = ba.data();

		ReadObjectModel3d(hv_ModelPath, "m", HTuple(), HTuple(), &hv_ObjectModel3D, &hv_Status);
		/*SampleObjectModel3d(hv_ObjectModel3D, 'fast', 5, HTuple(), HTuple(), &hv_SampledObjectModel3D);
		SurfaceNormalsObjectModel3d(hv_SampledObjectModel3D, 'mls', HTuple(), HTuple(), &hv_ObjectModel3DNormals);*/
		CreateSurfaceModel(hv_ObjectModel3D, 0.03, HTuple(), HTuple(), &hv_SurfaceModelID);
		for (int i = 0; i < nameList.length(); i++)
		{
			QByteArray qba = nameList[i].toLatin1();
			const char* hv_CloudPath = qba.data();
			ReadObjectModel3d(hv_CloudPath, "m", HTuple(), HTuple(), &hv_ObjectModel3D1, &hv_Status1);
			FindSurfaceModel(hv_SurfaceModelID, hv_ObjectModel3D1, 0.05, 0.2, 0, "false", HTuple(), HTuple(), &hv_Pose, &hv_Score, &hv_SurfaceMatchingResultID);
			RigidTransObjectModel3d(hv_ObjectModel3D, hv_Pose, &hv_ObjectModel3DRigidTrans);
			halconVisualize.visualize_object_model_3d(hv_WindowHandle, hv_ObjectModel3DRigidTrans.TupleConcat(hv_ObjectModel3D1),
				HTuple(), HTuple(), (HTuple("color_0").Append("color_1")), (HTuple("green").Append("gray")), HTuple(), HTuple(), HTuple(), &hv_PoseOut);

			HString hstrScore = hv_Score.ToString();
			std::string strScore = (std::string)hstrScore;
			QString qstrScore = QString::fromStdString(strScore);
			scoreList.append(qstrScore);

			HString hstrPose = hv_Pose.ToString();
			std::string strPose = (std::string)hstrPose;
			QString qstrPose = QString::fromStdString(strPose);
			qstrPose.remove(QString("["));
			qstrPose.remove(QString(" "));
			QStringList poseList = qstrPose.split(",");
			xList.append(poseList[0]);
			yList.append(poseList[1]);
			zList.append(poseList[2]);
			ui->progressBar_MatchingProgress->setValue(i + 1);
			TableViewData(i);
		}
	}
	catch (const std::exception& e)
	{
		QMessageBox::critical(NULL, QStringLiteral("Critical"), QString(e.what()), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	}
}