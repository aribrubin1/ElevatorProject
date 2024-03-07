#include "Request.h"

Request::Request(Floor* floorvar, bool dir)
{
    floor = floorvar;
    direction = dir;
}

Request::~Request(){

}

int Request::getFloor(){
    return floor->getFloorNum();
}

bool Request::getDirection(){
    return direction;
}
