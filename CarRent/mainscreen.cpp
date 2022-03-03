#include "mainscreen.h"
#include "ui_mainscreen.h"

MainScreen::MainScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScreen)
{
    ui->setupUi(this);
}

MainScreen::~MainScreen()
{
    delete ui;
}
