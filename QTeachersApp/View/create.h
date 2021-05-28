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
    /*!
     * \brief The Create class is responsible for create operation.
     *
     * Create is making new entries to teachers.sqlite database.\n
     * If operation could be successful data in QLineEdits\n
     * can't be equal to one of the entries in teachers.sqlite database.
     */
    class Create : public QWidget
    {
        Q_OBJECT

    public:
        /*!
         * \brief Constructor (only) of Create class.
         * \param parent got adress of parent of this class (which is MainView instance)
         * \param database pointer got adress of QSqlDatabase object, which will be connected to teachers.sqlite
         */
        explicit Create(QWidget* parent, QSqlDatabase* database);
        /*!
         * Destructor "destructs" instance of Create class
         */
        ~Create();

    private slots:
        void on_pushButton_clicked();

    private:
        QSqlDatabase* myTeachersDatabase;
        friend bool dataValidation(QString name, QString surname, QString sex, QString pesel, QString dateOfBirth, QString title, QString listOfSubjects);
        void fillTeacherToCreate(Teacher& teacher);
        bool isTeacherInDatabase(const Teacher& teacher);
        void createIntoDatabase(const Teacher& teacher);
        void clearingLineEdits();
        Ui::Create* ui;
    };
}
#endif // CREATE_H
