#include "Passenger.h"

int Passenger::nextID = 1;

Passenger::Passenger(int spawnFloor)
{
    passengerID = nextID;
    nextID++;
    currentFloor = spawnFloor;
    desiredFloor = -1;
    desiredDirection = true;
}

int Passenger::getID(){
    return passengerID;
}

int Passenger::getCurrentFloor(){
    return currentFloor;
}

int Passenger::getDesiredFloor(){
    return desiredFloor;
}

bool Passenger::getDesiredDirection(){
    return desiredDirection;
}

void Passenger::setDesiredFloor(int i){
    desiredFloor = i;
    if(i < currentFloor){
        desiredDirection = false;
    }
    else if (i > currentFloor){
        desiredDirection = true;
    }
}

Passenger::~Passenger(){

}

void Passenger::enterFloor(){

}

void Passenger::exitFloor(){

}

void Passenger::requestDown(){

}

void Passenger::requestUp(){

}
