#ifndef DIRECTORYMANAGER_H
#define DIRECTORYMANAGER_H

#include <QString>
#include <QDir>
#include <QDirIterator>
#include <QDebug>

class DirectoryManager
{
public:
    QStringList searchFilesAndSubdirectories(const QString &folderPath);

    void checkFileType(const QString &filePath);

    DirectoryManager();
};

#endif // DIRECTORYMANAGER_H
