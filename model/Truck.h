#pragma once

#include "Vehicle.h"
#include "ResourceMaterial.h"
#include "Worker.h"

// Truck is a vehicle that can carry resources
class Truck: public Vehicle
{
public:
    //Constructor & Destructor
    Truck();
    virtual ~Truck();

    //Other methods
    virtual void Update(double dt);
    virtual void Render();
    void Upgrade(); // Upgrade truck
    void transport(ResourceMaterial* resource); // Transport resource
private:
    int capacity; // Capacity of truck
};
