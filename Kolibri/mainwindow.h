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


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //метод модифицирует входные файлы.
    void modifyFile(const QString& filePath);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
   // void on_selectFileButton_clicked();
    QString getOpenFile(const QString &formatFale);

   // void on_checkBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;


private:
    QString inputMask;                                  //для хранения маски входных файлов.
    bool deleteInputFiles;                              //для определения, нужно ли удалять входные файлы.
    QString outputPath;                                 //для хранения пути сохранения результирующих файлов.
    bool overwriteOutputFiles;                          //для определения действий при повторении имени выходного файла.
    bool timerMode;                                     //для определения режима работы по таймеру или разового запуска.
    int timerInterval;                                  //для хранения периодичности опроса наличия входного файла.
    quint64 operationValue;                             //для хранения значения 8 байт для бинарной операции модификации файла.

};
#endif // MAINWINDOW_H
