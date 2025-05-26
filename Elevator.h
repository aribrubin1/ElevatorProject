#ifndef ELEVATOR_H
#define ELEVATOR_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Passenger;
class Request;
class Floor;
class Elevator{
    private:
        static int nextID;
        int elevatorID;
        bool direction;
        string currentVisualMessage;
        string currentAudioMessage;
        bool doorOpen;
        vector<Request*> upFloorRequests;
        vector<Request*> downFloorRequests;
        vector<Passenger*> passengers;
        Request* currentRequest;
        int numPassengers;
        int currentFloor;
        void overload();
        int doortimer;

    public:
        Elevator(int);
        ~Elevator();
        bool stationary();
        vector<int> getPassengerList();
        string signal;
        int getNumPassengers();
        void loadNextRequest();
        Passenger* getPassenger(int i);
        bool isAtDesiredFloor();
        int getDesiredFloor();
        int activeRequests;
        void insertRequest(Request*);
        int getfloorNum();
        bool getDirection();
        void sendAudioMessage(std::string);
        void sendVisualMessage(std::string);
        void removePassenger(Passenger*);
        void addPassenger(Passenger*);
        void countdown();
        void detectOverload();
        void moveUp();
        void moveDown();
        void handleHelp();
        void receiveHelp();
        void fireAlarm();
        void powerOutage();
        void bellRing();
        void updateFloorNum(int);
};

#endif
