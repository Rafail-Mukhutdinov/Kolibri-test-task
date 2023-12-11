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

#include "conditioncontroller.h"
#include "directorymanager.h"


struct ParamFormMain
{
    QString inputMaskFile;          //для хранение маски файла.
    QString inputDirStart;          //для хранения директории входных файлов.
    QString inputMaskXor;           //для хранения маски входных файлов.
    QString outputDirFinish;        //для хранения пути сохранения результирующих файлов.

    bool deleteInputFiles;          //для определения, нужно ли удалять входные файлы.
    bool searchAttachedFiles;       //для определения, нужно ли искать во вложенных папках.

    bool radioModifyOverride;       //для определения, состояния зависимого переключателя radioButton Перезаписать файл, Модифицировать файл
    bool radioOnelaunchTimer;       //для определения, состояния зависимого переключателя radioButton Разовый запуск, Работа по таймеру

    // quint64 operationValue;       //для хранения значения 8 байт для бинарной операции модификации файла.
    int timerInterval;              //для хранения периодичности опроса наличия входного файла.


    bool overwriteOutputFiles;      //для определения действий при повторении имени выходного файла.
    bool timerMode;                 //для определения режима работы по таймеру или разового запуска.
};



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

private:

    Ui::MainWindow *ui;
    ParamFormMain param;
    ConditionController controler;
    DirectoryManager dirmaneger;

private:
};
#endif // MAINWINDOW_H
