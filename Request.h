#ifndef REQUEST_H
#define REQUEST_H
#include "Floor.h"
class Request{
    private:
        Floor* floor;
        bool direction;
    public:
        Request(Floor*,bool);
        ~Request();
        int getFloor();
        bool getDirection();
};

#endif
