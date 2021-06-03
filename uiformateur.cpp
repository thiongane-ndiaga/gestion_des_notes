#include "uiformateur.hpp"
#include "ui_uiformateur.h"

UIFormateur::UIFormateur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIFormateur)
{
    ui->setupUi(this);
}

UIFormateur::~UIFormateur()
{
    delete ui;
}
