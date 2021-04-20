#include "mainview.h"
#include "ui_mainview.h"
#include "View/read.h"
#include "View/create.h"
#include "View/update.h"
#include "View/delete.h"

namespace HubertiusNamespace
{

    MainView::MainView(QWidget *parent):
        m_readTab(*new Read(this, &myTeachersDatabase)),
        m_createTab(*new Create(this, &myTeachersDatabase)),
        m_updateTab(*new Update(this, &myTeachersDatabase)),
        m_deleteTab(*new Delete(this, &myTeachersDatabase)),
        QDialog(parent),
        ui(new Ui::MainView)
    {
        ui->setupUi(this);
        myTeachersDatabase = QSqlDatabase::addDatabase("QSQLITE");
        QDir tempPath = QDir::current();
        tempPath.cdUp(); // to get out from /.../build-QTeachersApp-Desktop-Debug one folder up into /All-Teachers-In-System
        connOpen(&myTeachersDatabase, tempPath.path() + "/QTeachersApp/DataBases/teachers.sqlite");
        ui->loReadTab->addWidget(&m_readTab);
        ui->loCreateTab->addWidget(&m_createTab);
        ui->loUpdateTab->addWidget(&m_updateTab);
        ui->loDeleteTab->addWidget(&m_deleteTab);
    }

    MainView::~MainView()
    {
        connClose(&myTeachersDatabase);
        delete ui;
    }

}
