#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создаем новый валидатор с регулярным выражением "[0-9A-F]{0,16}"
    // Затем устанавливаем этот валидатор для lineEdit_mask_xor
    ui->lineEdit_mask_xor->setValidator(textControler.createHexValidator("[0-9A-F]{0,16}"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_mask_file_textChanged(const QString &arg1)
{
    param.inputMaskFile = arg1;
    qDebug() << "Вводим значение маски файлов:" << param.inputMaskFile ;
}

void MainWindow::on_checkBox_delete_file_clicked(bool checked)
{
    param.deleteInputFiles = checked;
    qDebug() << "Чекбокс на удаление файла:" << param.deleteInputFiles;
}

void MainWindow::on_checkBox_search_folders_clicked(bool checked)
{
    param.searchAttachedFiles = checked;
    qDebug() << "Чекбокс на поиск вложенных папок:" << param.searchAttachedFiles;
}

void MainWindow::on_lineEdit_dir_open_textChanged(const QString &arg1)
{
    param.inputDirStart = arg1;
    qDebug() << "Вводим значение директории входных файлов:" << param.inputDirStart ;
}

void MainWindow::on_lineEdit_mask_xor_textChanged(const QString &arg1)
{
    param.inputMaskXor =  arg1;
    qDebug() << "Вводим значение маски XOR из lineEdit_mask_xor:" << param.inputMaskXor ;
}

void MainWindow::on_pushButton_dir_open_clicked()
{
    param.inputDirStart = QFileDialog::getExistingDirectory();
    ui->lineEdit_dir_open->setText(param.inputDirStart);
    qDebug() << "Нажата кнопка Открыть и выбрана директория:" << param.inputDirStart;
}


void MainWindow::on_radioButton_overwriting_toggled(bool checked)
{
    param.radioModifyOverride = checked;
    qDebug() << "Переключение RadioButton Перезаписать файл true, Модифицировать файл false:" << param.radioModifyOverride;
}


void MainWindow::on_radioButton_one_start_toggled(bool checked)
{
    param.radioOnelaunchTimer = checked;
    ui->timeEdit->setDisabled(checked);                     //
    qDebug() << "Переключение RadioButton Разовый запуск true, Работа по таймеру false:" << param.radioOnelaunchTimer;
}


void MainWindow::on_timeEdit_timeChanged(const QTime &time)
{
    param.timerInterval = time.msecsSinceStartOfDay();
    qDebug() << "Выставление таймера:" << param.timerInterval;
}


void MainWindow::on_pushButton_dir_save_clicked()
{
    param.outputDirFinish = QFileDialog::getExistingDirectory();
    ui->lineEdit_dir_save->setText(param.outputDirFinish);
    qDebug() << "Нажата кнопка Сохранить в директории:" << param.outputDirFinish;
}


void MainWindow::on_pushButton_start_clicked()
{

    // Проверяем наши LineEdit На корректные данные
    if(!controler.checkLineEditNotEmpty(ui, param)){
        return;
    }
    ui->label_Text_info->setText("Обработка.");
    //Обрабатываем наше кодирование и декодирование и так же обработка таймера
    controler.handleEncryptionEvent(timer, param);

   // ui->label_Text_info->setText("Готово.");
    return;

}

void MainWindow::on_pushButton_stop_clicked()
{
    ui->label_Text_info->setText("Стоп.");
    timer.stop();
    qDebug() << "Работа по таймеру отключена";
}


void MainWindow::on_lineEdit_dir_save_textChanged(const QString &arg1)
{
    param.outputDirFinish = arg1;
    qDebug() << "Вводим значение директории выходных файлов:" << param.inputDirStart ;
}

