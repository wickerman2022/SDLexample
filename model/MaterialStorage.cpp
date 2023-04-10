#include "MaterialStorage.h"

//Constructor & Destructor

MaterialStorage::MaterialStorage()
{
    // Add sand
    materials[RESOURCE_MATERIAL_TYPE_SAND] = new ResourceMaterial();
    // Add gravel
    materials[RESOURCE_MATERIAL_TYPE_GRAVEL] = new ResourceMaterial();
    // Add bitumen
    materials[RESOURCE_MATERIAL_TYPE_BITUMEN] = new ResourceMaterial();
    // Add mineral powder
    materials[RESOURCE_MATERIAL_TYPE_MINERAL_POWDER] = new ResourceMaterial();
    // Add fuel
    materials[RESOURCE_MATERIAL_TYPE_FUEL] = new ResourceMaterial();
    // Add cellulose
    materials[RESOURCE_MATERIAL_TYPE_CELLULOSE] = new ResourceMaterial();
    // Add electricity
    materials[RESOURCE_MATERIAL_TYPE_ELECTRICITY] = new ResourceMaterial();
}

MaterialStorage::~MaterialStorage()
{
    // Delete sand
    delete materials[RESOURCE_MATERIAL_TYPE_SAND];
    // Delete gravel
    delete materials[RESOURCE_MATERIAL_TYPE_GRAVEL];
    // Delete bitumen
    delete materials[RESOURCE_MATERIAL_TYPE_BITUMEN];
    // Delete mineral powder
    delete materials[RESOURCE_MATERIAL_TYPE_MINERAL_POWDER];
    // Delete fuel
    delete materials[RESOURCE_MATERIAL_TYPE_FUEL];
    // Delete cellulose
    delete materials[RESOURCE_MATERIAL_TYPE_CELLULOSE];
    // Delete electricity
    delete materials[RESOURCE_MATERIAL_TYPE_ELECTRICITY];
}

//Add material to storage
void MaterialStorage::AddMaterial(RESOURCE_MATERIAL_TYPE type, int amount)
{
    // Add material to map
    auto it = materials.find(type);
        if (it != materials.end()) {
            it->second += amount;
        } else {
            materials[type] = new ResourceMaterial();
        }
}

//Get material from storage
int MaterialStorage::GetMaterial(RESOURCE_MATERIAL_TYPE type, int amount)
{
    // Add material to map
    auto it = materials.find(type);
        if (it != materials.end()) {
            it->second -= amount;
        } else {
            materials[type] = new ResourceMaterial();
        }
}