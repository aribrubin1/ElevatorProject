#include "ElevatorThread.h"
#include "qdebug.h"

ElevatorThread::ElevatorThread(Elevator *elevator, ECS *ecs, QObject *parent) : QThread(parent), elevator(elevator), ecs(ecs) {stopped = false;}

void ElevatorThread::run(){
        while (!stopped) {
            if (!elevator->stationary()) {
                loadUnloadPassengers();
                handleFloorRequests();
                //Elevator moves up or down
                if(!elevator->stationary()){
                    if(elevator->getDirection()){
                        qDebug() << "Going up";
                        elevator->moveUp();
                    }
                    else{
                        qDebug() << "Going down";
                        elevator->moveDown();
                    }
                }
                qDebug() << ecs->getFloorStats(4)->getPassengerNums().size() << " Floor 4 size";

            }
            msleep(1000);
        }
    }

void ElevatorThread::stopThread(){
    stopped=true;
}

void ElevatorThread::handleFloorRequests(){
    if(elevator->isAtDesiredFloor()){
        elevator->loadNextRequest();
        qDebug() << "Going to " << elevator->getDesiredFloor();
    }
}


void ElevatorThread::loadUnloadPassengers(){
    if(elevator->isAtDesiredFloor()){
        qDebug()<<elevator->getfloorNum()<< " Floornum";
        ecs->loadElevator(elevator,ecs->getFloorStats(elevator->getfloorNum()-1));

    }
    emit onChanged();

}
