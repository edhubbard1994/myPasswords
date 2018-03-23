#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include "start.h"

bool authenticateLogin;
QString loggedInUser;

int main(int argc, char *argv[])
{
    authenticateLogin=false;
    QApplication a(argc, argv);
    QGuiApplication::setQuitOnLastWindowClosed(true);

    start loginMenu;
    loginMenu.setModal(false);
    loginMenu.setWindowFlags(Qt::WindowStaysOnTopHint);
    loginMenu.exec();

    MainWindow w;
    w.show();


    return a.exec();
}
