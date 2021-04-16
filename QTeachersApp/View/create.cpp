#include "create.h"
#include "ui_create.h"

namespace HubertiusNamespace
{
    Create::Create(QWidget *parent, QSqlDatabase * database):
        myTeachersDatabase(database),
        QWidget(parent),
        ui(new Ui::Create)
    {
        ui->setupUi(this);

    }

    Create::~Create()
    {
        delete ui;
    }

    void Create::on_pushButton_clicked()
    {
        QString name, surname, sex, pesel, dateOfBirth, title, listOfSubjects;
        name = ui->lineEdit_name->text();
        surname = ui->lineEdit_surname->text();
        sex = ui->lineEdit_sex->text();
        pesel = ui->lineEdit_pesel->text();
        dateOfBirth = ui->lineEdit_dateOfBirth->text();
        title = ui->lineEdit_title->text();
        listOfSubjects = ui->lineEdit_listOfSubjects->text();
        if((*myTeachersDatabase).isOpen())
        {
            qInfo("I'm in creation mode right now!");
            QSqlQuery query("INSERT INTO Teachers (Name, Surname, Sex, PESEL, Title, DateOfBirth, ListOfSubjects) VALUES ('"+name+"', '"+surname+"', '"+sex+"', '"+pesel+"', '"+dateOfBirth+"', '"+title+"', '"+listOfSubjects+"')");
            query.exec();
        }
    }

}


