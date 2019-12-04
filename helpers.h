#ifndef HELPERS_H
#define HELPERS_H

#include <QObject>
#include <QMainWindow>

namespace Ui {
    class Patients;
    class Settings;
}

class tetra_grip_api : public QObject
{
    Q_OBJECT
public:
    tetra_grip_api();
    static tetra_grip_api* instance();

    signals:
    tetraGripEvent();
};

class Settings : public QMainWindow
{
    Q_OBJECT
    Ui::Settings* ui;
public:
    Settings(QWidget *parent);
    public slots:
    void eventHandler();
};



class Patients : public QMainWindow
{
    Q_OBJECT
    Ui::Patients* ui;
public:
    Patients(QWidget *parent);
public slots:
    void eventHandlerTwo();
};



#endif // HELPERS_H
