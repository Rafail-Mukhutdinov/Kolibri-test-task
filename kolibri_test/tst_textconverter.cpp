#include <QtTest>


#include "autotest.h"
#include "../kolibri/textconverter.h"

class tst_TextConverter: public QObject
{
    Q_OBJECT

public:


private slots:
    void getUniqueWords();

};

void tst_TextConverter::getUniqueWords()
{
    TextConverter converter;
    {
        // Проверка работы функции с входной строкой, содержащей имена файлов
        QString sentence = "file1.txt file2.bin file3.txt *.bin *.txt file1.txt file2.bin uuuu fgf.fjuu jhhkk/ bii";
        QStringList result = converter.getUniqueWords(sentence);
        QCOMPARE(result, QStringList() << "*.txt" << "*.bin");
    }

    {
        // Проверка работы функции с входной строкой, содержащей имена файлов
        QString sentence = "file1.txt file3.txt *.txt file1.txt uuuu fgf.fjuu jhhkk/ bii";
        QStringList result = converter.getUniqueWords(sentence);
        QCOMPARE(result, QStringList() << "*.txt" );
    }

    {
        // Проверка работы функции с входной строкой, содержащей имена файлов
        QString sentence = " file2.bin  *.bin file2.bin uuuu fgf.fjuu jhhkk/ bii";
        QStringList result = converter.getUniqueWords(sentence);
        QCOMPARE(result, QStringList() << "*.bin");
    }

    {
        // Проверка работы функции с входной строкой, содержащей имена файлов
        QString sentence = "file1.txt file2.bin file3.txt file4.bin *.txt file1.txt file2.bin uuuu fgf.fjuu jhhkk/ bii";
        QStringList result = converter.getUniqueWords(sentence);
        QCOMPARE(result, QStringList() << "*.txt" << "file2.bin" << "file4.bin");
    }

    {
        // Проверка работы функции с входной строкой, содержащей имена файлов
        QString sentence = "file1.txt file2.bin file3.txt *.bin  file1.txt file2.bin uuuu fgf.fjuu jhhkk/ bii";
        QStringList result = converter.getUniqueWords(sentence);
        QCOMPARE(result, QStringList() << "*.bin" << "file1.txt" << "file3.txt");
    }

    {
        // Проверка работы функции с входной строкой, содержащей имена файлов
        QString sentence = "file1.txt file2.bin file3.txt file1.txt file2.bin uuuu fgf.fjuu jhhkk/ bii";
        QStringList result = converter.getUniqueWords(sentence);
        QCOMPARE(result, QStringList() << "file1.txt" << "file2.bin" << "file3.txt" );
    }

    {
        // Проверка работы функции с входной строкой, не содержащей имен файлов
        QString sentence = "Это сообщение должно удалиться ";
        QStringList result = converter.getUniqueWords(sentence);
        QVERIFY(result.isEmpty());
    }

    {
        // Проверка работы функции с пустой входной строкой
        QString sentence = "";
        QStringList result = converter.getUniqueWords(sentence);
        QVERIFY(result.isEmpty());
    }

}


DECLARE_TEST(tst_TextConverter)
#include "tst_textconverter.moc"
