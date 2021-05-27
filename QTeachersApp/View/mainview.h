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
    /*!
     *MainView class is practically "main body" of the app when login process to it is finished.
     *This is detailed description of "MainView" class. More stuff in here.
     */
    class MainView : public QDialog
    {
        Q_OBJECT
    public:
        explicit MainView(QWidget* parent=nullptr);
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
        friend void connClose(QSqlDatabase* myDatabase);
        friend bool connOpen(QSqlDatabase* myDatabase, const QString& PATH);

    };
}

#endif // MAINVIEW_H
