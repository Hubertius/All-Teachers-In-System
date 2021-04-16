#ifndef READ_H
#define READ_H

#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QSqlError>
namespace Ui
{
    class Read;
}

namespace HubertiusNamespace
{
    class Read : public QWidget
    {
        Q_OBJECT

    public:
        explicit Read(QWidget *parent, QSqlDatabase * database);
        ~Read();

    private:
        QSqlDatabase * myTeachersDatabase;
        Ui::Read *ui;
    };
}

#endif // READ_H
