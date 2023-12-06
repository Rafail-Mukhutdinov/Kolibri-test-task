#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::modifyFile(const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open file for reading");
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    operationValue = 0x12345678; // Значение для теста XOR

    for (int i = 0; i < data.size(); i++) {
        data[i] = data[i] ^ static_cast<char>(operationValue >> (i % 8 * 8));
    }

    if (!file.open(QIODevice::WriteOnly)) {
        qWarning("Cannot open file for writing");
        return;
    }

    QDataStream out(&file);
    out.writeRawData(data.data(), data.size());
    file.close();
}
