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
        bool stationary;
        string currentVisualMessage;
        string currentAudioMessage;
        bool doorOpen;
        vector<Request*> upFloorRequests;
        vector<Request*> downFloorRequests;
        vector<Passenger*> passengers;
        Floor* currentfloor;
        void overload();
        int doortimer;
    public:
        Elevator(Floor*);
        ~Elevator();
        vector<int> getPassengerList();
        int getfloorNum();
        void sendAudioMessage(std::string);
        void sendVisualMessage(std::string);
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
