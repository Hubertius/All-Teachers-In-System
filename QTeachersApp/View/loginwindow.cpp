#include "loginwindow.h"
#include "ui_loginwindow.h"

namespace HubertiusNamespace
{
    LoginWindow::LoginWindow(QWidget *parent):
        QMainWindow(parent),
        ui(new Ui::LoginWindow)
    {
        ui->setupUi(this);
        myDatabase = QSqlDatabase::addDatabase("QSQLITE");
        connOpen(&myDatabase, PATH);
    }

    LoginWindow::~LoginWindow()
    {
        delete ui;
    }


    void LoginWindow::on_btnLogin_clicked()
    {

        QString Username, Password;
        Username = ui->lineEditUsername->text();
        Password = ui->lineEditPassword->text();

        if(myDatabase.isOpen())
        {
            QSqlQuery query("SELECT * FROM Login WHERE Username = '"+Username+"' AND Password = '"+Password+"'");
            if(!query.next())
            {
               qDebug() << "Something went terribly wrong!";
               ui->label_ConnStat->setText("Something went wrong when searching for your login data\n in system. :(");
               qInfo() << "Querry error: " << query.lastError().text();
               ui->lineEditUsername->setText("");
               ui->lineEditPassword->setText("");
            }
            else if(!query.first()) //
            {
                ui->label_ConnStat->setText("Incorrect username or pasword!");
            }
            else
            {
                ui->label_ConnStat->setText("Username and password are correct.\nYou're now connected to our app. :)");
                connClose(&myDatabase);
                this->hide();
                MainView mainView;
                mainView.setModal(true);
                mainView.exec();

            }
            //qInfo() << "hello there!";
        }
    }

    /*bool LoginWindow::connOpen()
    {
        myDatabase = QSqlDatabase::addDatabase("QSQLITE");
        myDatabase.setDatabaseName("/home/hubertius/All-Teachers-In-System/QTeachersApp/DataBases/login.sqlite");
        if(myDatabase.open())
        {
            qDebug() << "Connected to database.";
            return true;
        }
        else
        {
            qDebug() << "Failed to open the database!";
        }
        return false;
    }

    void LoginWindow::connClose()
    {
        myDatabase.close();
        myDatabase.removeDatabase(QSqlDatabase::defaultConnection);
    }*/

}
