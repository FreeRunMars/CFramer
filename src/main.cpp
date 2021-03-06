#include "Logger.h"
#include "logmanager.h"
#include "cmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LogManager::instance()->debug_log_console_on();
    CMainWindow w;
    w.show();

    return a.exec();
}
