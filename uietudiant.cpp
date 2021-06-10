#include "uietudiant.hpp"
#include "ui_uietudiant.h"

UIEtudiant::UIEtudiant(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIEtudiant)
{
    ui->setupUi(this);
}

UIEtudiant::UIEtudiant(QObject *controller)
    : ui(new Ui::UIEtudiant)
{
    ui->setupUi(this);
}

UIEtudiant::~UIEtudiant()
{
    delete ui;
}
