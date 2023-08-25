#ifndef LOGIN_DIALOG_H
#define LOGIN_DIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private:
    bool onLogin(const QString& name, const QString& pwd);

    void initPage();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGIN_DIALOG_H
