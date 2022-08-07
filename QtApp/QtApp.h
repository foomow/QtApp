#pragma once

#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include "ui.h"

class QtApp : public QMainWindow
{
    Q_OBJECT

public:
    QtApp(QWidget *parent = nullptr);
    ~QtApp();

private:
    Ui::QtAppClass ui;
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void maxButtonClicked();
    void minButtonClicked();
    void closeButtonClicked();
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
};
