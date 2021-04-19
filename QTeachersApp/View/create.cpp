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
            if( !dataValidation(name, surname, sex, pesel, dateOfBirth, title, listOfSubjects) )
            {
                clearingLineEdits();
                return;
            }
            QSqlQuery query;
            query.prepare("INSERT INTO Teachers (Name, Surname, Sex, PESEL, DateOfBirth, Title, ListOfSubjects) VALUES ('"+name+"', '"+surname+"', '"+sex+"', '"+pesel+"', '"+dateOfBirth+"', '"+title+"', '"+listOfSubjects+"')");
            if(query.exec())
            {
                qInfo() << "Everything is working and you querry was added to your teachers database. :)";
            }
            else
            {
                qDebug() << "Something went terribly wrong.";
            }

         }
       clearingLineEdits();
     }

     void Create::clearingLineEdits()
     {
         ui->lineEdit_name->setText("");
         ui->lineEdit_surname->setText("");
         ui->lineEdit_sex->setText("");
         ui->lineEdit_pesel->setText("");
         ui->lineEdit_dateOfBirth->setText("");
         ui->lineEdit_title->setText("");
         ui->lineEdit_listOfSubjects->setText("");
     }

}


