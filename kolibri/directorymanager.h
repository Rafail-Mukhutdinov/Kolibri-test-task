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

    bool isDirectoryValid(const QString &paramDir);

    DirectoryManager();
};

#endif // DIRECTORYMANAGER_H
