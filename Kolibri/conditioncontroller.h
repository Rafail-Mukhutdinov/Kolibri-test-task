//#ifndef CONDITIONCONTROLLER_H
//#define CONDITIONCONTROLLER_H
#pragma once
#include <QDir>

#include "paramformmain.h"
#include "ui_mainwindow.h"


class ConditionController
{

public:
    ConditionController();

    bool checkLineEditNotEmpty(Ui::MainWindow *cui, const ParamFormMain &paramLineEdit);

private:
    // Проверяем на корректность заданной директории
    bool isDirectoryValid (const QString &paramDir);

};

//#endif // CONDITIONCONTROLLER_H
