#include "conditioncontroller.h"


ConditionController::ConditionController()
{

}

// Метод проверяет, что поля ввода не пусты и содержат корректные значения
bool ConditionController::checkLineEditNotEmpty (Ui::MainWindow *cui, ParamFormMain &paramForm)
{
    qDebug() << "Настройка виджетов";
    // Инициализируем переменную для проверки корректности ввода
    bool check = true;
    // Инициализируем переменную для хранения информационных сообщений
    QString text_info;

    const int KEY_LENGTH = 16;

    // Получаем уникальные слова из строки inputMaskFile
    this->arrayOfFileTypesMask = textCont.getUniqueWords(paramForm.inputMaskFile);
    // Преобразуем список уникальных слов в строку и устанавливаем эту строку в поле ввода lineEdit_mask_file
    QString textMaskInfo = arrayOfFileTypesMask.join(" ");
    cui->lineEdit_mask_file->setText(textMaskInfo);

    // Удаляем пробелы в начале и конце каждого поля ввода
    QString trimmedInputMaskFile = paramForm.inputMaskFile.trimmed();
    QString trimmedInputDirStart = paramForm.inputDirStart.trimmed();
    QString trimmedOutputDirFinish = paramForm.outputDirFinish.trimmed();
    QString trimmedInputMaskXor = paramForm.inputMaskXor.trimmed();

    // Проверяем, что поле ввода inputMaskFile не пусто и содержит корректные значения
    if(trimmedInputMaskFile.isEmpty() || arrayOfFileTypesMask.empty())
    {
        text_info += "Введите корректную маску файла.\n";
        check = false;
    }

    // Проверяем, что поле ввода inputDirStart содержит корректный путь к директории
    if(!dirManager.isDirectoryValid(trimmedInputDirStart))
    {
        text_info += "Выбирите корректную входную директорию.\n";
        check = false;
    }

    // Проверяем, что поле ввода inputMaskXor не пусто
    if(trimmedInputMaskXor.isEmpty())
    {
        text_info += "Введите XOR.\n";
        check = false;
    }else
    {
        // если ключ меньше 16 символов, то заполняем слева нулями
        if(paramForm.inputMaskXor.length() < KEY_LENGTH){
            paramForm.inputMaskXor = paramForm.inputMaskXor.rightJustified(KEY_LENGTH, '0');
        }
        cui->lineEdit_mask_xor->setText(paramForm.inputMaskXor);
    }

    // Проверяем, что поле ввода outputDirFinish содержит корректный путь к директории
    if(!dirManager.isDirectoryValid(trimmedOutputDirFinish))
    {
        text_info += "Выбирите корректную выходную директорию.\n";
        check = false;
    }

    // Проверяем, что входная и выходная директории не совпадают
    if( !trimmedInputDirStart.isEmpty() &&
        !trimmedOutputDirFinish.isEmpty() &&
        trimmedInputDirStart == trimmedOutputDirFinish)
    {
        text_info += "Входная и выходная директория не должны совпадать.\n";
        check = false;
    }

    // Если выбрано по таймеру и таймер значение ноль
    if(paramForm.radioOnelaunchTimer == false && paramForm.timerInterval == 0)
    {
        text_info += "Таймер не может быть ноль.\n";
        check = false;
    }

    // Если были найдены ошибки ввода, выводим информационные сообщения
    if(!check)
    {
        cui->label_Text_info->setText(text_info);
    }
    qDebug() << "Конец Настройка виджетов";
    // Возвращаем результат проверки
    return check;
}

void ConditionController::toggleWidget(Ui::MainWindow *cui, bool toggle)
{
    cui->lineEdit_mask_file->setDisabled(toggle);
    cui->lineEdit_dir_open->setDisabled(toggle);
    cui->pushButton_dir_open->setDisabled(toggle);
    cui->lineEdit_mask_xor->setDisabled(toggle);
    cui->lineEdit_dir_save->setDisabled(toggle);
    cui->pushButton_dir_save->setDisabled(toggle);
    cui->pushButton_start->setDisabled(toggle);
    cui->pushButton_stop->setDisabled(!toggle);
    cui->radioButton_one_start->setDisabled(toggle);
    cui->radioButton_timer_start->setDisabled(toggle);
    cui->timeEdit->setDisabled(!toggle);

}

