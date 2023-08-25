#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include<QMessageBox>

namespace Ui {
class SignUp;
}

class SignUp : public QWidget
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

    void paintEvent(QPaintEvent *);
private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_register_clicked();
    void handleMessageBoxFinished(int result);
     void showMessageBox();

private:
    Ui::SignUp *ui;
     QMessageBox* messageBox;
signals:
    void signalToMain();
    void signalTologin();
};

#endif // SIGNUP_H
