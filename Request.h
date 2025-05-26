#ifndef REQUEST_H
#define REQUEST_H
#include "Floor.h"
class Request{
    private:
        Floor* floor;
    public:
        Request(Floor*);
        ~Request();
        int getFloor();
};

#endif
