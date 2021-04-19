#ifndef UPDATE_H
#define UPDATE_H

#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QSqlError>
#include "../utils.h"
namespace Ui
{
    class Update;
}

namespace HubertiusNamespace
{
    class Update : public QWidget
    {
        Q_OBJECT

    public:
        explicit Update(QWidget *parent, QSqlDatabase * database);
        friend bool dataValidation(QString name, QString surname, QString sex, QString pesel, QString dateOfBirth, QString title, QString listOfSubjects);
        void clearingLineEdits();
        ~Update();

    private slots:
        void on_pushButton_clicked();

    private:
        QSqlDatabase * myTeachersDatabase;
        Ui::Update *ui;
    };
}
#endif // UPDATE_H
