#ifndef UPDATE_H
#define UPDATE_H

#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QSqlError>
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
        ~Update();

    private:
        QSqlDatabase * myTeachersDatabase;
        Ui::Update *ui;
    };
}
#endif // UPDATE_H
