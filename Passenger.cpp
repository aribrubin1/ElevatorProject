#include "Passenger.h"

int Passenger::nextID = 1;

Passenger::Passenger(int spawnFloor)
{
    passengerID = nextID;
    nextID++;
    currentFloor = spawnFloor;
}

int Passenger::getID(){
    return passengerID;
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
