#ifndef CREATE_H
#define CREATE_H
#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QSqlError>

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
        explicit Create(QWidget *parent, QSqlDatabase * database);
        ~Create();

    private slots:
        void on_pushButton_clicked();

    private:
        QSqlDatabase * myTeachersDatabase;
        Ui::Create *ui;
    };
}
#endif // CREATE_H
