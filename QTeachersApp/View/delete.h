#ifndef DELETE_H
#define DELETE_H

#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QSqlError>
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
        explicit Delete(QWidget *parent, QSqlDatabase * database);
        ~Delete();

    private:
        QSqlDatabase * myTeachersDatabase;
        Ui::Delete *ui;
    };
}
#endif // DELETE_H
