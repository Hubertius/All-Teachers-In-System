#include "View/loginwindow.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    HubertiusNamespace::LoginWindow w;
    w.show();
    return a.exec();
}
