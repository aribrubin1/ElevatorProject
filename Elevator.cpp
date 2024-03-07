#include "Elevator.h"
#include "Request.h"
#include "Passenger.h"

int Elevator::nextID = 1;

Elevator::Elevator(Floor* fl)
{
    elevatorID = nextID;
    nextID++;
    stationary = true;
    direction = true;
    currentAudioMessage = "";
    currentVisualMessage = "";
    doorOpen = false;
    doortimer = -1;
    currentfloor = fl;
}

Elevator::~Elevator(){
    for(int i = 0; i < upFloorRequests.size(); i++){
        delete upFloorRequests.at(i);
    }
    for(int i = 0; i < downFloorRequests.size(); i++){
        delete downFloorRequests.at(i);
    }
    for(int i = 0; i < passengers.size(); i++){
        delete passengers.at(i);
    }
}

int Elevator::getfloorNum(){
    return currentfloor->getFloorNum();
}

vector<int> Elevator::getPassengerList(){
    vector<int> listof;
    for(int i = 0; i< passengers.size(); i++){
        listof.push_back(passengers.at(i)->getID());
    }
}

void Elevator::sendAudioMessage(string){

}

void Elevator::sendVisualMessage(string){

}

void Elevator::countdown(){

}

void Elevator::moveUp(){

}

void Elevator::moveDown(){

}

void Elevator::handleHelp(){

}

void Elevator::receiveHelp(){

}

void Elevator::fireAlarm(){

}

void Elevator::powerOutage(){

}

void Elevator::bellRing(){

}

void Elevator::updateFloorNum(int newnum){

}
