#ifndef TEXTCONVERTER_H
#define TEXTCONVERTER_H

#include <QStringList>
#include <QRegularExpression>
#include <QDir>
#include <QValidator>

//#include "paramformmain.h"

class TextConverter
{
public:
    TextConverter();
    //Возвращает текстовое сообщение состояния виджитов LineEdit
    QString     getTextInfo() {return textinfo;}

    //Возвращаем массив маки файлов
    QStringList getArrFileTypesMask();

    //Возвращаем маску файла в текстовом формате
    QString getTextFileTypeMask();

    QStringList getUniqueWords(const QString &sentence);

    QValidator* createHexValidator(const QString textvalid);


private:

    // bool isDirectoryValid(const QString &paramDir);

private:
    // текстовое сообщение
    QString textinfo;
    //Массив значений маски
    QStringList arrayOfFileTypesMask;
    //Текстовое значение маски
    QString textFileTypeMask;



};

#endif // TEXTCONVERTER_H
