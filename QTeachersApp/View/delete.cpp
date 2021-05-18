#include "delete.h"
#include "ui_delete.h"
#include <QMessageBox>

namespace HubertiusNamespace
{
    Delete::Delete(QWidget* parent, QSqlDatabase* database):
        myTeachersDatabase(database),
        QWidget(parent),
        ui(new Ui::Delete)
    {
        ui->setupUi(this);
    }

    Delete::~Delete()
    {
        delete ui;
    }

    void Delete::on_pushButton_clicked()
    {
        if(isIdInt() == false)
        {
            qDebug() << "ID, which you wrote is not even an integer!";
            return;
        }
        Teacher teacher;
        fillTeacherToDelete(teacher);
        bool checkForEqualisation = false;
        if((*myTeachersDatabase).isOpen())
        {
            // Checking if there is the same data in database already - START OF CODE
            QSqlQuery querySelect;
            querySelect.prepare("SELECT * FROM Teachers");
            querySelect.exec();
            while(querySelect.next())
            {
                bool temp;
                int id = ui->lineEdit_id->text().toInt(&temp, 10);
                if(isIdInt() && id == querySelect.value(0).toInt())
                {
                   if(teacher.name == querySelect.value(1).toString()
                   && teacher.surname == querySelect.value(2).toString()
                   && teacher.sex == querySelect.value(3).toString()
                   && teacher.pesel == querySelect.value(4).toString()
                   && teacher.dateOfBirth == querySelect.value(5).toString()
                   && teacher.title == querySelect.value(6).toString()
                   && teacher.listOfSubjects == querySelect.value(7).toString())
                   {
                       checkForEqualisation = true;
                   }
                   else
                   {
                       clearingLineEdits();
                       return;
                   }
                }
            }
            if(checkForEqualisation)
            {
               deleteFromDatabase(teacher);
            }
            clearingLineEdits();
        }
    }

    void Delete::fillTeacherToDelete(Teacher& teacher)
    {
        teacher.name = ui->lineEdit_name->text();
        teacher.surname = ui->lineEdit_surname->text();
        teacher.sex = ui->lineEdit_sex->text();
        teacher.pesel = ui->lineEdit_pesel->text();
        teacher.dateOfBirth = ui->lineEdit_dateOfBirth->text();
        teacher.title = ui->lineEdit_title->text();
        teacher.listOfSubjects = ui->lineEdit_listOfSubjects->text();
    }

    bool Delete::isIdInt()
    {
        bool checkForIntId;
        ui->lineEdit_id->text().toInt(&checkForIntId, 10);
        return checkForIntId;
    }

    void Delete::deleteFromDatabase(Teacher& teacher)
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM Teachers WHERE ID = ?");
        bool toIntConversion;
        queryDelete.addBindValue(QString::number(ui->lineEdit_id->text().toInt(&toIntConversion,10)));
        if(queryDelete.exec())
        {
            QMessageBox::critical(this,tr("Delete"),tr("Deleted"));
        }
        else
        {
            QMessageBox::critical(this,tr("ERROR WITH QUERY!"),queryDelete.lastError().text());
        }
    }

    void Delete::clearingLineEdits()
    {
        ui->lineEdit_id->setText("");
        ui->lineEdit_name->setText("");
        ui->lineEdit_surname->setText("");
        ui->lineEdit_sex->setText("");
        ui->lineEdit_pesel->setText("");
        ui->lineEdit_dateOfBirth->setText("");
        ui->lineEdit_title->setText("");
        ui->lineEdit_listOfSubjects->setText("");
    }
}


