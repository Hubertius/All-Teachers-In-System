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
        myDatabase.setDatabaseName("../../DataBases/login.db");
        if(myDatabase.open())
        {
            ui->label_ConnStat->setText("Connected...");
        }
        else
        {
            ui->label_ConnStat->setText("Failed to open the data base!");
        }

    }

    LoginWindow::~LoginWindow()
    {
        delete ui;
    }


    void LoginWindow::on_btnLogin_clicked()
    {

    }

}
