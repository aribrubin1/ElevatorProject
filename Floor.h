#ifndef FLOOR_H
#define FLOOR_H
#include "Passenger.h"
#include <vector>
using namespace std;
class Floor{
    private:
        static int nextFloor;
        int floorNum;
        vector<Passenger*> passengerList;
        bool upElevatorRequested;
        bool downElevatorRequested;
    public:
        Floor();
        ~Floor();
        int getFloorNum();
        bool getFloorDirection();
        void PressUp();
        void PressDown();
        void sendElevatorRequest();
        bool detectElevator();

};
#endif

