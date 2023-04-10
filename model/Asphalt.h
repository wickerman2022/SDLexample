#pragma once

#include "GameObject.h"

class Asphalt: public GameObject
{
public:
    //Constructor & Destructor
    Asphalt();
    virtual ~Asphalt();

    //Other methods
    virtual void Update(double dt);
    virtual void Render();
private:
    int gravel; // Amount of gravel
    int sand; // Amount of sand
    int cement; // Amount of cement
    int bitumen; // Amount of bitumen
    int cost; // Cost of asphalt
};