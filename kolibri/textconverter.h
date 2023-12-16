#ifndef TEXTCONVERTER_H
#define TEXTCONVERTER_H

#include <QStringList>
#include <QRegularExpression>
#include <QDir>

//#include "paramformmain.h"

class TextConverter
{
public:
    TextConverter();
    //Возвращает текстовое сообщение состояния виджитов LineEdit
    QString     getTextInfo() {return textinfo;}

    QStringList getUniqueWords(const QString &sentence);
private:

    // bool isDirectoryValid(const QString &paramDir);

private:
    // текстовое сообщение
    QString textinfo;


};

#endif // TEXTCONVERTER_H
