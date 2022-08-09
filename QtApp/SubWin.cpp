#include "SubWin.h"

SubWin::SubWin()
{
	m_nMouseClick_X_Coordinate = -1;
	m_nMouseClick_Y_Coordinate = -1;
	m_nMouseClick_X_offset = -1;
	m_nMouseClick_Y_offset = -1;
	setObjectName(QString::fromUtf8("SubWin"));
	setWindowFlags(Qt::FramelessWindowHint);
	leftTab = new Ui_TabPanel(this);

}

SubWin::~SubWin()
{
}

void SubWin::mousePressEvent(QMouseEvent* event) {
	m_nMouseClick_X_Coordinate = event->x();
	m_nMouseClick_Y_Coordinate = event->y();
	if (m_nMouseClick_X_Coordinate == -1 && m_nMouseClick_Y_Coordinate == -1)
	{
		m_nMouseClick_X_offset = pos().x();
		m_nMouseClick_Y_offset = pos().y();
	}
}

void SubWin::mouseReleaseEvent(QMouseEvent* event) {
	m_nMouseClick_X_Coordinate = -1;
	m_nMouseClick_Y_Coordinate = -1;
}

void SubWin::mouseMoveEvent(QMouseEvent* event) {
	if (m_nMouseClick_X_Coordinate > -1 && m_nMouseClick_Y_Coordinate > -1)
		move(m_nMouseClick_X_offset + event->x() - m_nMouseClick_X_Coordinate, m_nMouseClick_Y_offset + event->y() - m_nMouseClick_Y_Coordinate);
}