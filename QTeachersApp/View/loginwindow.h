#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow> 
#include "mainview.h"
#include "../utils.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class LoginWindow;
}
QT_END_NAMESPACE

namespace HubertiusNamespace
{
    class LoginWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        LoginWindow(QWidget* parent = nullptr);
        ~LoginWindow();

    private slots:
        void on_btnLogin_clicked();

    private:
        QString path;
        QSqlDatabase myDatabase;
        Ui::LoginWindow* ui;

    public:
        friend void connClose(QSqlDatabase* myDatabase);
        friend bool connOpen(QSqlDatabase* myDatabase, const QString & PATH);
    };
}
#endif // LOGINWINDOW_H
