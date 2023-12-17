#ifndef CONDITIONCONTROLLER_H
#define CONDITIONCONTROLLER_H




#include "paramformmain.h"
#include "ui_mainwindow.h"
#include "textconverter.h"
#include "directorymanager.h"


class ConditionController
{

public:
    ConditionController();

    bool checkLineEditNotEmpty(Ui::MainWindow *cui, const ParamFormMain &paramLineEdit);



private:
    // Проверяем на корректность заданной директории
   // bool isDirectoryValid (const QString &paramDir);
    //bool isDirectoryValid(const QString &paramDir, const QString &errorMessage, QString &text_info);
    bool checkInputNotEmpty(const QString &input, const QString &errorMessage, QString &text_info);
    //

private:
    QStringList arrayOfFileTypesMask;
    TextConverter textCont;
    DirectoryManager dirManager;
};

#endif // CONDITIONCONTROLLER_H
