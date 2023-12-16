#include "textconverter.h"

TextConverter::TextConverter() {}







// Определение функции getUniqueWords
QStringList TextConverter::getUniqueWords(const QString &sentence)
{
    QStringList uniqueMaskFile;
    // Разделение входной строки на слова по пробелам
    QStringList words = sentence.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);

    // Создание регулярного выражения для поиска имен файлов с расширениями .txt и .bin
    QRegularExpression pattern("^(.*\\.txt|.*\\.bin)$", QRegularExpression::CaseInsensitiveOption);

    // Проверка, есть ли символ '*' в строке
    bool hasAsteriskTxt = sentence.contains("*.txt");
    bool hasAsteriskBin = sentence.contains("*.bin");

    if(hasAsteriskTxt){
        uniqueMaskFile << "*.txt";
    }
    if(hasAsteriskBin){
        uniqueMaskFile << "*.bin";
    }

    // Цикл по всем словам в списке
    for(const auto &item : words){
        // Если имя файла соответствует шаблону и его еще нет в списке, добавляем его
        if (pattern.match(item).hasMatch() && !uniqueMaskFile.contains(item)) {

            // Если в строке есть символ '*' перед .txt и имя файла заканчивается на .txt, пропускаем его
            if (hasAsteriskTxt && item.endsWith(".txt")) {
                continue;
            }
            // Если в строке есть символ '*' перед .bin и имя файла заканчивается на .bin, пропускаем его
            if (hasAsteriskBin && item.endsWith(".bin")) {
                continue;
            }
            // В противном случае, добавляем имя файла в список
            uniqueMaskFile << item;
        }
    }
    // Возвращаем список уникальных имен файлов
    return uniqueMaskFile;
}



