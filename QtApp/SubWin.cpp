#include<QDebug>
#include "SubWin.h"

SubWin::SubWin()
{
	oldpos_win = QPoint(-1, -1);
	oldpos_mouse = QPoint(-1, -1);
	setObjectName(QString::fromUtf8("SubWin"));
	setWindowFlags(Qt::FramelessWindowHint);
	leftTab = new Ui_TabPanel(this);
}

SubWin::~SubWin()
{
}

void SubWin::mousePressEvent(QMouseEvent* event) {

	if (oldpos_win == QPoint(-1, -1)) {
		oldpos_win = pos();
		oldpos_mouse = event->pos();
	}
}

void SubWin::mouseReleaseEvent(QMouseEvent* event) {
	oldpos_win = QPoint(-1, -1);
	oldpos_mouse = QPoint(-1, -1);
}

void SubWin::mouseMoveEvent(QMouseEvent* event) {
	if (oldpos_win != QPoint(-1, -1)) {
		move(oldpos_win + event->pos() - oldpos_mouse);
	}
}