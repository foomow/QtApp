#pragma execution_character_set("utf-8")
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
#include <QToolButton>
#include <QFrame>
#include <QLabel>
#include <QSplitter>
#include <iostream>

#include"Ui_TitleBar.h"
#include "Ui_TabPanel.h"
#include <QTextEdit>
#include <QMdiArea>

QT_BEGIN_NAMESPACE

class Ui_QtAppClass
{
public:
	QToolBar* mainToolBar;
	QWidget* centralWidget;
	QStatusBar* statusBar;
	QMdiArea* mainContent;
	Ui_TitleBar* titleBar; 
	Ui_TabPanel* leftTab;
	

	void setupUi(QMainWindow* QtAppClass)
	{
		if (QtAppClass->objectName().isEmpty())
			QtAppClass->setObjectName(QString::fromUtf8("QtAppClass"));
		QtAppClass->setWindowFlags(Qt::FramelessWindowHint);
		QtAppClass->resize(900, 600);
		centralWidget = new QWidget(QtAppClass);
		centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
		QtAppClass->setCentralWidget(centralWidget);

		QVBoxLayout* verticalLayout = new QVBoxLayout(centralWidget);
		verticalLayout->setSpacing(0);
		verticalLayout->setContentsMargins(0, 0, 0, 0);
		verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
		verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);

		titleBar = new Ui_TitleBar();
		titleBar->setObjectName(QString::fromUtf8("tittleBar"));
		titleBar->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);

		verticalLayout->addWidget(titleBar);

		mainToolBar = new QToolBar();
		mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
		mainToolBar->addAction(QIcon(":/QtApp/icons/icon_new.png"), "New(&N)");
		mainToolBar->addAction(QIcon(":/QtApp/icons/icon_open.png"), "Open(&O)");
		mainToolBar->addAction(QIcon(":/QtApp/icons/icon_save.png"), "Save(&S)");
		mainToolBar->addAction(QIcon(":/QtApp/icons/icon_del.png"), "Del(&D)");
		mainToolBar->addAction(QIcon(":/QtApp/icons/icon_play.png"), "Play(&P)");
		mainToolBar->addAction(QIcon(":/QtApp/icons/icon_edit.png"), "Edit(&E)");
		verticalLayout->addWidget(mainToolBar);

		mainContent = new QMdiArea();
		mainContent->setObjectName(QString::fromUtf8("mainContent"));
		mainContent->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
		mainContent->setBackground(QColor("#222c18"));
		
		/*QGridLayout* gridLayout = new QGridLayout(mainContent);
		gridLayout->setSpacing(1);

		leftTab = new Ui_TabPanel();		
		gridLayout->addWidget(leftTab, 0, 0);*/

		

		leftTab = new Ui_TabPanel;

		mainContent->addSubWindow(leftTab);

		

		verticalLayout->addWidget(mainContent);

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
