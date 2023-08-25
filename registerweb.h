#ifndef REGISTERWEB_H
#define REGISTERWEB_H

#include <QMainWindow>
#include <QtDebug>
#include <QtSql>
#include <QFileInfo>

#include"homepage.h"
QT_BEGIN_NAMESPACE
namespace Ui { class RegisterWeb; }
QT_END_NAMESPACE

class RegisterWeb : public QMainWindow
{
    Q_OBJECT

public:
    RegisterWeb(QWidget *parent = nullptr);
    ~RegisterWeb();
    void paintEvent(QPaintEvent*);
     HomePage* homePage;
private:
    Ui::RegisterWeb *ui;
    void login();

    QSqlDatabase myDB;

};
#endif // REGISTERWEB_H
