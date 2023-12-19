#include "directorymanager.h"

DirectoryManager::DirectoryManager()
{

}


bool DirectoryManager::isDirectoryValid(const QString &paramDir)
{
    return !paramDir.trimmed().isEmpty() && QDir(paramDir).exists();
}



// Модификация файлов
void DirectoryManager::modifyInputFiles(QFile &file, const ParamFormMain &paramForm, QDirIterator &dirIterator, QString &outFile)
{
    // Инициализация номера файла
    int number = 1;
    while(true){
        // Создание нового имени файла
        QString newFileName = paramForm.outputDirFinish % "/" % dirIterator.fileName();
        // Поиск последней точки в имени файла
        int index = newFileName.lastIndexOf(".");
        // Создание строки для вставки
        QString insert = " (" % QString::number(number) % ")";
        // Если точка не найдена
        if(index == -1){
            newFileName += insert; // Добавить строку вставки в конец имени файла
        } else {
            newFileName.insert(index,insert); // Вставить строку перед точкой
        }
        // Обновить выходной файл
        outFile = newFileName;
        // Установить новое имя файла
        file.setFileName(outFile);
        // Если файл существует
        if(file.exists()){
            number++; // Увеличить номер файла
            continue; // Продолжить цикл
        } else {
            break; // Выход из цикла
        }
    }
}


