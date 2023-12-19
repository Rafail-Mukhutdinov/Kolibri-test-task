#ifndef DIRECTORYMANAGER_H
#define DIRECTORYMANAGER_H

#include <QString>
#include <QDir>
#include <QDirIterator>
#include <QDebug>
#include <QApplication>
#include <QFile>
#include "paramformmain.h"
//#include "hexadecimalxorprocessor.h"

class DirectoryManager
{
public:
    bool isDirectoryValid(const QString &paramDir);

    // Модификация файлы
    void modifyInputFiles(QFile &file, const ParamFormMain &paramForm, QDirIterator &dirIterator, QString &outFile);

    DirectoryManager();

private:
   // HexadecimalXORProcessor hex1;

};

#endif // DIRECTORYMANAGER_H
