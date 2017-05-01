/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Mon May 1 00:21:45 2017
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QFrame *frameVideo;
    QVBoxLayout *verticalLayout;
    QFrame *frameSeek;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnMedia;
    QPushButton *btnPlay;
    QPushButton *btnStop;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnSet;
    QFrame *frameVolume;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(706, 312);
        Widget->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frameVideo = new QFrame(Widget);
        frameVideo->setObjectName(QString::fromUtf8("frameVideo"));
        frameVideo->setMinimumSize(QSize(291, 231));
        frameVideo->setFrameShape(QFrame::StyledPanel);
        frameVideo->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frameVideo, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frameSeek = new QFrame(Widget);
        frameSeek->setObjectName(QString::fromUtf8("frameSeek"));
        frameSeek->setMinimumSize(QSize(0, 16));
        frameSeek->setMaximumSize(QSize(16777215, 16));
        frameSeek->setFrameShape(QFrame::StyledPanel);
        frameSeek->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frameSeek);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnMedia = new QPushButton(Widget);
        btnMedia->setObjectName(QString::fromUtf8("btnMedia"));

        horizontalLayout->addWidget(btnMedia);

        btnPlay = new QPushButton(Widget);
        btnPlay->setObjectName(QString::fromUtf8("btnPlay"));
        btnPlay->setCheckable(true);

        horizontalLayout->addWidget(btnPlay);

        btnStop = new QPushButton(Widget);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));

        horizontalLayout->addWidget(btnStop);

        horizontalSpacer_2 = new QSpacerItem(37, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnSet = new QPushButton(Widget);
        btnSet->setObjectName(QString::fromUtf8("btnSet"));

        horizontalLayout->addWidget(btnSet);

        frameVolume = new QFrame(Widget);
        frameVolume->setObjectName(QString::fromUtf8("frameVolume"));
        frameVolume->setMinimumSize(QSize(120, 31));
        frameVolume->setMaximumSize(QSize(100, 30));
        frameVolume->setFrameShape(QFrame::StyledPanel);
        frameVolume->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frameVolume);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        btnMedia->setText(QApplication::translate("Widget", "\345\252\222\344\275\223\345\272\223", 0, QApplication::UnicodeUTF8));
        btnPlay->setText(QApplication::translate("Widget", "\346\222\255\346\224\276", 0, QApplication::UnicodeUTF8));
        btnStop->setText(QApplication::translate("Widget", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
        btnSet->setText(QApplication::translate("Widget", "\346\240\207\346\270\205", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
