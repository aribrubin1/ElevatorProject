#ifndef ECS_H
#define ECS_H
#include "Elevator.h"
#include "Floor.h"
#include "Request.h"

#include <vector>
using namespace std;

class ECS
{
private:
    vector<Elevator*> elevators;
    vector<Request*> ElevatorRequestQueue;
    vector<Floor*> floors;
public:
    ECS(int, int);
    ~ECS();

    Elevator* getElevator(int);
    void sendElevator(Elevator*,Floor*);
    void addPassenger(Elevator*, Passenger*);
    void removePassenger(Elevator*, Passenger*);
    void handleNewRequest(Request);
    void removeRequest(Request*);
    int getElevatorNums();

    void handleDoorObstruction(Elevator*);
    void handleHelpButton(Elevator*);
    void sendFireSignal(Elevator*);
    void sendFireSignalToAll();
    void sendPowerOutSignal();
    void openDoor(Elevator*);
    void closeDoor(Elevator*);
    void detectOverload(Elevator*);

};
#endif
