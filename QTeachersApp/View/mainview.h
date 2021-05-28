#ifndef MAINVIEW_H
#define MAINVIEW_H


#include <QDialog>
#include "utils.h"

namespace Ui
{
    class MainView;
}

namespace HubertiusNamespace
{
    class Read;
    class Create;
    class Update;
    class Delete;
<<<<<<< HEAD
    /*! \brief MainView class is practically "main body" of the app when Login class responsible for app working moves to it after successful login.
     *
     *  Tab widget of MainView got four pages with 4 classes added to it's content.\n
     *  Pages of tab widget:\n
     *  a) Read - Read class is responsible for it's content\n
     *  b) Create - Create class is responsible for it's content\n
     *  c) Update - Update class is responsible for it's content\n
     *  d) Delete - Delete class is responsible for it's content\n
     *  So this clas is responsible for working with instances of classes mentioned above and with opening and closing\n
     *  of teachers database.
=======
    /*!
     *
     *
>>>>>>> 61aecf2d8c8b0d9a2190845ec39034700ed86d9d
     */
    class MainView : public QDialog
    {
        Q_OBJECT
    public:
        /*!
         * \brief Constructor (only) of LoginWindow
         * \param nullptr (no parent basically)
         *
         * Constructor is making connection with teachers.sqlite database.\n
         * Beyond that it adds widgets (bascially 4 classes) to 4 pages of tab widget from MainView
         */
        explicit MainView(QWidget* parent=nullptr);

       /*!
         * \brief MainView destructor
         *
         * Destructor is closing connection with teachers.sqlite database.\n
         * That are basically only operations which this method is making.
         */
        ~MainView();

    private:
        Read& m_readTab;
        Create& m_createTab;
        Update& m_updateTab;
        Delete& m_deleteTab;
        QSqlDatabase myTeachersDatabase;
        QString path;
        Ui::MainView *ui;

    public:
        friend void connClose(QSqlDatabase* myDatabase); /*!< friend function from utils files. It serves for closing of teachers.sqlite database  */
        friend bool connOpen(QSqlDatabase* myDatabase, const QString& PATH); /*!< friend function from utils files. It serves for opening of teachers.sqlite database */

    };
}

#endif // MAINVIEW_H
