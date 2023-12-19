#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QFile>
#include <QByteArray>
#include <QDataStream>
#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>
#include <QProcess>
#include <QSysInfo>


#include "paramformmain.h"
#include "conditioncontroller.h"
#include "textconverter.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_lineEdit_mask_xor_textChanged(const QString &arg1);

    void on_lineEdit_mask_file_textChanged(const QString &arg1);

    void on_lineEdit_dir_open_textChanged(const QString &arg1);

    void on_checkBox_delete_file_clicked(bool checked);

    void on_checkBox_search_folders_clicked(bool checked);

    void on_pushButton_dir_open_clicked();

    void on_radioButton_overwriting_toggled(bool checked);

    void on_radioButton_one_start_toggled(bool checked);

    void on_timeEdit_timeChanged(const QTime &time);

    void on_pushButton_dir_save_clicked();

    void on_pushButton_start_clicked();

    void on_pushButton_stop_clicked();

    void on_lineEdit_dir_save_textChanged(const QString &arg1);

private:

    Ui::MainWindow *ui;
    ParamFormMain param;
    ConditionController controler;
    TextConverter textControler;
    QTimer timer;

private:
};
#endif // MAINWINDOW_H
