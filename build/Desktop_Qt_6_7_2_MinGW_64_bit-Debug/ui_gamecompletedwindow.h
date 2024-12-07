/********************************************************************************
** Form generated from reading UI file 'gamecompletedwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMECOMPLETEDWINDOW_H
#define UI_GAMECOMPLETEDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GameCompletedWindow
{
public:
    QPushButton *ok_butt;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QDialog *GameCompletedWindow)
    {
        if (GameCompletedWindow->objectName().isEmpty())
            GameCompletedWindow->setObjectName("GameCompletedWindow");
        GameCompletedWindow->resize(577, 328);
        ok_butt = new QPushButton(GameCompletedWindow);
        ok_butt->setObjectName("ok_butt");
        ok_butt->setGeometry(QRect(230, 240, 121, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Calibri")});
        font.setPointSize(12);
        ok_butt->setFont(font);
        label_2 = new QLabel(GameCompletedWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 130, 444, 33));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Calibri")});
        font1.setPointSize(20);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label = new QLabel(GameCompletedWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(1, 21, 574, 90));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        label->setPalette(palette);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Calibri")});
        font2.setPointSize(55);
        label->setFont(font2);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(GameCompletedWindow);

        QMetaObject::connectSlotsByName(GameCompletedWindow);
    } // setupUi

    void retranslateUi(QDialog *GameCompletedWindow)
    {
        GameCompletedWindow->setWindowTitle(QCoreApplication::translate("GameCompletedWindow", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        ok_butt->setToolTip(QCoreApplication::translate("GameCompletedWindow", "Continue", nullptr));
#endif // QT_CONFIG(tooltip)
        ok_butt->setText(QCoreApplication::translate("GameCompletedWindow", "Ok", nullptr));
        label_2->setText(QCoreApplication::translate("GameCompletedWindow", "Congratulations! You Finished the Game!", nullptr));
        label->setText(QCoreApplication::translate("GameCompletedWindow", " Game Completed! ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameCompletedWindow: public Ui_GameCompletedWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMECOMPLETEDWINDOW_H
