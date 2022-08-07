#pragma once
#ifndef UI_TITLEBAR_H
#define UI_TITLEBAR_H
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMenuBar>

class Ui_TitleBar :
    public QFrame
{
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
private:
	QWidget* blankArea;
	QHBoxLayout* horizontalLayout;
	QSize sizeHint() const;
	void setup();
};
#endif

