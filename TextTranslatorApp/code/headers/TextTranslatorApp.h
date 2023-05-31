// Codigo por:
// Felipe Vallejo Molina
// felipevm07@gmail.com
// 2022.6
// Proyecto: Editor de textos
#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TextTranslatorApp.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <qlistwidget.h>
#include <cstdlib>
#include "ui_QtWidget_AboutMe.h"
#include "..\qt\QtWidget_AboutMe.h"

class TextTranslatorApp : public QMainWindow
{
    Q_OBJECT

public:
    TextTranslatorApp(QWidget *parent = nullptr);
    ~TextTranslatorApp();

private:    
    std::unique_ptr < QtWidget_AboutMe> AboutMe;

public slots:

    void openFile()
    {
        // Ruta del archivo que el usuario quiere abrir
        QString filePath = QFileDialog::getOpenFileName(this, "Choose Open File", "/home", "Text files(*.txt)");
        if (filePath.isEmpty())
            return;
        else
            ui.LabelStatus->setText(filePath + " :File Open Succesfully");

        // Referencia al archivo cargado de la ruta
        QFile fileLoaded(filePath);
        if (!fileLoaded.open(QIODevice::ReadWrite | QIODevice::Text))
            return;

        // Comprobamos por lineas de texto el archivo
        QTextStream in(&fileLoaded);
        QString fileContent;

        fileContent = in.readAll();

        fileLoaded.close();

        // Mostramos el texto cargado del archivo
        ui.textDisplay->clear();
        ui.textDisplay->setPlainText(fileContent);
        ui.LabelStatus->setText(filePath + " :File Open Succesfully");
    }

    void saveFile()
    {
        // Guardamos la ruta del archivo
        QString filePath = QFileDialog::getSaveFileName(this, "Save File As", "/home", "Text files(*.txt)");
        if (filePath.isEmpty())
            return;

        // Referencia a ese archivo
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream out(&file);

        out << ui.textEdit->toPlainText() << "\n";
        file.close();

        ui.LabelStatus->setText(filePath);

    }

    void selectedLenguageClicked()
    {
        // ToDo: Connect to DLL

        QString selectedvalue = ui.ListLenguagesWidget->currentItem()->text();

        if (selectedvalue == "ES")
        {
            ui.LabelLenguageSelection->setText("Spanish was selected");
        }
        else if (selectedvalue == "EN")
        {
            ui.LabelLenguageSelection->setText("English was selected");
        }

    }

    // Toolbar actions
    void copyAction()
    {
        ui.textDisplay->copy();
    }

    void pasteAction()
    {
        ui.textDisplay->paste();
    }

    void cutAction()
    {
        ui.textDisplay->cut();
    }

    void exitAPP()
    {
        QApplication::quit();
    }

    void createAboutWindow()
    {        
        //QDialog secDialog;
        //
        //secDialog.setModal(true);
        //secDialog.exec();

        AboutMe = std::make_unique < QtWidget_AboutMe >(this);

        AboutMe->setModal(true);
    }
private:
    Ui::TextTranslatorAppClass ui;
    //Ui_QtWidget_AboutMeClass *aboutmeDialog;
};
