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
        QDir tempPath = QDir::current();
        tempPath.cdUp();  // to get out from /.../build-QTeachersApp-Desktop-Debug one folder up into /All-Teachers-In-System
        qDebug() << tempPath.path() + "/QTeachersApp/DataBases/login.sqlite";
        connOpen(&myDatabase, tempPath.path() + "/QTeachersApp/DataBases/login.sqlite");
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



}
