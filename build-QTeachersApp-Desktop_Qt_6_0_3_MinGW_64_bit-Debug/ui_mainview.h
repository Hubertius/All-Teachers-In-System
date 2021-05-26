/********************************************************************************
** Form generated from reading UI file 'mainview.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINVIEW_H
#define UI_MAINVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainView
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabRead;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *loReadTab;
    QWidget *tabCreate;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *loCreateTab;
    QWidget *tabUpdate;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *loUpdateTab;
    QWidget *tabDelete;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *loDeleteTab;

    void setupUi(QDialog *MainView)
    {
        if (MainView->objectName().isEmpty())
            MainView->setObjectName(QString::fromUtf8("MainView"));
        MainView->resize(720, 500);
        MainView->setToolTipDuration(-7);
        verticalLayout = new QVBoxLayout(MainView);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(MainView);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabRead = new QWidget();
        tabRead->setObjectName(QString::fromUtf8("tabRead"));
        verticalLayout_3 = new QVBoxLayout(tabRead);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        loReadTab = new QVBoxLayout();
        loReadTab->setObjectName(QString::fromUtf8("loReadTab"));

        verticalLayout_3->addLayout(loReadTab);

        tabWidget->addTab(tabRead, QString());
        tabCreate = new QWidget();
        tabCreate->setObjectName(QString::fromUtf8("tabCreate"));
        verticalLayout_5 = new QVBoxLayout(tabCreate);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        loCreateTab = new QVBoxLayout();
        loCreateTab->setObjectName(QString::fromUtf8("loCreateTab"));

        verticalLayout_5->addLayout(loCreateTab);

        tabWidget->addTab(tabCreate, QString());
        tabUpdate = new QWidget();
        tabUpdate->setObjectName(QString::fromUtf8("tabUpdate"));
        verticalLayout_7 = new QVBoxLayout(tabUpdate);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        loUpdateTab = new QVBoxLayout();
        loUpdateTab->setObjectName(QString::fromUtf8("loUpdateTab"));

        verticalLayout_7->addLayout(loUpdateTab);

        tabWidget->addTab(tabUpdate, QString());
        tabDelete = new QWidget();
        tabDelete->setObjectName(QString::fromUtf8("tabDelete"));
        verticalLayout_9 = new QVBoxLayout(tabDelete);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        loDeleteTab = new QVBoxLayout();
        loDeleteTab->setObjectName(QString::fromUtf8("loDeleteTab"));

        verticalLayout_9->addLayout(loDeleteTab);

        tabWidget->addTab(tabDelete, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(MainView);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainView);
    } // setupUi

    void retranslateUi(QDialog *MainView)
    {
        MainView->setWindowTitle(QCoreApplication::translate("MainView", "Dialog", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabRead), QCoreApplication::translate("MainView", "Read", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCreate), QCoreApplication::translate("MainView", "Create", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabUpdate), QCoreApplication::translate("MainView", "Update", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDelete), QCoreApplication::translate("MainView", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainView: public Ui_MainView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVIEW_H
