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

    // Попытка открыть файл для чтения и записи
    if (!file.open(QIODevice::ReadWrite)) {
        QMessageBox::warning(0, "Ошибка", "Файл уже открыт и заблокирован в другом приложении");
        return;
    }

    QByteArray data = file.readAll();
    file.close(); // Закрываем файл после чтения

    operationValue = 0x12345678; // Значение для теста XOR
    QString text;

    for (int i = 0; i < data.size(); i++)
    {
        data[i] = data[i] ^ static_cast<char>(operationValue >> (i % 8 * 8)); // Применяем XOR к каждому байту
        text += data[i];
    }
    qDebug() << text;

    // Переоткрываем файл для записи
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(0, "Ошибка", "Не удалось открыть файл для записи");
        return;
    }

    QDataStream out(&file);
    out.writeRawData(data.data(), data.size());
    file.close(); // Закрываем файл после записи
}


void MainWindow::on_selectFileButton_clicked()
{
    QString savePath = getOpenFile(".txt");
    if (!savePath.isEmpty())
    {
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

    if (filePath.isEmpty())
    {
        // Пользователь нажал "Отмена" или закрыл диалоговое окно
        throw std::runtime_error(tr("No file selected").toStdString());
    }
    return filePath;
}
/*
void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(ui->checkBox->isChecked())
    {
        qDebug() << "Ok";
    }else
    {
        qDebug() << "No";
    }
}

*/


