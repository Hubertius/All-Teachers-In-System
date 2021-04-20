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
        // Getting data from lineEdits of ui - START OF CODE
        QString name, surname, sex, pesel, dateOfBirth, title, listOfSubjects;
        name = ui->lineEdit_name->text();
        surname = ui->lineEdit_surname->text();
        sex = ui->lineEdit_sex->text();
        pesel = ui->lineEdit_pesel->text();
        dateOfBirth = ui->lineEdit_dateOfBirth->text();
        title = ui->lineEdit_title->text();
        listOfSubjects = ui->lineEdit_listOfSubjects->text();
        // Getting data from lineEdits of ui - END OF CODE
        if((*myTeachersDatabase).isOpen())
        {
            qInfo("I'm in creation mode right now!");
            // Checking if there is the same data in database already - START OF CODE
            QSqlQuery querySelect;
            querySelect.prepare("SELECT * FROM Teachers");
            querySelect.exec();
            bool checkForEqualisation = false; // if the same data (with only diffrence being another "ID") are already in teachers.sqlite database
            while(querySelect.next())
            {
                   if(name == querySelect.value(1).toString()
                      && surname == querySelect.value(2).toString()
                      && sex == querySelect.value(3).toString()
                      && pesel == querySelect.value(4).toString()
                      && dateOfBirth == querySelect.value(5).toString()
                      && title == querySelect.value(6).toString()
                      && listOfSubjects == querySelect.value(7).toString())
                    {
                        checkForEqualisation = true;
                        qDebug() << "Creating your new \"teacher\" will be imposssible, because he already is in our database (only with another id).";
                    }

            }
            if( !dataValidation(name, surname, sex, pesel, dateOfBirth, title, listOfSubjects) || checkForEqualisation)
            {

                clearingLineEdits();
                return;
            }
            // Checking if there is the same data in database already - END OF CODE
            // Creation of new teacher - START OF CODE
            QSqlQuery queryCreate;
            queryCreate.prepare("INSERT INTO Teachers (Name, Surname, Sex, PESEL, DateOfBirth, Title, ListOfSubjects) VALUES ('"+name+"', '"+surname+"', '"+sex+"', '"+pesel+"', '"+dateOfBirth+"', '"+title+"', '"+listOfSubjects+"')");
            if(queryCreate.exec())
            {
                qInfo() << "Everything is working and you querry was added to your teachers database. :)";
            }
            else
            {
                qDebug() << "Something went terribly wrong.";
            }
            // Creation of new teacher - END OF CODE

         }
         clearingLineEdits();
     }

     void Create::clearingLineEdits() // function is making line edits "empty" after all operations, whatever they are
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


