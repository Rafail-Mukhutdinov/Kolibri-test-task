#ifndef CONDITIONCONTROLLER_H
#define CONDITIONCONTROLLER_H

#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
#include <QThread>
#include <QDirIterator>

#include "paramformmain.h"
#include "ui_mainwindow.h"
#include "textconverter.h"
#include "directorymanager.h"
#include "hexadecimalxorprocessor.h"


class ConditionController: public QObject
{
private slots:
       void controlTimer(const ParamFormMain &paramForm);

public:
    ConditionController();

    bool checkLineEditNotEmpty(Ui::MainWindow *cui, ParamFormMain &paramLineEdit);

    void handleEncryptionEvent(QTimer &timer, const ParamFormMain &paramLineEdit);

    void convertFilesToEncodedFormat(QString inputDir, const ParamFormMain &paramForm, const QStringList dirMask);

private:
    QStringList arrayOfFileTypesMask;
    TextConverter textCont;
    DirectoryManager dirManager;
    QTimer timer;
    HexadecimalXORProcessor hex;
};

#endif // CONDITIONCONTROLLER_H
