// Codigo por:
// Felipe Vallejo Molina
// felipevm07@gmail.com
// 2022.6
// Proyecto: Editor de textos


#include "..\headers\TextTranslatorApp.h"
#include <qdialog.h>



TextTranslatorApp::TextTranslatorApp(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);

    // Barras del Menu File
    connect(ui.actionExit,  SIGNAL(triggered()), this, SLOT(exitAPP()));

    connect(ui.actionOpen,  SIGNAL(triggered()), this, SLOT(openFile()));
    connect(ui.actionSave,  SIGNAL(triggered()), this, SLOT(saveFile()));

    // Barras del Menu Edit
    connect(ui.actionCopy,  SIGNAL(triggered()), this, SLOT(copyAction()));
    connect(ui.actionPaste, SIGNAL(triggered()), this, SLOT(pasteAction()));
    connect(ui.actionCut,   SIGNAL(triggered()), this, SLOT(cutAction()));

    // Intentos de crear window de about
    connect(ui.actionAbout_Me, SIGNAL(triggered()), this, SLOT(createAboutWindow()));

    /*
    Ui_QtWidget_AboutMeClass* aboutMe = new Ui_QtWidget_AboutMeClass;
    aboutMe->setWindowTitle("AboutMe");
    aboutMe->show();
    */


    // Lista de idiomas disponibles
    connect(ui.ListLenguagesWidget, SIGNAL(clicked()), this, SLOT(selectedLenguageClicked()));
}

TextTranslatorApp::~TextTranslatorApp() {}
