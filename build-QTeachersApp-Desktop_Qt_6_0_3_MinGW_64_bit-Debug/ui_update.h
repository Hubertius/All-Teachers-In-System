/********************************************************************************
** Form generated from reading UI file 'update.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATE_H
#define UI_UPDATE_H

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

class Ui_Update
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_id;
    QLineEdit *lineEdit_id;
    QGroupBox *groupBoxOfData;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_surname;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_sex;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_pesel;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_dateOfBirth;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEdit_title;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *lineEdit_listOfSubjects;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton;

    void setupUi(QWidget *Update)
    {
        if (Update->objectName().isEmpty())
            Update->setObjectName(QString::fromUtf8("Update"));
        Update->resize(700, 480);
        verticalLayout_2 = new QVBoxLayout(Update);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_id = new QLabel(Update);
        label_id->setObjectName(QString::fromUtf8("label_id"));

        horizontalLayout_8->addWidget(label_id);

        lineEdit_id = new QLineEdit(Update);
        lineEdit_id->setObjectName(QString::fromUtf8("lineEdit_id"));

        horizontalLayout_8->addWidget(lineEdit_id);


        verticalLayout_2->addLayout(horizontalLayout_8);

        groupBoxOfData = new QGroupBox(Update);
        groupBoxOfData->setObjectName(QString::fromUtf8("groupBoxOfData"));
        verticalLayout = new QVBoxLayout(groupBoxOfData);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_name = new QLabel(groupBoxOfData);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        horizontalLayout->addWidget(label_name);

        lineEdit_name = new QLineEdit(groupBoxOfData);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        horizontalLayout->addWidget(lineEdit_name);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBoxOfData);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_surname = new QLineEdit(groupBoxOfData);
        lineEdit_surname->setObjectName(QString::fromUtf8("lineEdit_surname"));

        horizontalLayout_2->addWidget(lineEdit_surname);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBoxOfData);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_sex = new QLineEdit(groupBoxOfData);
        lineEdit_sex->setObjectName(QString::fromUtf8("lineEdit_sex"));

        horizontalLayout_3->addWidget(lineEdit_sex);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(groupBoxOfData);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_pesel = new QLineEdit(groupBoxOfData);
        lineEdit_pesel->setObjectName(QString::fromUtf8("lineEdit_pesel"));

        horizontalLayout_4->addWidget(lineEdit_pesel);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(groupBoxOfData);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEdit_dateOfBirth = new QLineEdit(groupBoxOfData);
        lineEdit_dateOfBirth->setObjectName(QString::fromUtf8("lineEdit_dateOfBirth"));

        horizontalLayout_5->addWidget(lineEdit_dateOfBirth);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(groupBoxOfData);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        lineEdit_title = new QLineEdit(groupBoxOfData);
        lineEdit_title->setObjectName(QString::fromUtf8("lineEdit_title"));

        horizontalLayout_6->addWidget(lineEdit_title);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(groupBoxOfData);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        lineEdit_listOfSubjects = new QLineEdit(groupBoxOfData);
        lineEdit_listOfSubjects->setObjectName(QString::fromUtf8("lineEdit_listOfSubjects"));

        horizontalLayout_7->addWidget(lineEdit_listOfSubjects);


        verticalLayout->addLayout(horizontalLayout_7);


        verticalLayout_2->addWidget(groupBoxOfData);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        pushButton = new QPushButton(Update);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_9->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_9);


        retranslateUi(Update);

        QMetaObject::connectSlotsByName(Update);
    } // setupUi

    void retranslateUi(QWidget *Update)
    {
        Update->setWindowTitle(QCoreApplication::translate("Update", "Form", nullptr));
        label_id->setText(QCoreApplication::translate("Update", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Id of data to search </span></p><p><span style=\" font-size:12pt; font-weight:600;\">for UPDATE operation</span></p></body></html>", nullptr));
        groupBoxOfData->setTitle(QCoreApplication::translate("Update", "Data to Update", nullptr));
        label_name->setText(QCoreApplication::translate("Update", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("Update", "Surname", nullptr));
        label_3->setText(QCoreApplication::translate("Update", "Sex", nullptr));
        label_4->setText(QCoreApplication::translate("Update", "PESEL", nullptr));
        label_5->setText(QCoreApplication::translate("Update", "DateOfBirth", nullptr));
        label_6->setText(QCoreApplication::translate("Update", "Title", nullptr));
        label_7->setText(QCoreApplication::translate("Update", "ListOfSubjects", nullptr));
        pushButton->setText(QCoreApplication::translate("Update", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Update: public Ui_Update {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATE_H
