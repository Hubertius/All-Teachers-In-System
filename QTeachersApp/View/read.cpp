#include "read.h"
#include "ui_read.h"

namespace HubertiusNamespace
{
    Read::Read(QWidget* parent, QSqlDatabase* database):
        myTeachersDatabase(database),
        QWidget(parent),
        ui(new Ui::Read)
    {
        ui->setupUi(this);
    }

    Read::~Read()
    {
        delete ui;
    }

    void Read::on_pushButton_clicked()
    {
        QSqlQueryModel* model = new QSqlQueryModel();
        QSqlQuery* query = new QSqlQuery(*myTeachersDatabase);
        query->prepare("SELECT * FROM Teachers");
        if(query->exec())
        {
            model->setQuery(*query);
            ui->tableView->setModel(model);
        }
    }
}


