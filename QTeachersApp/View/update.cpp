#include "update.h"
#include "ui_update.h"
#include <QMessageBox>

namespace HubertiusNamespace
{

    Update::Update(QWidget *parent, QSqlDatabase * database):
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
        bool checkForIntId;
        int id = ui->lineEdit_id->text().toInt(&checkForIntId, 10);
        if(checkForIntId == false)
        {
            qDebug() << "ID, which you wrote is not even an integer!";
            return;
        }
        QString name = ui->lineEdit_name->text();
        QString surname = ui->lineEdit_surname->text();
        QString sex = ui->lineEdit_sex->text();
        QString pesel = ui->lineEdit_pesel->text();
        QString dateOfBirth = ui->lineEdit_dateOfBirth->text();
        QString title = ui->lineEdit_title->text();
        QString listOfSubjects = ui->lineEdit_listOfSubjects->text();

        if((*myTeachersDatabase).isOpen())
        {
            QSqlQuery querySelect;
            querySelect.prepare("SELECT * FROM Teachers");
            querySelect.exec();
            bool checkForId = false;
            while(querySelect.next())
            {
                int idInBase = querySelect.value(0).toInt();
                if(idInBase == id)
                {
                    checkForId = true;
                }
                qDebug() << idInBase;
            }
            if(checkForId)
            {
                qDebug() << "There is id in database mathching it.";
            }
            else
            {
                qDebug() << "There is no id matching in teachers database.";
                clearingLineEdits();
                return;
            }
            if( !dataValidation(name, surname, sex, pesel, dateOfBirth, title, listOfSubjects) )
            {
                clearingLineEdits();
                return;
            }
            else
            {
                QSqlQuery queryUpdate;
                queryUpdate.prepare("UPDATE Teachers SET Name = '"+name+"', Surname = '"+surname+"', Sex = '"+sex+"', PESEL = '"+pesel+"', DateOfBirth = '"+dateOfBirth+"', Title = '"+title+"', ListOfSubjects = '"+listOfSubjects+"' WHERE ID = '"+QString::number(id)+"'");
                if(queryUpdate.exec())
                {
                    QMessageBox::critical(this,tr("Edit"), tr("Updated"));
                }
                else
                {
                   QMessageBox::critical(this,tr("ERROR WITH QUERY!"), queryUpdate.lastError().text());
                }
            }
            clearingLineEdits();

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


