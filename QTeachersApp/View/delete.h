#ifndef DELETE_H
#define DELETE_H

#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QSqlError>
#include "../utils.h"

namespace Ui
{
    class Delete;
}

namespace HubertiusNamespace
{
    class Delete : public QWidget
    {
        Q_OBJECT

    public:
        explicit Delete(QWidget* parent, QSqlDatabase* database);
        friend bool dataValidation(QString name, QString surname, QString sex, QString pesel, QString dateOfBirth, QString title, QString listOfSubjects);
        void clearingLineEdits();
        ~Delete();

    private slots:
        void on_pushButton_clicked();

    private:
        QSqlDatabase* myTeachersDatabase;
        void fillTeacherToDelete(Teacher& teacher);
        bool isIdInt();
        void deleteFromDatabase(Teacher& teacher);
        Ui::Delete* ui;
    };
}
#endif // DELETE_H
