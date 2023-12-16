//#ifndef CONDITIONCONTROLLER_H
//#define CONDITIONCONTROLLER_H
#pragma once



#include "paramformmain.h"
#include "ui_mainwindow.h"
#include "textconverter.h"


class ConditionController
{

public:
    ConditionController();

    bool checkLineEditNotEmpty(Ui::MainWindow *cui, const ParamFormMain &paramLineEdit);

    bool isDirectoryValid(const QString &paramDir);

private:
    // Проверяем на корректность заданной директории
   // bool isDirectoryValid (const QString &paramDir);
    //bool isDirectoryValid(const QString &paramDir, const QString &errorMessage, QString &text_info);
    bool checkInputNotEmpty(const QString &input, const QString &errorMessage, QString &text_info);
    //QStringList getUniqueWords(const QString& sentence);





private:
    TextConverter textcont;

};

//#endif // CONDITIONCONTROLLER_H
