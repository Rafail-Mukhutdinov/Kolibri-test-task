#include "textconverter.h"

TextConverter::TextConverter() {}

// Возвращаем массив маски файлов
QStringList TextConverter::getArrFileTypesMask()
{
    return QStringList(arrayOfFileTypesMask.begin(), arrayOfFileTypesMask.end());
}

QStringList TextConverter::getUniqueWords(const QString &sentence)
{
    //Если массив не пустой очищаем его
    if(!arrayOfFileTypesMask.empty()) arrayOfFileTypesMask.clear();

    // Разделение входной строки на слова по пробелам
    QStringList words = sentence.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);

    // Создание регулярного выражения для поиска имен файлов с расширениями .txt и .bin
    QRegularExpression pattern("^(.*\\.txt|.*\\.bin)$", QRegularExpression::CaseInsensitiveOption);

    // Проверка, есть ли символ '*' в строке
    bool hasAsteriskTxt = sentence.contains("*.txt");
    bool hasAsteriskBin = sentence.contains("*.bin");

    if(hasAsteriskTxt)
    {
        arrayOfFileTypesMask << "*.txt";
    }
    if(hasAsteriskBin)
    {
        arrayOfFileTypesMask << "*.bin";
    }

    // Цикл по всем словам в списке
    for(const auto &item : words)
    {
        // Если имя файла соответствует шаблону и его еще нет в списке, добавляем его
        if (pattern.match(item).hasMatch() && !arrayOfFileTypesMask.contains(item))
        {

            // Если в строке есть символ '*' перед .txt и имя файла заканчивается на .txt, пропускаем его
            if (hasAsteriskTxt && item.endsWith(".txt"))
            {
                continue;
            }
            // Если в строке есть символ '*' перед .bin и имя файла заканчивается на .bin, пропускаем его
            if (hasAsteriskBin && item.endsWith(".bin"))
            {
                continue;
            }
            // В противном случае, добавляем имя файла в список
            arrayOfFileTypesMask << item;
        }
    }
    // Возвращаем список уникальных имен файлов
    return arrayOfFileTypesMask;
}

QValidator* TextConverter::createHexValidator(const QString textvalid)
{
    QValidator *validator = new QRegularExpressionValidator(QRegularExpression(textvalid), nullptr);
    return validator;
}


