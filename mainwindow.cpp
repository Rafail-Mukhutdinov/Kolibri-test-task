#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_selectFileButton_clicked);
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
    QString text;

    for (int i = 0; i < data.size(); i++) {
        data[i] = data[i] ^ static_cast<char>(operationValue >> (i % 8 * 8)); // Применяем XOR к каждому байту
        text += data[i];
    }
    qDebug() << text;

    if (!file.open(QIODevice::WriteOnly)) {
        qWarning("Cannot open file for writing");
        return;
    }

    QDataStream out(&file);
    out.writeRawData(data.data(), data.size());
    file.close();
}

void MainWindow::on_selectFileButton_clicked()
{
    QString savePath = getOpenFile(".txt");
    if (!savePath.isEmpty()) {
        ui->lineEdit->setText(savePath);
    } else {
        // Обработка ситуации, когда пользователь нажимает "Отмена" или закрывает диалоговое окно
        throw std::runtime_error(tr("No file selected").toStdString());
    }
}

QString MainWindow::getOpenFile(const QString &formatFile)
{
    QString text = tr("Text Files (*%1)").arg(formatFile);
    QString defaultDirectory = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), defaultDirectory, text);

    if (filePath.isEmpty()) {
        // Пользователь нажал "Отмена" или закрыл диалоговое окно
        throw std::runtime_error(tr("No file selected").toStdString());
    }
    return filePath;
}




























