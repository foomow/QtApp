#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <QMdiSubWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <QtWidgets/QMdiArea>
#include "Ui_TitleBar.h"
#include "Ui_TabPanel.h"


class QtApp : public QMainWindow
{
    Q_OBJECT

public:
    QtApp(QWidget *parent = nullptr);
    ~QtApp();

private:
    QToolBar* mainToolBar;
    QWidget* centralWidget;
    QStatusBar* statusBar;
    QMdiArea* mainContent;
    Ui_TitleBar* titleBar;
    Ui_TabPanel* leftTab;

    void setupUi();
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void maxButtonClicked();
    void minButtonClicked();
    void closeButtonClicked();
    void toolbarAction(bool checked = false);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
};
