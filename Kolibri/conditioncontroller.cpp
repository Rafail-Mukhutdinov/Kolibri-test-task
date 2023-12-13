#include "conditioncontroller.h"


ConditionController::ConditionController()
{

}

bool ConditionController::checkLineEditNotEmpty (Ui::MainWindow *cui, const ParamFormMain &paramLineEdit)
{
    bool check = true;
    bool checkDirStart = this->isDirectoryValid(paramLineEdit.inputDirStart);
    bool checkDirFinish = this->isDirectoryValid(paramLineEdit.outputDirFinish);

    QString text_info = "";

    if(paramLineEdit.inputMaskFile.trimmed().isEmpty())
    {
        text_info += "Введите маску файла.\n";
        check = false;
    }


    if(!checkDirStart)
    {
        text_info += "Выбирите корректную входную директорию.\n";
        check = false;
    }


    if(paramLineEdit.inputMaskXor.trimmed().isEmpty())
    {
        text_info += "Введите XOR.\n";
        check = false;
    }

    qDebug() << "пустота " << paramLineEdit.outputDirFinish.trimmed().isEmpty() << "корректность" << checkDirFinish;
    if(!checkDirFinish)
    {
        text_info += "Выбирите корректную выходную директорию.\n";
        check = false;
    }

    if(!paramLineEdit.inputDirStart.trimmed().isEmpty() && !paramLineEdit.outputDirFinish.trimmed().isEmpty())
    {
        if(paramLineEdit.inputDirStart == paramLineEdit.outputDirFinish)
        {
           text_info += "Входная и выходная директория не должны совпадать.\n";
           check = false;
        }
    }

    if(!check)
    {
        cui->label_Text_info->setText(text_info);
    }

    return check;
}

bool ConditionController::isDirectoryValid(const QString &paramDir)
{
    if(paramDir.trimmed().isEmpty())
    {
        return false;
    }
    QDir dir(paramDir);
    return dir.exists();
}
