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
    explicit UIFormateur(QWidget *parent = nullptr);
    ~UIFormateur();

private:
    Ui::UIFormateur *ui;
};

#endif // UIFORMATEUR_HPP
