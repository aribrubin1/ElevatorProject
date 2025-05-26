#ifndef ELEVATORTHREAD_H
#define ELEVATORTHREAD_H
#include "ECS.h"
#include "Elevator.h"
#include <QThread>


class ElevatorThread : public QThread
{
    private:
        void handleFloorRequests();

        void loadUnloadPassengers();

        Elevator *elevator;
        ECS *ecs;
        bool stopped = false;


    Q_OBJECT
    public:
        ElevatorThread(Elevator *elevator, ECS *ecs, QObject *parent = nullptr);
        void run() override;
        void stopThread();

    signals:
        void onChanged();


};

#endif // ELEVATORTHREAD_H
