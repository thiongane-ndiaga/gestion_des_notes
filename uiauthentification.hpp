#ifndef UIAUTHENTIFICATION_H
#define UIAUTHENTIFICATION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class UIAuthentification; }
QT_END_NAMESPACE

class UIAuthentification : public QMainWindow
{
    Q_OBJECT

public:
    UIAuthentification(QWidget *parent = nullptr);
    UIAuthentification(QObject *controller = nullptr);

    bool getInputs (QString &login, QString &password);
    void notificationError (QString message);
    void notificationInformation (QString message);

    ~UIAuthentification();

private:
    Ui::UIAuthentification *ui;
};
#endif // UIAUTHENTIFICATION_H
