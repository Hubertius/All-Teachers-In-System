#ifndef UTILS_H
#define UTILS_H



#include <QString>
#include <QtSql> // for creation (or connection) to SQLite database
#include <QtDebug>
#include <QFileInfo>
#include <QSqlError>
#include <QRegularExpression>
#include <QDir>

namespace HubertiusNamespace
{
    /*!
     * \brief The Teacher struct, which holds data of teacher.
     *
     * Data of Teacher struct are used in operation of create / update / delete in the app.
     * In create to add teacher entry to teacher.sqlite database with data equal to that of this structure.
     * In update to update teacher entry of teacher.sqlite database with the data of this structure.
     * In delete to remove teacher entry from teacher.sqlite database if the data of this structure are the same.
     */
    struct Teacher
    {
        QString name; /*!< Name of the teacher "taken from QLineEdit"*/
        QString surname; /*!< Surname of the teacher "taken from QLineEdit"*/
        QString sex; /*!< Sex of the teacher "taken from QLineEdit"*/
        QString pesel; /*!< PESEL of the teacher "taken from QLineEdit"*/
        QString dateOfBirth; /*!< Date of birth of teacher "taken from QLineEdit*/
        QString title; /*!< Title of the teacher "taken from QLineEdit"*/
        QString listOfSubjects; /*!< List of Subject "taken from QLineEdit"*/
    };

    void connClose(QSqlDatabase* myDatabase); /*!< function is closing .sqlite database */
    bool connOpen(QSqlDatabase* myDatabase, QString  path); /*!< function is opening .sqlite database */
    bool dataValidation(Teacher& teacher); /*!< function is making validation of "teacher data" */
    bool peselValidation(QString pesel); /*!< function executed in the dataValidation(), basically it validates only PESEL */
    bool isStartingWithUpper(QString name, QString surname, QString title, QString listOfSubjects); /*!< function executed in the dataValidation(), basically it check if word is starting with upper letter. */
    bool isValidDate(const QString day, const QString month, const QString year); /*!< function executed in the dataValidation(), it validates date of birth */
    bool isLeap(int year); /*!< function executed in the isValidDate(), it "checks" for date of birth being a leap year */
}



#endif // UTILS_H
