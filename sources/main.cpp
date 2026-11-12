#include "../headers/mainwindow.h"
// #include "../headers/advertisingCampaign.h"
// #include "../headers/budget.h"
// #include "../headers/client.h"
// #include "../headers/date.h"
// #include "../headers/designService.h"
// #include "../headers/service.h"
// #include "../headers/specialist.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return QApplication::exec();
}
