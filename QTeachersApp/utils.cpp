#include "utils.h"

namespace HubertiusNamespace
{

    bool connOpen(QSqlDatabase * myDatabase, const QString & PATH)
    {
        (*myDatabase).setDatabaseName(PATH);
        if((*myDatabase).open())
        {
            qDebug() << "Connected to database.";
            return true;
        }
        else
        {
            qDebug() << "Failed to open the database!";
        }
        return false;
    }

    void connClose(QSqlDatabase * myDatabase)
    {
        (*myDatabase).close();
        (*myDatabase).removeDatabase(QSqlDatabase::defaultConnection);
    }

}
