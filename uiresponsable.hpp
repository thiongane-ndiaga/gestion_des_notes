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
    explicit UIResponsable(QWidget *parent = nullptr);
    ~UIResponsable();

private:
    Ui::UIResponsable *ui;
};

#endif // UIRESPONSABLE_HPP
