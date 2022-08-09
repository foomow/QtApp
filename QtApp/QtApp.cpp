#include<iostream>
#include "QtApp.h"

QtApp::QtApp(QWidget* parent)
	: QMainWindow(parent)
{
	m_nMouseClick_X_Coordinate = -1;
	m_nMouseClick_Y_Coordinate = -1;
	setupUi();
	QObject::connect(titleBar->maxButton, &QPushButton::clicked, [=]() {
		emit maxButtonClicked();
		}
	);
	QObject::connect(titleBar->minButton, &QPushButton::clicked, [=]() {
		emit minButtonClicked();
		}
	);
	QObject::connect(titleBar->closeButton, &QPushButton::clicked, [=]() {
		emit closeButtonClicked();
		}
	);
}

QtApp::~QtApp()
{
}

void QtApp::setupUi()
{
	setObjectName(QString::fromUtf8("QtAppClass"));
	setWindowFlags(Qt::FramelessWindowHint);
	resize(900, 600);
	centralWidget = new QWidget(this);
	centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
	setCentralWidget(centralWidget);

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
	mainToolBar->addAction(QIcon(":/QtApp/icons/icon_new.png"), "New(&N)",this, &QtApp::toolbarAction);
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

	leftTab = new Ui_TabPanel;

	mainContent->addSubWindow(leftTab,Qt::WindowType::FramelessWindowHint);



	verticalLayout->addWidget(mainContent);

	statusBar = new QStatusBar(this);
	statusBar->setObjectName(QString::fromUtf8("statusBar"));
	setStatusBar(statusBar);
}

void QtApp::mousePressEvent(QMouseEvent* event) {
	m_nMouseClick_X_Coordinate = event->x();
	m_nMouseClick_Y_Coordinate = event->y();
}

void QtApp::mouseMoveEvent(QMouseEvent* event) {
	if (m_nMouseClick_X_Coordinate > -1 && m_nMouseClick_Y_Coordinate > -1)
		move(event->globalX() - m_nMouseClick_X_Coordinate, event->globalY() - m_nMouseClick_Y_Coordinate);
}

void QtApp::maxButtonClicked()
{
	if (windowState() & Qt::WindowState::WindowMaximized)
		setWindowState(Qt::WindowState::WindowNoState);
	else
		setWindowState(Qt::WindowState::WindowMaximized);

}

void QtApp::minButtonClicked()
{
	setWindowState(Qt::WindowState::WindowMinimized);
}

void QtApp::closeButtonClicked()
{
	close();
}

void QtApp::toolbarAction(bool checked)
{
	mainContent->grab().save("aaa.png","png");
}
