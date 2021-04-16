#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QtSql> // for creation (or connection) to SQLite database
#include <QtDebug>
#include <QFileInfo>
#include <QSqlError>

namespace HubertiusNamespace
{

    void connClose(QSqlDatabase * myDatabase);
    bool connOpen(QSqlDatabase * myDatabase, const QString & PATH);

}



#endif // UTILS_H
