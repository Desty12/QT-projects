/********************************************************************************
** Form generated from reading UI file 'wincalculator.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINCALCULATOR_H
#define UI_WINCALCULATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_winCalculatorClass
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *addBtn;
    QPushButton *oneBtn;
    QLabel *showLab;
    QPushButton *fourBtn;
    QPushButton *clearBtn;
    QPushButton *fiveBtn;
    QPushButton *sevenBtn;
    QPushButton *delBtn;
    QPushButton *multiBtn;
    QPushButton *twoBtn;
    QPushButton *eightBtn;
    QPushButton *sixBtn;
    QPushButton *threeBtn;
    QPushButton *nineBtn;
    QPushButton *divBtn;
    QPushButton *subBtn;
    QPushButton *zeroBtn;
    QPushButton *equalBtn;
    QPushButton *pointBtn;
    QPushButton *surplusBtn;
    QLabel *showResult;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *winCalculatorClass)
    {
        if (winCalculatorClass->objectName().isEmpty())
            winCalculatorClass->setObjectName(QString::fromUtf8("winCalculatorClass"));
        winCalculatorClass->resize(600, 400);
        centralWidget = new QWidget(winCalculatorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 0, 571, 341));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        addBtn = new QPushButton(gridLayoutWidget);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        QFont font;
        font.setPointSize(14);
        addBtn->setFont(font);

        gridLayout_2->addWidget(addBtn, 3, 3, 1, 1);

        oneBtn = new QPushButton(gridLayoutWidget);
        oneBtn->setObjectName(QString::fromUtf8("oneBtn"));
        oneBtn->setFont(font);

        gridLayout_2->addWidget(oneBtn, 3, 0, 1, 1);

        showLab = new QLabel(gridLayoutWidget);
        showLab->setObjectName(QString::fromUtf8("showLab"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\344\271\246\345\256\213\347\256\200\344\275\223"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        showLab->setFont(font1);
        showLab->setLayoutDirection(Qt::RightToLeft);
        showLab->setTextFormat(Qt::AutoText);
        showLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        showLab->setMargin(20);

        gridLayout_2->addWidget(showLab, 0, 0, 1, 4);

        fourBtn = new QPushButton(gridLayoutWidget);
        fourBtn->setObjectName(QString::fromUtf8("fourBtn"));
        fourBtn->setFont(font);

        gridLayout_2->addWidget(fourBtn, 4, 0, 1, 1);

        clearBtn = new QPushButton(gridLayoutWidget);
        clearBtn->setObjectName(QString::fromUtf8("clearBtn"));
        clearBtn->setFont(font);

        gridLayout_2->addWidget(clearBtn, 2, 0, 1, 1);

        fiveBtn = new QPushButton(gridLayoutWidget);
        fiveBtn->setObjectName(QString::fromUtf8("fiveBtn"));
        fiveBtn->setFont(font);

        gridLayout_2->addWidget(fiveBtn, 4, 1, 1, 1);

        sevenBtn = new QPushButton(gridLayoutWidget);
        sevenBtn->setObjectName(QString::fromUtf8("sevenBtn"));
        sevenBtn->setFont(font);

        gridLayout_2->addWidget(sevenBtn, 5, 0, 1, 1);

        delBtn = new QPushButton(gridLayoutWidget);
        delBtn->setObjectName(QString::fromUtf8("delBtn"));
        delBtn->setFont(font);

        gridLayout_2->addWidget(delBtn, 2, 1, 1, 1);

        multiBtn = new QPushButton(gridLayoutWidget);
        multiBtn->setObjectName(QString::fromUtf8("multiBtn"));
        multiBtn->setFont(font);

        gridLayout_2->addWidget(multiBtn, 2, 2, 1, 1);

        twoBtn = new QPushButton(gridLayoutWidget);
        twoBtn->setObjectName(QString::fromUtf8("twoBtn"));
        twoBtn->setFont(font);

        gridLayout_2->addWidget(twoBtn, 3, 1, 1, 1);

        eightBtn = new QPushButton(gridLayoutWidget);
        eightBtn->setObjectName(QString::fromUtf8("eightBtn"));
        eightBtn->setFont(font);

        gridLayout_2->addWidget(eightBtn, 5, 1, 1, 1);

        sixBtn = new QPushButton(gridLayoutWidget);
        sixBtn->setObjectName(QString::fromUtf8("sixBtn"));
        sixBtn->setFont(font);

        gridLayout_2->addWidget(sixBtn, 4, 2, 1, 1);

        threeBtn = new QPushButton(gridLayoutWidget);
        threeBtn->setObjectName(QString::fromUtf8("threeBtn"));
        threeBtn->setFont(font);

        gridLayout_2->addWidget(threeBtn, 3, 2, 1, 1);

        nineBtn = new QPushButton(gridLayoutWidget);
        nineBtn->setObjectName(QString::fromUtf8("nineBtn"));
        nineBtn->setFont(font);

        gridLayout_2->addWidget(nineBtn, 5, 2, 1, 1);

        divBtn = new QPushButton(gridLayoutWidget);
        divBtn->setObjectName(QString::fromUtf8("divBtn"));
        divBtn->setFont(font);

        gridLayout_2->addWidget(divBtn, 2, 3, 1, 1);

        subBtn = new QPushButton(gridLayoutWidget);
        subBtn->setObjectName(QString::fromUtf8("subBtn"));
        subBtn->setFont(font);

        gridLayout_2->addWidget(subBtn, 4, 3, 1, 1);

        zeroBtn = new QPushButton(gridLayoutWidget);
        zeroBtn->setObjectName(QString::fromUtf8("zeroBtn"));
        zeroBtn->setFont(font);

        gridLayout_2->addWidget(zeroBtn, 6, 0, 1, 1);

        equalBtn = new QPushButton(gridLayoutWidget);
        equalBtn->setObjectName(QString::fromUtf8("equalBtn"));
        equalBtn->setMinimumSize(QSize(0, 60));
        equalBtn->setFont(font);

        gridLayout_2->addWidget(equalBtn, 5, 3, 2, 1);

        pointBtn = new QPushButton(gridLayoutWidget);
        pointBtn->setObjectName(QString::fromUtf8("pointBtn"));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        pointBtn->setFont(font2);

        gridLayout_2->addWidget(pointBtn, 6, 1, 1, 1);

        surplusBtn = new QPushButton(gridLayoutWidget);
        surplusBtn->setObjectName(QString::fromUtf8("surplusBtn"));
        surplusBtn->setFont(font);

        gridLayout_2->addWidget(surplusBtn, 6, 2, 1, 1);

        showResult = new QLabel(gridLayoutWidget);
        showResult->setObjectName(QString::fromUtf8("showResult"));
        showResult->setMaximumSize(QSize(16777215, 50));
        showResult->setFont(font1);
        showResult->setLayoutDirection(Qt::LeftToRight);
        showResult->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        showResult->setMargin(10);

        gridLayout_2->addWidget(showResult, 1, 0, 1, 4);

        winCalculatorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(winCalculatorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        winCalculatorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(winCalculatorClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        winCalculatorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(winCalculatorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        winCalculatorClass->setStatusBar(statusBar);

        retranslateUi(winCalculatorClass);

        QMetaObject::connectSlotsByName(winCalculatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *winCalculatorClass)
    {
        winCalculatorClass->setWindowTitle(QApplication::translate("winCalculatorClass", "winCalculator", 0, QApplication::UnicodeUTF8));
        addBtn->setText(QApplication::translate("winCalculatorClass", "+", 0, QApplication::UnicodeUTF8));
        oneBtn->setText(QApplication::translate("winCalculatorClass", "1", 0, QApplication::UnicodeUTF8));
        showLab->setText(QApplication::translate("winCalculatorClass", "0", 0, QApplication::UnicodeUTF8));
        fourBtn->setText(QApplication::translate("winCalculatorClass", "4", 0, QApplication::UnicodeUTF8));
        clearBtn->setText(QApplication::translate("winCalculatorClass", "\346\270\205\351\231\244", 0, QApplication::UnicodeUTF8));
        fiveBtn->setText(QApplication::translate("winCalculatorClass", "5", 0, QApplication::UnicodeUTF8));
        sevenBtn->setText(QApplication::translate("winCalculatorClass", "7", 0, QApplication::UnicodeUTF8));
        delBtn->setText(QApplication::translate("winCalculatorClass", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        multiBtn->setText(QApplication::translate("winCalculatorClass", "*", 0, QApplication::UnicodeUTF8));
        twoBtn->setText(QApplication::translate("winCalculatorClass", "2", 0, QApplication::UnicodeUTF8));
        eightBtn->setText(QApplication::translate("winCalculatorClass", "8", 0, QApplication::UnicodeUTF8));
        sixBtn->setText(QApplication::translate("winCalculatorClass", "6", 0, QApplication::UnicodeUTF8));
        threeBtn->setText(QApplication::translate("winCalculatorClass", "3", 0, QApplication::UnicodeUTF8));
        nineBtn->setText(QApplication::translate("winCalculatorClass", "9", 0, QApplication::UnicodeUTF8));
        divBtn->setText(QApplication::translate("winCalculatorClass", "/", 0, QApplication::UnicodeUTF8));
        subBtn->setText(QApplication::translate("winCalculatorClass", "-", 0, QApplication::UnicodeUTF8));
        zeroBtn->setText(QApplication::translate("winCalculatorClass", "0", 0, QApplication::UnicodeUTF8));
        equalBtn->setText(QApplication::translate("winCalculatorClass", "=", 0, QApplication::UnicodeUTF8));
        pointBtn->setText(QApplication::translate("winCalculatorClass", ".", 0, QApplication::UnicodeUTF8));
        surplusBtn->setText(QApplication::translate("winCalculatorClass", "%", 0, QApplication::UnicodeUTF8));
        showResult->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class winCalculatorClass: public Ui_winCalculatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINCALCULATOR_H
