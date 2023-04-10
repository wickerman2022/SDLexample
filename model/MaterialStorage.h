#pragma once

#include "ResourceMaterial.h"
#include <map>

enum RESOURCE_MATERIAL_TYPE
{
    RESOURCE_MATERIAL_TYPE_NONE = 0,
    RESOURCE_MATERIAL_TYPE_SAND, // Sand
    RESOURCE_MATERIAL_TYPE_GRAVEL, // Gravel
    RESOURCE_MATERIAL_TYPE_BITUMEN, // Bitumen
    RESOURCE_MATERIAL_TYPE_MINERAL_POWDER, // Mineral Powder
    RESOURCE_MATERIAL_TYPE_FUEL, // Fuel
    RESOURCE_MATERIAL_TYPE_CELLULOSE, // Cellulose
    RESOURCE_MATERIAL_TYPE_ELECTRICITY, // Electricity 
};

class MaterialStorage: public GameObject
{
public:
    //Constructor & Destructor
    MaterialStorage();
    virtual ~MaterialStorage();

    //Other methods
    virtual void Update(double dt);
    virtual void Render();
    // Add material to storage
    void AddMaterial(RESOURCE_MATERIAL_TYPE type, int amount);
    //Get material from storage
    int GetMaterial(RESOURCE_MATERIAL_TYPE type, int amount);
private:
    // Map of materials
    std::map<RESOURCE_MATERIAL_TYPE, ResourceMaterial*> materials;
};