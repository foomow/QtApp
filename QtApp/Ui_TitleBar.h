#pragma once
#pragma execution_character_set("utf-8")
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
	Ui_TitleBar(bool hasmenu = true) :QFrame() {
		setup(hasmenu);
	};
	Ui_TitleBar(QWidget* parent, bool hasmenu = true) :QFrame(parent) {
		setup(hasmenu);
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
	void setup(bool hasmenu = true);
};
#endif

