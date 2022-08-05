#include "QtApp.h"

QtApp::QtApp(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_nMouseClick_X_Coordinate = -1;
	m_nMouseClick_Y_Coordinate = -1;
}

QtApp::~QtApp()
{}

void QtApp::mousePressEvent(QMouseEvent* event) {
	if (event->y() < 40)
	{
		m_nMouseClick_X_Coordinate = event->x();
		m_nMouseClick_Y_Coordinate = event->y();
	}
	else {
		m_nMouseClick_X_Coordinate = -1;
		m_nMouseClick_Y_Coordinate = -1;
	}
}

void QtApp::mouseMoveEvent(QMouseEvent* event) {
	if (m_nMouseClick_X_Coordinate > -1 && m_nMouseClick_Y_Coordinate > -1)
		move(event->globalX() - m_nMouseClick_X_Coordinate, event->globalY() - m_nMouseClick_Y_Coordinate);
}
