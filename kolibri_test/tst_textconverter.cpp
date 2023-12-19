#include <QtTest>


#include "autotest.h"
#include "../kolibri/textconverter.h"

class tst_TextConverter: public QObject
{
    Q_OBJECT

public:


private slots:
    void getUniqueWords();

    void createHexValidator_data();
    void createHexValidator();

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


void tst_TextConverter::createHexValidator_data()
{
    // Добавляем две колонки в таблицу данных теста: "input" и "expectedResult"
    QTest::addColumn<QString>("input");
    QTest::addColumn<bool>("expectedResult");

    // Добавляем три строки в таблицу данных теста
    QTest::newRow("Valid Hex") << "ABCDEF1234567890" << true; // Валидная шестнадцатеричная строка
    QTest::newRow("Invalid Hex") << "XYZ" << false; // Невалидная шестнадцатеричная строка
    QTest::newRow("Empty String") << "" << true; // Пустая строка
}

// Метод, который выполняет тестирование
void tst_TextConverter::createHexValidator()
{
    // Извлекаем данные из текущего тестового случая
    QFETCH(QString, input);
    QFETCH(bool, expectedResult);

    // Создаем объект TextConverter и валидатор с регулярным выражением "[0-9A-F]{0,16}"
    TextConverter converter;
    QValidator* validator = converter.createHexValidator("[0-9A-F]{0,16}");

    // Проверяем, что валидатор корректно проверяет входные данные
    int pos = 0;
    QCOMPARE(validator->validate(input, pos) == QValidator::Acceptable, expectedResult);
}



DECLARE_TEST(tst_TextConverter)
#include "tst_textconverter.moc"
