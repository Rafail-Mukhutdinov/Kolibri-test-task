#ifndef PARAMFORMMAIN_H
#define PARAMFORMMAIN_H

#include <QString>

struct ParamFormMain
{
    ParamFormMain():inputMaskFile(""),
                    inputDirStart(""),
                    inputMaskXor(""),
                    outputDirFinish(""),
                    deleteInputFiles(false),
                    searchAttachedFiles(false),
                    radioModifyOverride(true),
                    radioOnelaunchTimer(true),
                    timerInterval(0),
                    bottonClickStop(false){};
    QString inputMaskFile;          //для хранение маски файла.
    QString inputDirStart;          //для хранения директории входных файлов.
    QString inputMaskXor;           //для хранения маски входных файлов.
    QString outputDirFinish;        //для хранения пути сохранения результирующих файлов.

    bool deleteInputFiles;          //для определения, нужно ли удалять входные файлы.
    bool searchAttachedFiles;       //для определения, нужно ли искать во вложенных папках.

    bool radioModifyOverride;       //для определения, состояния зависимого переключателя radioButton Перезаписать файл, Модифицировать файл
    bool radioOnelaunchTimer;       //для определения, состояния зависимого переключателя radioButton Разовый запуск, Работа по таймеру

    int timerInterval;              //для хранения периодичности опроса наличия входного файла.
    bool bottonClickStop;


};

#endif // PARAMFORMMAIN_H
