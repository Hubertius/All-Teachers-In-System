#include "update.h"
#include "ui_update.h"
#include <QMessageBox>

namespace HubertiusNamespace
{
    Update::Update(QWidget* parent, QSqlDatabase* database):
        myTeachersDatabase(database),
        QWidget(parent),
        ui(new Ui::Update)
    {
        ui->setupUi(this);
    }

    Update::~Update()
    {
        delete ui;
    }

    void Update::on_pushButton_clicked()
    {
        if(isIdInt() == false)
        {
            qDebug() << "ID, which you wrote is not even an integer!";
            return;
        }
        Teacher teacher;
        fillTeacherToUpdate(teacher);
        if((*myTeachersDatabase).isOpen())
        {
            if(isTeacherIdInDatabase(teacher) && dataValidation(teacher))
            {
                updateIntoDatabase(teacher);
                qDebug() << "Your \"teacher\" was succesfully updated in database!";
            }
            else
            {
                qDebug() << "Your \"teacher\" can't be updated!";
            }
        }
        clearingLineEdits();
    }

    void Update::fillTeacherToUpdate(Teacher& teacher)
    {
        teacher.name = ui->lineEdit_name->text();
        teacher.surname = ui->lineEdit_surname->text();
        teacher.sex = ui->lineEdit_sex->text();
        teacher.pesel = ui->lineEdit_pesel->text();
        teacher.dateOfBirth = ui->lineEdit_dateOfBirth->text();
        teacher.title = ui->lineEdit_title->text();
        teacher.listOfSubjects = ui->lineEdit_listOfSubjects->text();
    }

    bool Update::isIdInt()
    {
        bool checkForIntId;
        ui->lineEdit_id->text().toInt(&checkForIntId, 10);
        return checkForIntId;
    }

    bool Update::isTeacherIdInDatabase(const Teacher& teacher)
    {
        QSqlQuery querySelect;
        querySelect.prepare("SELECT * FROM Teachers");
        querySelect.exec();
        bool checkForId = false;
        while(querySelect.next())
        {
            int idInBase = querySelect.value(0).toInt();
            bool temp;
            int idFromUser = ui->lineEdit_id->text().toInt(&temp, 10);
            if(idInBase == idFromUser)
            {
                return true;
            }
            qDebug() << idInBase;
        }
        return false;
    }

    void Update::updateIntoDatabase(const Teacher& teacher)
    {
        QSqlQuery queryUpdate;
        queryUpdate.prepare("UPDATE Teachers SET Name = ?, Surname = ?, Sex = ?, PESEL = ?, DateOfBirth = ?, Title = ?, ListOfSubjects = ? WHERE ID = ?");
        queryUpdate.addBindValue(teacher.name);
        queryUpdate.addBindValue(teacher.surname);
        queryUpdate.addBindValue(teacher.sex);
        queryUpdate.addBindValue(teacher.pesel);
        queryUpdate.addBindValue(teacher.dateOfBirth);
        queryUpdate.addBindValue(teacher.title);
        queryUpdate.addBindValue(teacher.listOfSubjects);
        bool toIntConversion;
        queryUpdate.addBindValue(QString::number(ui->lineEdit_id->text().toInt(&toIntConversion,10)));
        if(queryUpdate.exec())
        {
            QMessageBox::critical(this,tr("Edit"), tr("Updated"));
        }
        else
        {
           QMessageBox::critical(this,tr("ERROR WITH QUERY!"), queryUpdate.lastError().text());
        }
    }

    void Update::clearingLineEdits()
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


