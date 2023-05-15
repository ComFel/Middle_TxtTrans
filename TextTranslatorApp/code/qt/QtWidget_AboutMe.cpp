#include "QtWidget_AboutMe.h"
#include <qdialog.h>


QtWidget_AboutMe::QtWidget_AboutMe(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//setText();

	//connect(ui.okButton, SIGNAL(triggered()), this, SLOT(exitWindow()));
}

QtWidget_AboutMe::~QtWidget_AboutMe()
{}

/*
QtWidget_AboutMe::QtWidget_AboutMe() 
{
	setText();

	QDialog* subAbout = new QDialog;
	subAbout->setWindowTitle("AboutMe");
	QPushButton* button = new QPushButton("Push to open new dialog", this);

	connect(button, SIGNAL(clicked()), subAbout, SLOT(show()));
}*/