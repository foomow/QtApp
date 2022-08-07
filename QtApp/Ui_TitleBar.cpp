#include"Ui_TitleBar.h"
QSize Ui_TitleBar::sizeHint() const
{
	return QSize(0, 30);
}
void Ui_TitleBar::setup()
{
	mainIcon = new QIcon(":/QtApp/icons/icon_main.png");
	mainIconLabel = new QLabel();
	mainIconLabel->setObjectName(QString::fromUtf8("mainIconLabel"));
	mainIconLabel->setPixmap(mainIcon->pixmap(QSize(15, 14)));

	menuBar = new QMenuBar();
	menuBar->setObjectName(QString::fromUtf8("menuBar"));
	menuBar->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
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

	blankArea = new QWidget();
	blankArea->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
	horizontalLayout->addWidget(mainIconLabel);
	horizontalLayout->addWidget(menuBar);
	horizontalLayout->addWidget(blankArea);
	horizontalLayout->addWidget(maxButton);
	horizontalLayout->addWidget(minButton);
	horizontalLayout->addWidget(closeButton);
}