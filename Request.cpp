#include "Request.h"

Request::Request(Floor* floorvar)
{
    floor = floorvar;
}

Request::~Request(){

}

int Request::getFloor(){
    return floor->getFloorNum();
}
