#include<iostream>
#include "QtApp.h"

QtApp::QtApp(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.titleBar->maxButton, &QPushButton::clicked, [=]() {
		emit maxButtonClicked();
		}
	);
	QObject::connect(ui.titleBar->minButton, &QPushButton::clicked, [=]() {
		emit minButtonClicked();
		}
	);
	QObject::connect(ui.titleBar->closeButton, &QPushButton::clicked, [=]() {
		emit closeButtonClicked();
		}
	);
	m_nMouseClick_X_Coordinate = -1;
	m_nMouseClick_Y_Coordinate = -1;
}

QtApp::~QtApp()
{}

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
