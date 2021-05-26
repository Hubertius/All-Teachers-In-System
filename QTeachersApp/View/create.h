#ifndef CREATE_H
#define CREATE_H
#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QSqlError>
#include "../utils.h"

namespace Ui
{
    class Create;
}

namespace HubertiusNamespace
{
    class Create : public QWidget
    {
        Q_OBJECT

    public:
        explicit Create(QWidget* parent, QSqlDatabase* database);
         void clearingLineEdits();
        ~Create();

    private slots:
        void on_pushButton_clicked();

    private:
        QSqlDatabase* myTeachersDatabase;
        void fillTeacherToCreate(Teacher& teacher);
        bool isTeacherInDatabase(const Teacher& teacher);
        void createIntoDatabase(const Teacher& teacher);
        Ui::Create* ui;
    };
}
#endif // CREATE_H
