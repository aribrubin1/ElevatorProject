#ifndef PASSENGER_H
#define PASSENGER_H
using namespace std;
#include <vector>

class Floor;
class Passenger{
    private:
        static int nextID;
        int passengerID;
        int currentFloor;
        int desiredFloor;
        bool desiredDirection;
        //bool desiredDirection;
        //Request* request;
        //Elevator* elevator;
    public:
        Passenger(int);
        ~Passenger();
        bool getDesiredDirection();
        int getDesiredFloor();
        void setDesiredFloor(int);
        int getID();
        int getCurrentFloor();
        void enterFloor();
        void exitFloor();
        void requestUp();
        void requestDown();

};

#endif
