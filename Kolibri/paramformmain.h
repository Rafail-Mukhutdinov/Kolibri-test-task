#ifndef PARAMFORMMAIN_H
#define PARAMFORMMAIN_H

#include <QString>

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

#endif // PARAMFORMMAIN_H
