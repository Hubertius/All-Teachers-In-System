/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_ConnStat;
    QGroupBox *groupBox;
    QPushButton *btnLogin;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelUsername;
    QLineEdit *lineEditUsername;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelPassword;
    QLineEdit *lineEditPassword;
    QLabel *label;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuLogin_to_Teachers_APP;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(640, 410);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_ConnStat = new QLabel(centralwidget);
        label_ConnStat->setObjectName(QString::fromUtf8("label_ConnStat"));
        label_ConnStat->setGeometry(QRect(10, 290, 351, 61));
        label_ConnStat->setScaledContents(false);
        label_ConnStat->setWordWrap(false);
        label_ConnStat->setMargin(0);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(220, 40, 251, 161));
        btnLogin = new QPushButton(groupBox);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(80, 120, 80, 23));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 50, 197, 58));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelUsername = new QLabel(layoutWidget);
        labelUsername->setObjectName(QString::fromUtf8("labelUsername"));

        horizontalLayout->addWidget(labelUsername);

        lineEditUsername = new QLineEdit(layoutWidget);
        lineEditUsername->setObjectName(QString::fromUtf8("lineEditUsername"));

        horizontalLayout->addWidget(lineEditUsername);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelPassword = new QLabel(layoutWidget);
        labelPassword->setObjectName(QString::fromUtf8("labelPassword"));

        horizontalLayout_2->addWidget(labelPassword);

        lineEditPassword = new QLineEdit(layoutWidget);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        lineEditPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEditPassword);


        verticalLayout->addLayout(horizontalLayout_2);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 171, 181));
        LoginWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LoginWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 20));
        menuLogin_to_Teachers_APP = new QMenu(menubar);
        menuLogin_to_Teachers_APP->setObjectName(QString::fromUtf8("menuLogin_to_Teachers_APP"));
        LoginWindow->setMenuBar(menubar);
#if QT_CONFIG(shortcut)
        labelUsername->setBuddy(lineEditUsername);
        labelPassword->setBuddy(lineEditPassword);
#endif // QT_CONFIG(shortcut)

        menubar->addAction(menuLogin_to_Teachers_APP->menuAction());

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "LoginWindow", nullptr));
        label_ConnStat->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">Waiting for the connection...</span></p></body></html>", nullptr));
        groupBox->setTitle(QCoreApplication::translate("LoginWindow", "Signin", nullptr));
        btnLogin->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        labelUsername->setText(QCoreApplication::translate("LoginWindow", "Username", nullptr));
        labelPassword->setText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
        label->setText(QString());
        menuLogin_to_Teachers_APP->setTitle(QCoreApplication::translate("LoginWindow", "Login to Teachers APP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
