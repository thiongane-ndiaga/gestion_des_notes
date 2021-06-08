#include "uiresponsable.hpp"
#include "ui_uiresponsable.h"

UIResponsable::UIResponsable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIResponsable)
{
    ui->setupUi(this);
}

UIResponsable::~UIResponsable()
{
    delete ui;
}
