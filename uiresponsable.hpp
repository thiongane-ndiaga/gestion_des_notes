#ifndef UIRESPONSABLE_HPP
#define UIRESPONSABLE_HPP

#include <QMainWindow>

namespace Ui {
class UIResponsable;
}

class UIResponsable : public QMainWindow
{
    Q_OBJECT

public:
    UIResponsable(QWidget *parent = nullptr);
    UIResponsable(QObject *controller);
    ~UIResponsable();

private:
    Ui::UIResponsable *ui;
};

#endif // UIRESPONSABLE_HPP
