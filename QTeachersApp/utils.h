#ifndef UTILS_H
#define UTILS_H



#include <QString>
#include <QtSql> // for creation (or connection) to SQLite database
#include <QtDebug>
#include <QFileInfo>
#include <QSqlError>
#include <QRegExp>

namespace HubertiusNamespace
{

    void connClose(QSqlDatabase * myDatabase);
    bool connOpen(QSqlDatabase * myDatabase, const QString & PATH);
    bool dataValidation(QString name, QString surname, QString sex, QString pesel, QString dateOfBirth, QString title, QString);
    bool peselValidation(QString pesel);
    bool isStartingWithUpper(QString name, QString surname, QString title, QString listOfSubjects);
    bool isValidDate(const QString day, const QString month, const QString year);
    bool isLeap(int year);
}



#endif // UTILS_H
