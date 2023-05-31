// Codigo por:
// Felipe Vallejo Molina
// felipevm07@gmail.com
// 2023.6
// Proyecto: Editor de textos

#include "..\headers\TextTranslatorApp.h"
#include <QtWidgets/QApplication>


int main(int number_arguments, char* arguments[])
{
    QApplication application(number_arguments, arguments);
    TextTranslatorApp myWindow;

    myWindow.show();


    return application.exec();
}