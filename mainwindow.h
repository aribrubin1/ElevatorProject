#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ECS.h"
#include "ElevatorThread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_elevator_selector_1_currentIndexChanged(const QString &arg1);

    void on_elevator_selector_2_currentIndexChanged(const QString &arg1);

    void on_elevator_selector_3_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_SPsend_clicked();

    void updateDisplays();

private:
    Ui::MainWindow *ui;
    void onStartup();
    ECS* ecs;
    void resetTable();
    vector<ElevatorThread*> elevatorThreads;

};
#endif // MAINWINDOW_H
