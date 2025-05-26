#include "Elevator.h"
#include "Request.h"
#include "Passenger.h"
#include<unistd.h>
#include "QDebug"
int Elevator::nextID = 1;

Elevator::Elevator(int fl)
{
    elevatorID = nextID;
    nextID++;
    direction = true;
    currentAudioMessage = "";
    currentVisualMessage = "";
    doorOpen = false;
    doortimer = -1;
    currentFloor = fl;
    numPassengers = 0;
    currentRequest = nullptr;
    activeRequests = 0;
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

void Elevator::insertRequest(Request* rq){
    activeRequests++;
    if(currentRequest==nullptr){
        qDebug() << "Request " <<rq->getFloor() <<" inserted sucessfully";
        currentRequest = rq;
        if(rq->getFloor() > currentFloor){direction = true;}
        else if(rq->getFloor() < currentFloor){direction = false;}
        return;
    }

    if(rq->getFloor() > currentFloor){
        direction = true;
        if(upFloorRequests.empty()){upFloorRequests.push_back(rq);}
        for(int i = 0; i < upFloorRequests.size(); i++){
            if(upFloorRequests.at(i)->getFloor() > rq->getFloor()){
                qDebug() << "Request inserted sucessfully";
                upFloorRequests.insert(upFloorRequests.begin() + i,rq);
            }
        }
    }
    else if(rq->getFloor() < currentFloor){
        direction = false;
        if(upFloorRequests.empty()){downFloorRequests.push_back(rq);qDebug() << "Request inserted sucessfully";}
        for(int i = 0; i < downFloorRequests.size(); i++){
            if(downFloorRequests.at(i)->getFloor() > rq->getFloor()){
                qDebug() << "Request inserted sucessfully";
                downFloorRequests.insert(downFloorRequests.begin() + i,rq);
            }
        }
    }
    else{

    }
}

void Elevator::addPassenger(Passenger* p){
    passengers.push_back(p);
    numPassengers++;
}

void Elevator::removePassenger(Passenger* p){
    for(int i = 0; i < passengers.size(); i++){
        if(passengers.at(i)==p){
            passengers.erase (passengers.begin() + i);
            numPassengers--;
            return;
        }
    }
}

bool Elevator::stationary(){
    return (currentRequest == nullptr);
}

int Elevator::getDesiredFloor(){
    if(currentRequest==nullptr){return -1;}
    return currentRequest->getFloor();
}

void Elevator::loadNextRequest(){
    activeRequests--;
    if(upFloorRequests.empty() && downFloorRequests.empty()){
        currentRequest = nullptr;
        return;
    }
    if(direction==true){
        if(upFloorRequests.empty()){
            direction = false;
            currentRequest = downFloorRequests.at(0);
            downFloorRequests.erase(downFloorRequests.begin());
            }
        else{
            currentRequest = upFloorRequests.at(0);
            upFloorRequests.erase(upFloorRequests.begin());
        }
    }

    else{
        if(downFloorRequests.empty()){
            direction = true;
            currentRequest = upFloorRequests.at(0);
            upFloorRequests.erase(upFloorRequests.begin());
        }
        else{
            currentRequest = downFloorRequests.at(0);
            downFloorRequests.erase(downFloorRequests.begin());
        }
    }

}

Passenger* Elevator::getPassenger(int i){
    return passengers.at(i);
}

int Elevator::getfloorNum(){
    return currentFloor;
}

bool Elevator::getDirection(){
    return direction;
}

vector<int> Elevator::getPassengerList(){
    vector<int> listof;
    for(int i = 0; i< passengers.size(); i++){
        listof.push_back(passengers.at(i)->getID());
    }
    return listof;
}

bool Elevator::isAtDesiredFloor(){
    if(currentRequest==nullptr){
        return false;
    }

    return (currentRequest->getFloor()== currentFloor);
}

int Elevator::getNumPassengers(){
    return numPassengers;
}

void Elevator::sendAudioMessage(string){

}

void Elevator::sendVisualMessage(string){

}

void Elevator::countdown(){

}

void Elevator::moveUp(){
    currentFloor++;
}

void Elevator::moveDown(){
    currentFloor--;
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
