#pragma once
#include <QTabWidget>
class Ui_TabPanel :
    public QTabWidget
{
public:
    Ui_TabPanel();
    ~Ui_TabPanel();
private:
    void setup();
};

