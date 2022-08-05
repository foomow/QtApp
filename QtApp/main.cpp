#include "QtApp.h"
#include <QtWidgets/QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile styleFile("style.qss");
    styleFile.open(QIODevice::ReadOnly);
    QByteArray content;

    while (!styleFile.atEnd()) {
        content = styleFile.readAll();
    }

    styleFile.close();

    QtApp w;
    w.setStyleSheet(content);

    w.show();
    return a.exec();
}
