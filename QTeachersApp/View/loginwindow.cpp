#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QCryptographicHash>

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

        QString Username;
        QByteArray Password;
        Username = ui->lineEditUsername->text();
        Password =  ui->lineEditPassword->text().toLatin1();

        if(myDatabase.isOpen())
        {
            QByteArray hashedUserInput = QCryptographicHash::hash(Password, static_cast<QCryptographicHash::Algorithm>(10));
            QString hashedPasswordToQString = QLatin1String(hashedUserInput.toHex());

            QSqlQuery query;
            query.prepare("SELECT * FROM Login");
            query.exec();
            while(query.next())
            {
                if(Username == query.value(1).toString() && hashedPasswordToQString == query.value(2).toString())
                {
                    ui->label_ConnStat->setText("Username and password are correct.\nYou're now connected to our app. :)");
                    connClose(&myDatabase);
                    this->hide();
                    MainView mainView;
                    mainView.setModal(true);
                    mainView.exec();
                    return;
                }
            }
            ui->label_ConnStat->setText("Something went wrong when searching for your login data\n in system. :(");
            qInfo() << "Querry error: " << query.lastError().text();
            ui->lineEditUsername->setText("");
            ui->lineEditPassword->setText("");
        }
    }



}
