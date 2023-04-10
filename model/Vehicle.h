//Prevent from being included more than once
#ifndef VEHICLE_H
#define VEHICLE_H

#include "GameObject.h"
#include "Worker.h"

// Vehicle class is a base class for all vehicles
class Vehicle: public GameObject
{
public:
    //Constructor & Destructor
    Vehicle();
    virtual ~Vehicle();

    //Other methods
    virtual void Update(double dt) = 0; 
    virtual void Render() = 0;
    virtual void Upgrade() = 0;
    void HireDriver(Worker* driver); // Hire a driver for vehicle
    void FireDriver(); // Fire driver of vehicle
    void Refuel(int amount); // Refuel vehicle
private:
    int speed; // Speed of vehicle
    int maxFuel; // Maximum fuel
    int fuel; // Current fuel
    int fuelConsumption; // Fuel consumption
    int maxOperationResources; // Operation resources before being brake down
    int level; // Level of vehicle
    int cost; // Cost of vehicle
    int upgradeCost; // Cost of upgrading vehicle
    Worker* driver; // Driver of vehicle
};

#endif // VEHICLE_H