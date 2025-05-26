#include "ECS.h"

ECS::ECS(int numElevators, int numFloors)
{
    floorNum = numFloors;
    elevatorNum = numElevators;

    for(int i = 0; i < numFloors; i++){
        floors.push_back(new Floor());
    }

    for(int i = 0; i < numElevators; i++){
        elevators.push_back(new Elevator(i+1));
    }
}



ECS::~ECS(){
    for(int i = 0; i < elevators.size(); i++){
        delete elevators.at(i);
    }

    for(int i = 0; i < floors.size(); i++){
        delete floors.at(i);
    }
}

void ECS::floorRequest(Request* r){
    dollOutRequest(r)->insertRequest(r);
}

Elevator* ECS::dollOutRequest(Request * rq){
    int reqfloor = rq->getFloor();
    vector<Elevator*> elevatorsInUse;
    vector<int> elevatorsInUseProx;
    vector<Elevator*> elevatorsNotInUse;
    vector<int> elevatorsNotInUseProx;
    int notInUseProx;
    int InUseSameDir;
    int InUseNotSameDir;

    for(int i = 0; i < elevators.size(); i++){
        if(elevators.at(i)->stationary()){elevatorsNotInUse.push_back(elevators.at(i));
            elevatorsNotInUseProx.push_back(abs(elevators.at(i)->getfloorNum() - reqfloor));
        }
        else{elevatorsInUse.push_back(elevators.at(i));
            elevatorsInUseProx.push_back(abs(elevators.at(i)->getfloorNum() - reqfloor));
        }
    }

    int notinuseProx = floorNum+1;
    int notinusebestindex;
    if(!elevatorsNotInUseProx.empty()){
        for(int i = 0; i < elevatorsNotInUseProx.size(); i++){
            if(notinuseProx > elevatorsNotInUseProx.at(i)){notinuseProx = elevatorsNotInUseProx.at(i); notinusebestindex = i;}
        }
    }

    //CASE: There are no used elevators
    if(elevatorsInUse.empty()){
        return elevatorsNotInUse.at(notinusebestindex);
    }
    int inusesamedirBestIndex;
    int inusesamedirProx = floorNum+1;
    for(int i = 0; i < elevatorsInUseProx.size(); i++){
        if(inusesamedirProx > elevatorsInUseProx.at(i) && elevatorsInUse.at(i)->getDirection()==directionalHelper(elevatorsInUse.at(i)->getfloorNum(),reqfloor)){inusesamedirProx = elevatorsInUseProx.at(i);inusesamedirBestIndex = i;}
    }
    int inusenotsamedirBestIndex;
    int usesnotsamedirProx = floorNum+1;
    for(int i = 0; i < elevatorsInUseProx.size(); i++){
        if(usesnotsamedirProx > elevatorsInUseProx.at(i) && elevatorsInUse.at(i)->getDirection()!=directionalHelper(elevatorsInUse.at(i)->getfloorNum(),reqfloor)){usesnotsamedirProx = elevatorsInUseProx.at(i);inusenotsamedirBestIndex = i;}
    }



    //CASE: there are only used direction positive elevators
    if(usesnotsamedirProx == floorNum+1 && elevatorsNotInUse.empty()){
        return elevatorsInUse.at(inusesamedirBestIndex);
    }
    //CASE: There is direction positive and unused
    if(usesnotsamedirProx == floorNum+1 && !elevatorsNotInUse.empty()){
        if(notInUseProx > 2*InUseSameDir){
            return elevatorsInUse.at(inusesamedirBestIndex);
        }
        else{
            return elevatorsInUse.at(notinusebestindex);
        }
    }
    //CASE: Therre are noo unused elevators.
    if(elevatorsNotInUseProx.empty()){
        //worst case
        if(inusesamedirProx == floorNum+1){
            return elevatorsInUse.at(inusenotsamedirBestIndex);
        }
        //just pick same direction
        else{
            return elevatorsInUse.at(inusesamedirBestIndex);
        }
    }
    return new Elevator(0);
}

void ECS::loadElevator(Elevator * el, Floor * fl){
    //Going through elevator to remove passengers that want to get off
    vector<Passenger*> p1;
    for(int i = 0; i < el->getNumPassengers(); i++){
        qDebug() << i;
        if(el->getPassenger(i)->getDesiredFloor()==fl->getFloorNum()){
            p1.push_back(el->getPassenger(i));
        }
    }
    for(int i = 0; i < p1.size(); i++){
        qDebug() << i;
        fl->addPassenger(p1.at(i));
        el->removePassenger(p1.at(i));
    }
    //Going through the floor to find passengers that want to go in that direction.
    //qDebug() << fl->getNumPassengers() << "passengers on floor " << fl->getFloorNum();
    vector<Passenger*> p2;
    for(int i = 0; i < fl->getNumPassengers(); i++){
        qDebug() << i << " dude " << fl->getPassenger(i)->getDesiredDirection() << el->getDirection() << el->activeRequests;
        if((fl->getPassenger(i)->getDesiredDirection()==el->getDirection() || el->activeRequests==1) && fl->getPassenger(i)->getDesiredFloor()!=-1){
            p2.push_back(fl->getPassenger(i));
        }
    }
    //qDebug() << "p2 size: " << p2.size();
    for(int i = 0; i < p2.size(); i++){
        //qDebug() << "AAdding request " << p2.at(i)->getDesiredFloor();

        el->addPassenger(p2.at(i));
        fl->removePassenger(p2.at(i));
        qDebug() << p2.at(i)->getDesiredFloor()<< " inserting request";
        el->insertRequest(new Request(floors.at(p2.at(i)->getDesiredFloor())));
    }
}



bool ECS::directionalHelper(int from, int to){
    if(from < to){return true;}
    else{return false;}
}

Floor* ECS::getFloorStats(int i){
    return floors.at(i);
}

void ECS::spawnPassenger(int i){
    Passenger* p = new Passenger(i);
    floors.at(i)->addPassenger(p);
    passengers.push_back(p);
    passengerNum++;
}

Elevator* ECS::getElevator(int i) {
    if (i >= 0 && i < elevatorNum) {
        return elevators.at(i);
    } else {
        return nullptr;
    }
}

Passenger* ECS::getPassenger(int i){
    if(i < passengers.size()){
        return passengers.at(i);
    }
    else{
        return nullptr;
    }
}


