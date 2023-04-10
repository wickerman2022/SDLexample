#pragma once

#include "Vehicle.h"

// AsphaltPaver is a vehicle that can lay asphalt
class AsphaltPaver: public Vehicle
{
public:
    //Constructor & Destructor
    AsphaltPaver();
    virtual ~AsphaltPaver();

    //Other methods
    virtual void Update(double dt);
    virtual void Render();
private:
    int compaction; // Compaction of asphalt
};
