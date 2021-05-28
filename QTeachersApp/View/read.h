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
    /*!
     * \brief The Read class is responsible for reading teachers.
     *
     * It reads entire content of teachers.sqlite database.
     */
    class Read : public QWidget
    {
        Q_OBJECT

    public:
        /*!
         * \brief Constructor (only) of Create class.
         * \param parent got adress of parent of this class (which is MainView instance)
         * \param database pointer got adress of QSqlDatabase object, which will be connected to teachers.sqlite
         */
        explicit Read(QWidget* parent, QSqlDatabase* database);
        /*!
         * Destructor "destructs" instance of Read class.
         */
        ~Read();

    private slots:
        void on_pushButton_clicked();

    private:
        QSqlDatabase* myTeachersDatabase;
        Ui::Read* ui;
    };
}

#endif // READ_H
