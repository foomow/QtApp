#include "Ui_TabPanel.h"

Ui_TabPanel::Ui_TabPanel()
{
	setup();
}

Ui_TabPanel::~Ui_TabPanel()
{
}

void Ui_TabPanel::setup()
{
	setObjectName(QString::fromUtf8("Ui_TabPanel"));
	setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);

	QWidget* summary = new QWidget();
	summary->setMinimumSize(300, 200);
	summary->setObjectName(QString::fromUtf8("tabpage"));
	summary->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
	QWidget* circute = new QWidget();
	circute->setMinimumSize(300, 200);
	circute->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
	circute->setObjectName(QString::fromUtf8("tabpage"));
	QWidget* device = new QWidget();
	device->setMinimumSize(300, 200);
	device->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
	device->setObjectName(QString::fromUtf8("tabpage"));
	addTab(summary, QString::fromUtf8("综合"));
	addTab(circute, QString::fromUtf8("回路"));
	addTab(device, QString::fromUtf8("设备"));
}

