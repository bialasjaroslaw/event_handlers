#include "helpers.h"
#include <QPushButton>
#include <QTimer>

#include "ui_Patients.h"
#include "ui_Settings.h"
#include <iostream>

using namespace std;

void Settings::eventHandler()
{
    cout << "EH" << endl;
}

Settings::Settings(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, [this](){
        this->close();
        auto* stagetwo = new Patients(this);
        stagetwo->show();
    });
    connect(tetra_grip_api::instance(), &tetra_grip_api::tetraGripEvent,this, &Settings::eventHandler);

}

Patients::Patients(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Patients)
{
    connect(tetra_grip_api::instance(), &tetra_grip_api::tetraGripEvent,this, &Patients::eventHandlerTwo);
}

void Patients::eventHandlerTwo()
{
    cout << "EH2" << endl;
}

tetra_grip_api::tetra_grip_api()
{
    QTimer::singleShot(5000, this, [this](){
        emit tetraGripEvent();
    });
}

tetra_grip_api* tetra_grip_api::instance()
{
    static tetra_grip_api ins;
    return &ins;
}
