#pragma once

#include <iostream>
#include <string>
// Random number generator
#include <random>

#include "GameObject.h"
#include "Asphalt.h"
#include "Customer.h"
#include "Road.h"

enum ContractStatus
{
    NOT_STARTED = 0,
    IN_PROGRESS = 1,
    COMPLETED = 2
};

enum ContractPayment
{
    NOT_PAID = 0,
    PAID = 1
};

enum ContractRating
{
    NOT_RATED = 0,
    BAD = 1,
    AVERAGE = 2,
    GOOD = 3
};

enum ContractType
{
    RECONSTRUCTION = 0,
    BUILDING = 1
};

//Contract class inherits from GameObject class that stores the road building/reconstruction contract details
class Contract : public GameObject
{
public:
    //Constructor & Destructor
    Contract();
    ~Contract();

    //Other methods
    void Update(double dt);
    void Render();
    
    //Game methods
    void StartContract();
    int CompleteContract(); //Returns contract profit
    void GetContractRating();
    void GetContractLength();
    void GetContractCost();
    void GetContractProfit();
    void GetContractCompletion();
    void GetContractStatus();
    void GetContractPayment();
    void GetContractLateFee();

private:
    //Contract properties
    Customer customer; //Customer that the contract is for
    Road road; //Road that the contract is for
    Asphalt asphalt; //Asphalt that the contract is for
    ContractType contractType; //Type of the contract (0 = reconstruction, 1 = building)
    int contractLength; //Length of the contract in days
    int contractCost; //Cost of the contract
    int contractProfit; //Profit of the contract
    int contractCompletion; //Completion of the contract in days
    ContractStatus contractStatus; //Status of the contract (0 = not started, 1 = in progress, 2 = completed)
    ContractPayment contractPayment; //Payment of the contract (0 = not paid, 1 = paid)
    ContractRating contractRating; //Rating of the contract (0 = not rated, 1 = bad, 2 = average, 3 = good)
    int contractLateFee; //Late fee of the contract 
};
