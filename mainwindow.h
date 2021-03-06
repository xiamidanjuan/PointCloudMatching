#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_SelectModel_clicked();

    void on_pushButton_SelectPointCloud_clicked();

    void TableViewData(int);

    void on_pushButton_CPMatch_clicked();

    void on_pushButton_DataExport_clicked();

    void Matching();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
