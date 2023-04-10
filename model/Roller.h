#ifndef ROLLER_H
#define ROLLER_H

//Resources includes
#include "Vehicle.h"
#include "Worker.h"

// Roller is a vehicle that can compact asphalt
class Roller: public Vehicle
{
public:
    //Constructor & Destructor
    Roller();
    virtual ~Roller();

    //Other methods
    virtual void Update(double dt);
    virtual void Render();
    void Upgrade(); // Upgrade roller
private:

};

#endif // ROLLER_H
