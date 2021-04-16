#include "read.h"
#include "ui_read.h"

namespace HubertiusNamespace
{

    Read::Read(QWidget *parent, QSqlDatabase * database):
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

}
