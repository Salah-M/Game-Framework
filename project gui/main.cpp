#include "mainwidget.h"
#include "signupwidget.h"
#include <QApplication>
#include <QPushButton>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWidget W;
    W.show();


    return a.exec();
}
