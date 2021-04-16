/********************************************************************************
** Form generated from reading UI file 'read.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READ_H
#define UI_READ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Read
{
public:
    QLabel *label;

    void setupUi(QWidget *Read)
    {
        if (Read->objectName().isEmpty())
            Read->setObjectName(QString::fromUtf8("Read"));
        Read->resize(700, 480);
        label = new QLabel(Read);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 80, 59, 15));

        retranslateUi(Read);

        QMetaObject::connectSlotsByName(Read);
    } // setupUi

    void retranslateUi(QWidget *Read)
    {
        Read->setWindowTitle(QApplication::translate("Read", "Form", nullptr));
        label->setText(QApplication::translate("Read", "Read", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Read: public Ui_Read {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READ_H
