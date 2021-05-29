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
    /*!
     * \brief The Delete class is responsible for operation of delete operations.
     *
     * Delete teachers entries from teachers.sqlite database.\n
     * If delete operation could be successful every data in teacher entry must be\n
     * the same as this written in QLineEdits.
     */
    class Delete : public QWidget
    {
        Q_OBJECT

    public:
        /*!
         * \brief Constructor (only) of Delete class.
         * \param parent got adress of parent of this class (which is MainView instance)
         * \param database pointer got adress of QSqlDatabase object, which will be connected to teachers.sqlite
         */
        explicit Delete(QWidget* parent, QSqlDatabase* database);
        /*!
         * Destructor "destructs" instance of Delete class
         */
        ~Delete();

    private slots:
        void on_pushButton_clicked();

    private:
        QSqlDatabase* myTeachersDatabase;
        friend bool dataValidation(QString name, QString surname, QString sex, QString pesel, QString dateOfBirth, QString title, QString listOfSubjects);
        void fillTeacherToDelete(Teacher& teacher);
        bool isIdInt();
        bool isTeacherInDatabase(const Teacher& teacher);
        void deleteFromDatabase(const Teacher& teacher);
        void clearingLineEdits();
        Ui::Delete* ui;
    };
}
#endif // DELETE_H
