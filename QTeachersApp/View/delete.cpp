#include "delete.h"
#include "ui_delete.h"
#include <QMessageBox>

namespace HubertiusNamespace
{

    Delete::Delete(QWidget *parent, QSqlDatabase * database):
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
        bool checkForIntId;
        int id = ui->lineEdit_id->text().toInt(&checkForIntId, 10); // coversion of ID into int in Qt
        if(checkForIntId == false)
        {
            qDebug() << "ID, which you wrote is not even an integer!";
            return;
        }
        // Getting data from lineEdits of ui - START OF CODE
        QString name = ui->lineEdit_name->text();
        QString surname = ui->lineEdit_surname->text();
        QString sex = ui->lineEdit_sex->text();
        QString pesel = ui->lineEdit_pesel->text();
        QString dateOfBirth = ui->lineEdit_dateOfBirth->text();
        QString title = ui->lineEdit_title->text();
        QString listOfSubjects = ui->lineEdit_listOfSubjects->text();
        // Getting data from lineEdits of ui - END OF CODE
        bool checkForEqualisation = false;

        if((*myTeachersDatabase).isOpen())
        {
            // Checking if there is the same data in database already - START OF CODE
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
                    if(name == querySelect.value(1).toString()
                       && surname == querySelect.value(2).toString()
                       && sex == querySelect.value(3).toString()
                       && pesel == querySelect.value(4).toString()
                       && dateOfBirth == querySelect.value(5).toString()
                       && title == querySelect.value(6).toString()
                       && listOfSubjects == querySelect.value(7).toString())
                    {
                        checkForEqualisation = true;
                    }
                    else
                    {
                        clearingLineEdits();
                        return;
                    }

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
            // Checking if there is the same data in database already - END OF CODE
            // Removing data in database if they exist - START OF CODE
            if(checkForEqualisation)
            {
                QSqlQuery queryDelete;
                queryDelete.prepare("DELETE FROM Teachers WHERE ID = '"+QString::number(id)+"'");
                if(queryDelete.exec())
                {
                    QMessageBox::critical(this,tr("Delete"),tr("Deleted"));
                }
                else
                {
                    QMessageBox::critical(this,tr("ERROR WITH QUERY!"),queryDelete.lastError().text());
                }
            }
            // Removing data in databe if they exist - END OF CODE
            clearingLineEdits();
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


