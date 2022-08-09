#pragma once
#include <QMouseEvent>
#include <QPoint>
#include <QMdiSubWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <QtWidgets/QMdiArea>
#include "Ui_TabPanel.h"
class SubWin :
    public QMdiSubWindow
{
public:
    SubWin();
    ~SubWin();
private:
    Ui_TabPanel* leftTab;
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);


    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;

    int m_nMouseClick_X_offset;
    int m_nMouseClick_Y_offset;

};

