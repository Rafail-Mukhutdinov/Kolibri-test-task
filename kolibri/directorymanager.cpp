#include "directorymanager.h"

DirectoryManager::DirectoryManager()
{

}

QStringList DirectoryManager::searchFilesAndSubdirectories(const QString &folderPath)
{
    QDir directory(folderPath);
    if (!directory.exists())
    {
        qWarning() << "Директория не существует:" << folderPath;
        return {};
    }

   // QDirIterator it(folderPath, QStringList() << "*.txt" << "*.bin", QDir::Files, QDirIterator::Subdirectories);

    QStringList filePaths;
    QDirIterator it(folderPath, QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        it.next();
        QFileInfo fileInfo(it.filePath());
        if (fileInfo.isFile())
        {
            filePaths << fileInfo.filePath();
        }
    }
    return filePaths;
}

void DirectoryManager::checkFileType(const QString &filePath)
{

    QFileInfo fileInfo(filePath);

    if (!fileInfo.exists())
    {
        qWarning() << "Файл не существует:" << filePath;
        return;
    }

    QString fileType = fileInfo.suffix();
    if (fileType == "txt" || fileType == "bin")
    {
        qDebug() << "Файл" << filePath << "является файлом типа" << fileType;
    } else
    {
        qDebug() << "Файл" << filePath << "не является .txt или .bin файлом";
    }
}


bool DirectoryManager::isDirectoryValid(const QString &paramDir)
{
    return !paramDir.trimmed().isEmpty() && QDir(paramDir).exists();
}
