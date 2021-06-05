#ifndef UIETUDIANT_HPP
#define UIETUDIANT_HPP

#include <QMainWindow>

namespace Ui {
class UIEtudiant;
}

class UIEtudiant : public QMainWindow
{
    Q_OBJECT

public:
    explicit UIEtudiant(QWidget *parent = nullptr);
    ~UIEtudiant();

private:
    Ui::UIEtudiant *ui;
};

#endif // UIETUDIANT_HPP
