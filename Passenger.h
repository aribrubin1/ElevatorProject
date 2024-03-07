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
        //bool desiredDirection;
        //Request* request;
        //Elevator* elevator;
    public:
        Passenger(int);
        ~Passenger();
        int getID();
        void enterFloor();
        void exitFloor();
        void requestUp();
        void requestDown();
};

#endif
