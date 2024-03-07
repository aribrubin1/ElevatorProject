
#include "Floor.h"

int Floor::nextFloor = 1;

Floor::Floor()
{
    floorNum = nextFloor;
    nextFloor++;
    upElevatorRequested = false;
    downElevatorRequested = false;
}

Floor::~Floor(){
    for(int i = 0; i < passengerList.size(); i++){
        delete passengerList.at(i);
    }
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
