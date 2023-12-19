#include <QtTest>

#include "autotest.h"
#include "../kolibri/directorymanager.h"

class tst_DirectoryManager: public QObject
{
    Q_OBJECT

public:


private slots:
    void isDirectoryValid_data();
    void isDirectoryValid();


};
//------------------------------------------------------------------------------------------------
void tst_DirectoryManager::isDirectoryValid_data()
{
    // Добавляем две колонки в таблицу данных теста: "dir" и "expectedResult"
    QTest::addColumn<QString>("dir");
    QTest::addColumn<bool>("expectedResult");

    // Добавляем три строки в таблицу данных теста
    QTest::newRow("Existing Directory") << QDir::homePath() << true; // Существующая директория
    QTest::newRow("Non-Existing Directory") << "/path/to/non/existing/directory" << false; // Несуществующая директория
    QTest::newRow("Empty String") << "" << false; // Пустая строка
}

void tst_DirectoryManager::isDirectoryValid()
{
    // Извлекаем данные из текущего тестового случая
    QFETCH(QString, dir);
    QFETCH(bool, expectedResult);

    // Создаем объект DirectoryManager и проверяем, является ли директория действительной
    DirectoryManager manager;
    QCOMPARE(manager.isDirectoryValid(dir), expectedResult);
}




//------------------------------------------------------------------------------------------------

DECLARE_TEST(tst_DirectoryManager)
#include "tst_directorymanager.moc"
