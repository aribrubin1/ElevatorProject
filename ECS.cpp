#include "ECS.h"

ECS::ECS(int numElevators, int numFloors)
{
    for(int i = 0; i < numFloors; i++){
        floors.push_back(new Floor());
    }

    for(int i = 0; i < numElevators; i++){
        elevators.push_back(new Elevator(floors.at(i)));
    }

}

ECS::~ECS(){
    for(int i = 0; i < elevators.size(); i++){
        delete elevators.at(i);
    }

    for(int i = 0; i < floors.size(); i++){
        delete floors.at(i);
    }
}

int ECS::getElevatorNums(){
    return elevators.size();
}

Elevator* ECS::getElevator(int i){
    return elevators.at(i);
}
