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
#include <iostream>

QT_BEGIN_NAMESPACE

class Ui_TitleBar :public QFrame {
public:
	Ui_TitleBar() :QFrame() {
		setup();
	};
	Ui_TitleBar(QWidget* parent) :QFrame(parent) {
		setup();
	};
	~Ui_TitleBar() {
	};
	QPushButton* maxButton;
	QPushButton* minButton;
	QPushButton* closeButton;
	QLabel* mainIconLabel;
	QIcon* mainIcon;
	QMenuBar* menuBar;
	QSize sizeHint() const
	{
		return QSize(0, 30);
	}
private:
	QHBoxLayout* horizontalLayout;
	void setup()
	{
		mainIcon = new QIcon(":/QtApp/icons/icon_main.png");
		mainIconLabel = new QLabel();
		mainIconLabel->setObjectName(QString::fromUtf8("mainIconLabel"));
		mainIconLabel->setPixmap(mainIcon->pixmap(QSize(15, 14)));

		menuBar = new QMenuBar();
		menuBar->setObjectName(QString::fromUtf8("menuBar"));
		QMenu* menu = menuBar->addMenu("文件(&F)");
		menu->addActions({ new QAction("新建"),new QAction("保存") ,new QAction("打开"), menu->addSeparator() ,new QAction("退出") });
		menu = menuBar->addMenu("工程(&P)");
		menu->addActions({ new QAction("启动"),new QAction("停止") ,new QAction("编辑") });
		menu = menuBar->addMenu("视图(&V)");
		menu->addActions({ new QAction("工程"),new QAction("监控") ,new QAction("统计"),new QAction("日志") });
		menu = menuBar->addMenu("帮助(&H)");
		menu->addActions({ new QAction("关于") });


		maxButton = new QPushButton(this);
		maxButton->setObjectName(QString::fromUtf8("maxButton"));
		maxButton->setToolTip(QString::fromUtf8("最大"));

		minButton = new QPushButton(this);
		minButton->setObjectName(QString::fromUtf8("minButton"));
		minButton->setToolTip(QString::fromUtf8("最小"));

		closeButton = new QPushButton(this);
		closeButton->setObjectName(QString::fromUtf8("closeButton"));
		closeButton->setToolTip(QString::fromUtf8("关闭"));


		horizontalLayout = new QHBoxLayout(this);
		horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
		horizontalLayout->setSpacing(0);
		horizontalLayout->setContentsMargins(0, 0, 0, 0);
		horizontalLayout->setAlignment(Qt::AlignRight);
		horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);

		horizontalLayout->addWidget(mainIconLabel);
		horizontalLayout->addWidget(menuBar);
		horizontalLayout->addWidget(maxButton);
		horizontalLayout->addWidget(minButton);
		horizontalLayout->addWidget(closeButton);
	}

};


class Ui_QtAppClass
{
public:
	QToolBar* mainToolBar;
	QWidget* centralWidget;
	QStatusBar* statusBar;
	QVBoxLayout* verticalLayout;
	QWidget* mainContent;
	Ui_TitleBar* titleBar;

	void setupUi(QMainWindow* QtAppClass)
	{
		if (QtAppClass->objectName().isEmpty())
			QtAppClass->setObjectName(QString::fromUtf8("QtAppClass"));
		QtAppClass->setWindowFlags(Qt::FramelessWindowHint);
		QtAppClass->resize(900, 600);
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

		mainContent = new QWidget();
		mainContent->setObjectName(QString::fromUtf8("mainContent"));
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
