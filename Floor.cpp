
#include "Floor.h"

int Floor::nextFloor = 1;

Floor::Floor()
{
    floorNum = nextFloor;
    nextFloor++;
    upElevatorRequested = false;
    downElevatorRequested = false;
    numPassengers = 0;
}

Floor::~Floor(){
    for(int i = 0; i < passengerList.size(); i++){
        delete passengerList.at(i);
    }
}


vector<int> Floor::getPassengerNums(){
    vector<int> listof;
    for(int i = 0; i< passengerList.size(); i++){
        listof.push_back(passengerList.at(i)->getID());
    }
    return listof;
}

Passenger* Floor::getPassenger(int i){
    return passengerList.at(i);
}

void Floor::addPassenger(Passenger * p){
    passengerList.push_back(p);
    numPassengers++;
}

void Floor::removePassenger(Passenger * p){
    for(int i = 0; i < passengerList.size(); i++){
        if(passengerList.at(i)==p){
            passengerList.erase (passengerList.begin() + i);
            numPassengers--;
            return;
        }
    }
}

int Floor::getNumPassengers(){
    return numPassengers;
}

void Floor::PressDown(){
    downElevatorRequested = true;
}

void Floor::PressUp(){
    upElevatorRequested = true;
}

int Floor::getFloorNum(){
    return floorNum;
}
