#include "update.h"
#include "ui_update.h"

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

}
