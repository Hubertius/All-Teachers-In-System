#include "delete.h"
#include "ui_delete.h"

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

}
