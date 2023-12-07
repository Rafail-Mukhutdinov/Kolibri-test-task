
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // Проверка работы XOR
    //QString filePath = "test.txt";
    //w.modifyFile(filePath);

    return a.exec();
}


