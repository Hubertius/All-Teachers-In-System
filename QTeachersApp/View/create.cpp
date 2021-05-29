#include "create.h"
#include "ui_create.h"
#include <QMessageBox>

namespace HubertiusNamespace
{
    Create::Create(QWidget* parent, QSqlDatabase*  database):
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
        Teacher teacher;
        fillTeacherToCreate(teacher);
        if((*myTeachersDatabase).isOpen())
        {
            qInfo("I'm in creation mode right now!");
            if(!isTeacherInDatabase(teacher))
            {
                if(dataValidation(teacher))
                {
                    createIntoDatabase(teacher);
                    qDebug() << "Your created teacher was ADDED into the database!";
                }
                else
                {
                    qDebug() << "Adding your new \"teacher\" can't be completed!";
                }
            }
        }
        clearingLineEdits();
    }

    void Create::fillTeacherToCreate(Teacher& teacher)
    {
        teacher.name = ui->lineEdit_name->text();
        teacher.surname = ui->lineEdit_surname->text();
        teacher.sex = ui->lineEdit_sex->text();
        teacher.pesel = ui->lineEdit_pesel->text();
        teacher.dateOfBirth = ui->lineEdit_dateOfBirth->text();
        teacher.title = ui->lineEdit_title->text();
        teacher.listOfSubjects = ui->lineEdit_listOfSubjects->text();
    }

    bool Create::isTeacherInDatabase(const Teacher& teacher)
    {
        QSqlQuery querySelect;
        querySelect.prepare("SELECT * FROM Teachers");
        querySelect.exec();
        while(querySelect.next())
        {
               if(teacher.name == querySelect.value(1).toString() 
                  && teacher.surname == querySelect.value(2).toString()
                  && teacher.sex == querySelect.value(3).toString()
                  && teacher.pesel == querySelect.value(4).toString()
                  && teacher.dateOfBirth == querySelect.value(5).toString()
                  && teacher.title == querySelect.value(6).toString()
                  && teacher.listOfSubjects == querySelect.value(7).toString())
                {
                    return true;
                }
        }
        return false;
    }

    void Create::createIntoDatabase(const Teacher& teacher)
    {
        QSqlQuery queryCreate;
        queryCreate.prepare("INSERT INTO Teachers (Name, Surname, Sex, PESEL, DateOfBirth, Title, ListOfSubjects) VALUES (?, ?, ?, ?, ?, ?, ?)");
        queryCreate.addBindValue(teacher.name);
        queryCreate.addBindValue(teacher.surname);
        queryCreate.addBindValue(teacher.sex);
        queryCreate.addBindValue(teacher.pesel);
        queryCreate.addBindValue(teacher.dateOfBirth);
        queryCreate.addBindValue(teacher.title);
        queryCreate.addBindValue(teacher.listOfSubjects);
        if(queryCreate.exec())
        {
            qInfo() << "Everything is working and you querry was added to your teachers database. :)";
            QMessageBox::critical(this,tr("Create"), tr("Created"));
        }
        else
        {
            qDebug() << "Something went terribly wrong.";
            QMessageBox::critical(this,tr("ERROR WITH QUERY!"), queryCreate.lastError().text());
        }
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


