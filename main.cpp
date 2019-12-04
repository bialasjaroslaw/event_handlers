#include "ui_Patients.h"
#include "ui_Settings.h"

#include "helpers.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Settings s(nullptr);
    s.show();
    return a.exec();
}
