#ifndef ECS_H
#define ECS_H
#include "Elevator.h"
#include "Floor.h"
#include "Request.h"
#include "QDebug"
#include <vector>
using namespace std;

class ECS
{
private:
    vector<Elevator*> elevators;
    vector<Request*> ElevatorRequestQueue;
    vector<Floor*> floors;
    vector<Passenger*> passengers;
public:
    ECS(int, int);
    ~ECS();
    int floorNum;
    int elevatorNum;
    int passengerNum;

    Elevator* getElevator(int);
    Floor* getFloorStats(int);
    Passenger* getPassenger(int);
    void loadElevator(Elevator*, Floor*);
    void sendElevator(Elevator*,Floor*);
    void addPassenger(Elevator*, Passenger*);
    void removePassenger(Elevator*, Passenger*);
    void spawnPassenger(int);
    void handleNewRequest(Request);
    void removeRequest(Request*);
    void sendSignal(Elevator*, string);
    Elevator* dollOutRequest(Request*);
    void floorRequest(Request*);

    void handleDoorObstruction(Elevator*);
    void handleHelpButton(Elevator*);
    void sendFireSignal(Elevator*);
    void sendFireSignalToAll();
    void sendPowerOutSignal();
    void openDoor(Elevator*);
    void closeDoor(Elevator*);
    void detectOverload(Elevator*);
    bool directionalHelper(int, int);

};
#endif
