#pragma once
#pragma execution_character_set("utf-8")
#include <QTabWidget>
class Ui_TabPanel :
    public QTabWidget
{
public:
    Ui_TabPanel();
    Ui_TabPanel(QWidget* parent) :QTabWidget(parent) {
        setup();
    }
    ~Ui_TabPanel();
private:
    void setup();
};

