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
    /*!
     * \brief This class is responsible for first operation after running the app (login process).
     */
    class LoginWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        /*!
         * \brief Constructor (only) of LoginWindow class.
         * \param nullptr (no parent basically)
         *
         * Constructor is basically responsible for connection with login.sqlite database.\n
         * No more important operations worth it of mentioning them.
         *
         */
        LoginWindow(QWidget* parent = nullptr);
        /*!
         * \brief Destructor of LoginWindow class
         *
         * It's main purpose is to execute friend function from utils files, which\n
         * is responsible for closing connection with login.sqlite database.
         */
        ~LoginWindow();

    private slots:
        void on_btnLogin_clicked();

    private:
        QString path;
        QSqlDatabase myDatabase;
        Ui::LoginWindow* ui;

    public:
        friend void connClose(QSqlDatabase* myDatabase); /*!< friend function from utils files. It serves for closing of login.sqlite database  */
        friend bool connOpen(QSqlDatabase* myDatabase, const QString & PATH); /*!< friend function from utils files. It serves for opening of login.sqlite database */
    };
}
#endif // LOGINWINDOW_H
