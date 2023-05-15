#pragma once

#include <QDialog>
#include "ui_QtWidget_AboutMe.h"

class QtWidget_AboutMe : public QDialog
{
	Q_OBJECT

public:
	QtWidget_AboutMe(QWidget *parent = nullptr);
	QtWidget_AboutMe();

	~QtWidget_AboutMe();

public slots:

	void exitWindow()
	{
		ui.okButton->close();
	}

	void setText() 
	{
		ui.textBrowser->setText("Made by ComFel (Felipe Vallejo Molina) on 06.2022, for any advice or problems, contact by felipe07@gmail.com");
	}

private:
	Ui::QtWidget_AboutMeClass ui;
};
