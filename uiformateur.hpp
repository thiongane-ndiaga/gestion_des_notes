#ifndef UIFORMATEUR_HPP
#define UIFORMATEUR_HPP

#include <QMainWindow>

namespace Ui {
class UIFormateur;
}

class UIFormateur : public QMainWindow
{
    Q_OBJECT

public:
     UIFormateur(QWidget *parent = nullptr);
     UIFormateur(QObject *controller);
    ~UIFormateur();

private:
    Ui::UIFormateur *ui;
};

#endif // UIFORMATEUR_HPP
