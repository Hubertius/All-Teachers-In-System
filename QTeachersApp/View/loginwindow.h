#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow> 
#include <QtSql> // for creation (or connection) to SQLite database
#include <QtDebug>
#include <QFileInfo>


QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

namespace HubertiusNamespace
{

    class LoginWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        LoginWindow(QWidget *parent = nullptr);
        ~LoginWindow();

    private slots:
        void on_btnLogin_clicked();

    private:
        Ui::LoginWindow *ui;
        QSqlDatabase myDatabase;
    };
}
#endif // LOGINWINDOW_H
