/********************************************************************************
** Form generated from reading UI file 'create.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_H
#define UI_CREATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Create
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_surname;
    QLineEdit *lineEdit_surname;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_sex;
    QLineEdit *lineEdit_sex;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_pesel;
    QLineEdit *lineEdit_pesel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_dateOfBirth;
    QLineEdit *lineEdit_dateOfBirth;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_title;
    QLineEdit *lineEdit_title;
    QHBoxLayout *horizontalLayout;
    QLabel *label_listOfSubjects;
    QLineEdit *lineEdit_listOfSubjects;
    QPushButton *pushButton;

    void setupUi(QWidget *Create)
    {
        if (Create->objectName().isEmpty())
            Create->setObjectName(QString::fromUtf8("Create"));
        Create->resize(700, 480);
        verticalLayout = new QVBoxLayout(Create);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(Create);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_name = new QLabel(groupBox);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        horizontalLayout_7->addWidget(label_name);

        lineEdit_name = new QLineEdit(groupBox);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        horizontalLayout_7->addWidget(lineEdit_name);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_surname = new QLabel(groupBox);
        label_surname->setObjectName(QString::fromUtf8("label_surname"));

        horizontalLayout_6->addWidget(label_surname);

        lineEdit_surname = new QLineEdit(groupBox);
        lineEdit_surname->setObjectName(QString::fromUtf8("lineEdit_surname"));

        horizontalLayout_6->addWidget(lineEdit_surname);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_sex = new QLabel(groupBox);
        label_sex->setObjectName(QString::fromUtf8("label_sex"));

        horizontalLayout_5->addWidget(label_sex);

        lineEdit_sex = new QLineEdit(groupBox);
        lineEdit_sex->setObjectName(QString::fromUtf8("lineEdit_sex"));

        horizontalLayout_5->addWidget(lineEdit_sex);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_pesel = new QLabel(groupBox);
        label_pesel->setObjectName(QString::fromUtf8("label_pesel"));

        horizontalLayout_4->addWidget(label_pesel);

        lineEdit_pesel = new QLineEdit(groupBox);
        lineEdit_pesel->setObjectName(QString::fromUtf8("lineEdit_pesel"));

        horizontalLayout_4->addWidget(lineEdit_pesel);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_dateOfBirth = new QLabel(groupBox);
        label_dateOfBirth->setObjectName(QString::fromUtf8("label_dateOfBirth"));

        horizontalLayout_2->addWidget(label_dateOfBirth);

        lineEdit_dateOfBirth = new QLineEdit(groupBox);
        lineEdit_dateOfBirth->setObjectName(QString::fromUtf8("lineEdit_dateOfBirth"));

        horizontalLayout_2->addWidget(lineEdit_dateOfBirth);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_title = new QLabel(groupBox);
        label_title->setObjectName(QString::fromUtf8("label_title"));

        horizontalLayout_3->addWidget(label_title);

        lineEdit_title = new QLineEdit(groupBox);
        lineEdit_title->setObjectName(QString::fromUtf8("lineEdit_title"));

        horizontalLayout_3->addWidget(lineEdit_title);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_listOfSubjects = new QLabel(groupBox);
        label_listOfSubjects->setObjectName(QString::fromUtf8("label_listOfSubjects"));

        horizontalLayout->addWidget(label_listOfSubjects);

        lineEdit_listOfSubjects = new QLineEdit(groupBox);
        lineEdit_listOfSubjects->setObjectName(QString::fromUtf8("lineEdit_listOfSubjects"));

        horizontalLayout->addWidget(lineEdit_listOfSubjects);


        verticalLayout_2->addLayout(horizontalLayout);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);


        verticalLayout->addWidget(groupBox);


        retranslateUi(Create);

        QMetaObject::connectSlotsByName(Create);
    } // setupUi

    void retranslateUi(QWidget *Create)
    {
        Create->setWindowTitle(QApplication::translate("Create", "Form", nullptr));
        groupBox->setTitle(QString());
        label_name->setText(QApplication::translate("Create", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Name</span></p></body></html>", nullptr));
        label_surname->setText(QApplication::translate("Create", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Surname</span></p></body></html>", nullptr));
        label_sex->setText(QApplication::translate("Create", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Sex</span></p></body></html>", nullptr));
        label_pesel->setText(QApplication::translate("Create", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">PESEL</span></p></body></html>", nullptr));
        label_dateOfBirth->setText(QApplication::translate("Create", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Date of Birth</span></p></body></html>", nullptr));
        label_title->setText(QApplication::translate("Create", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Title</span></p></body></html>", nullptr));
        label_listOfSubjects->setText(QApplication::translate("Create", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">List of Subjects</span></p></body></html>", nullptr));
        pushButton->setText(QApplication::translate("Create", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Create: public Ui_Create {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_H
