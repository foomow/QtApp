#ifndef UI_QTAPP_H
#define UI_QTAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFrame>
#include <QLabel>
#include <iostream>

QT_BEGIN_NAMESPACE

class Ui_TitleBar:public QFrame {
public:
    Ui_TitleBar() :QFrame() {
    };
    Ui_TitleBar(QWidget* parent):QFrame(parent) {
    };
    ~Ui_TitleBar() {
    };
    QSize sizeHint() const
    {
        return QSize(0, 30);
    }
};


class Ui_QtAppClass
{
public:
    QMenuBar* menuBar;
    QToolBar* mainToolBar;
    QWidget* centralWidget;
    QStatusBar* statusBar;
    QVBoxLayout* verticalLayout;
    QHBoxLayout* horizontalLayout;
    QPushButton* maxButton;
    QPushButton* minButton;
    QPushButton* closeButton;
    Ui_TitleBar* titleBar;
    QLabel* titleLabel;

    void setupUi(QMainWindow* QtAppClass)
    {
        if (QtAppClass->objectName().isEmpty())
            QtAppClass->setObjectName(QString::fromUtf8("QtAppClass"));
        QtAppClass->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowType::WindowStaysOnTopHint);
        QtAppClass->resize(900, 600);
        /*menuBar = new QMenuBar(QtAppClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QtAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtAppClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtAppClass->addToolBar(mainToolBar);*/
        centralWidget = new QWidget(QtAppClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtAppClass->setCentralWidget(centralWidget);

        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);

        titleBar = new Ui_TitleBar();
        titleBar->setObjectName(QString::fromUtf8("tittleBar"));
        titleBar->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        maxButton = new QPushButton(titleBar);
        maxButton->setObjectName(QString::fromUtf8("maxButton"));
        maxButton->setToolTip(QString::fromUtf8("最大"));
        minButton = new QPushButton(titleBar);
        minButton->setObjectName(QString::fromUtf8("minButton"));
        minButton->setToolTip(QString::fromUtf8("最小"));
        closeButton = new QPushButton(titleBar);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setToolTip(QString::fromUtf8("关闭"));
        titleLabel = new QLabel(titleBar);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setText(QString::fromUtf8("RSC 电能质量监控系统"));
        titleLabel->setAlignment(Qt::AlignLeft);
        titleLabel->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);

        verticalLayout->addWidget(titleBar);

        horizontalLayout = new QHBoxLayout(titleBar);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setAlignment(Qt::AlignRight);
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout->addWidget(titleLabel);
        horizontalLayout->addWidget(maxButton);
        horizontalLayout->addWidget(minButton);
        horizontalLayout->addWidget(closeButton);

        statusBar = new QStatusBar(QtAppClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtAppClass->setStatusBar(statusBar);

        retranslateUi(QtAppClass);

        QMetaObject::connectSlotsByName(QtAppClass);
    } // setupUi

    void retranslateUi(QMainWindow* QtAppClass)
    {
        QtAppClass->setWindowTitle(QCoreApplication::translate("QtAppClass", "QtApp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtAppClass : public Ui_QtAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTAPP_H
