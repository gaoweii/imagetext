/********************************************************************************
** Form generated from reading UI file 'transform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFORM_H
#define UI_TRANSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_transform
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *transform)
    {
        if (transform->objectName().isEmpty())
            transform->setObjectName(QString::fromUtf8("transform"));
        transform->resize(423, 105);
        centralWidget = new QWidget(transform);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 201, 71));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 10, 181, 71));
        transform->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(transform);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        transform->setStatusBar(statusBar);

        retranslateUi(transform);

        QMetaObject::connectSlotsByName(transform);
    } // setupUi

    void retranslateUi(QMainWindow *transform)
    {
        transform->setWindowTitle(QApplication::translate("transform", "transform", nullptr));
        pushButton->setText(QApplication::translate("transform", "\345\233\276\347\211\207\350\275\254txt\346\226\207\346\234\254", nullptr));
        pushButton_2->setText(QApplication::translate("transform", "\345\233\276\347\211\207\350\275\254txt\346\226\207\346\234\254(\351\235\236otsu)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class transform: public Ui_transform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORM_H
