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
}
