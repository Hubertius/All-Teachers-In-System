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
    /*!
     * \brief The Update class is responsible for updating teacher entry.
     *
     * It updates teacher entry in teachers.sqlite database.\n
     * Id of teacher entry must match with that being in database.
     */
    class Update : public QWidget
    {
        Q_OBJECT

    public:
        /*!
         * \brief Constructor (only) of Update class.
         * \param parent got adress of parent of this class (which is MainView instance)
         * \param database pointer got adress of QSqlDatabase object, which will be connected to teachers.sqlite
         */
        explicit Update(QWidget* parent, QSqlDatabase* database);
        /*!
         * Destructor "destructs" instance of Update class.
         */
        ~Update();

    private slots:
        void on_pushButton_clicked();

    private:
        QSqlDatabase* myTeachersDatabase;
        friend bool dataValidation(QString name, QString surname, QString sex, QString pesel, QString dateOfBirth, QString title, QString listOfSubjects);
        void fillTeacherToUpdate(Teacher& teacher);
        bool isIdInt();
        bool isTeacherIdInDatabase(const Teacher& teacher);
        void updateIntoDatabase(const Teacher& teacher);
        void clearingLineEdits();
        Ui::Update* ui;
    };
}
#endif // UPDATE_H