void ConditionController::handleEncryptionEvent(QTimer &timer, const ParamFormMain &paramForm)
{

    // Если обработка по таймеру
    if(paramForm.radioOnelaunchTimer == false)
    {
        // Подключаем сигнал таймера к слоту нашего объекта с параметрами через лямду
        QObject::connect(&timer, &QTimer::timeout, this, [&] {
            this->controlTimer(paramForm);
        });
        // Выставляем время таймера
        timer.start(paramForm.timerInterval);
    }else
    {
        // Разовый поиск
        this->convertFilesToEncodedFormat(paramForm.inputDirStart, paramForm, arrayOfFileTypesMask);
        // Поиск по волженных папках
        if(paramForm.searchAttachedFiles == true)
        {
            qDebug() << "Поиск по вложенным папкам по таймеру";
            QDirIterator subfoldIter(paramForm.inputDirStart, (QDir::Dirs | QDir::NoDotAndDotDot), QDirIterator::Subdirectories);
            while (subfoldIter.hasNext())
            {
                if(paramForm.bottonClickStop){
                    break;
                }
                this->convertFilesToEncodedFormat(subfoldIter.next(), paramForm, arrayOfFileTypesMask);
            }
        }else
        {
            qDebug() << "Поиск в текущей папке";
        }
        qDebug() << "Обработка Без таймера";
    }
}

void ConditionController::controlTimer(const ParamFormMain &paramForm){
    qDebug() << "Обработка по таймеру";

    // Разовый поиск
    this->convertFilesToEncodedFormat(paramForm.inputDirStart, paramForm, arrayOfFileTypesMask);
    // Поиск по вложенным папкам
    if(paramForm.searchAttachedFiles == true)
    {
        QDirIterator subfoldIter(paramForm.inputDirStart, (QDir::Dirs | QDir::NoDotAndDotDot), QDirIterator::Subdirectories);
        while (subfoldIter.hasNext()) {
            //Если нажата кнопка стоп
            if(paramForm.bottonClickStop)
            {
                break;
            }
            this->convertFilesToEncodedFormat(subfoldIter.next(), paramForm, arrayOfFileTypesMask);
        }
    }
}

void ConditionController::convertFilesToEncodedFormat(QString inputDir, const ParamFormMain &paramForm, const QStringList dirMask)
{
    QDirIterator dirIter(inputDir, dirMask, QDir::Files);
    //проход по всем файлам
    while(dirIter.hasNext())
    {
        //Если нажата кнопка стоп
        if(paramForm.bottonClickStop)
        {
            break;
        }

        dirIter.next();

        QFile inputFile(dirIter.filePath());
        // работаем с файлом только если он открывается в режиме ReadWrite
        if(inputFile.open(QIODevice::ReadWrite))
        {
            QString outFileName = paramForm.outputDirFinish + "/" +dirIter.fileName();
            QFile outputFile(outFileName);

            if(outputFile.exists())
            {
                if(paramForm.radioModifyOverride == false)
                {
                    qDebug() << "Модифицируем файл";
                    dirManager.modifyInputFiles(outputFile, paramForm, dirIter, outFileName);
                }
            }
            outputFile.open(QIODevice::WriteOnly);

            const int BUFFER_SIZE = 1024*1024*5; // 5MB

            QByteArray buffer;
            buffer.reserve(BUFFER_SIZE);
            std::vector<char> bufferChar(BUFFER_SIZE);

            while (!inputFile.atEnd())
            {
                //Если нажата кнопка стоп
                if(paramForm.bottonClickStop)
                {
                    break;
                }
                int nBlockSize = inputFile.read(bufferChar.data(), bufferChar.size());
                QByteArray outputArray = hex.processXOR(QByteArray::fromRawData(bufferChar.data(), nBlockSize), paramForm.inputMaskXor);
                buffer.append(outputArray);
            }
            outputFile.write(buffer);

            // если нужно удаляем входной файл
            if(paramForm.deleteInputFiles == true){
                inputFile.remove();
            }
            inputFile.close();
            outputFile.close();
        } else{

        }
    }
}
