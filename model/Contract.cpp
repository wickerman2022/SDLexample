#include "Contract.h"

Contract::Contract()
{
    //Generate random number for contract rating
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 3);
    contractRating = dist(mt);

    //Generate random number for contract length
    std::random_device rd2;
    std::mt19937 mt2(rd2());
    std::uniform_int_distribution<int> dist2(1, 5000);
    contractLength = dist2(mt2);

    //Generate random number for contract profit koefficient
    std::random_device rd3;
    std::mt19937 mt3(rd3());
    std::uniform_int_distribution<int> dist3(1, contractRating);
    int contractProfitKoeff = dist3(mt3) * 3;

    contractStatus = 0;
    contractPayment = 0;
    contractCompletion = 0;
    contractCost = contractLength * contractProfitKoeff;
}

Contract::~Contract()
{
}

void Contract::Update(double dt)
{
}

void Contract::Render()
{
}

void Contract::StartContract()
{
    contractStatus = 1;
}

int Contract::CompleteContract()
{
    contractStatus = 2;
    contractPayment = 1;
    //If contract is completed before the contract length, the contract profit is increased
    if (contractCompletion < contractLength)
    {
        contractProfit = contractCost + (contractLength - contractCompletion);
    }
    //If contract is completed after the contract length 
    //late fee is calculated and the contract profit is decreased
    else if (contractCompletion > contractLength)
    {
        contractLateFee = (contractCompletion - contractLength) * 2;
        contractProfit = contractCost - contractLateFee;
    }
    //If contract is completed on the contract length, the contract profit is the same
    else if (contractCompletion == contractLength)
    {
        contractProfit = contractCost;
    }
    return contractProfit;
    
}

void Contract::GetContractRating()
{
    std::cout << "Contract rating: " << contractRating << std::endl;
}

void Contract::GetContractLength()
{
    std::cout << "Contract length: " << contractLength << std::endl;
}

void Contract::GetContractCost()
{
    std::cout << "Contract cost: " << contractCost << std::endl;
}

void Contract::GetContractProfit()
{
    std::cout << "Contract profit: " << contractProfit << std::endl;
}

void Contract::GetContractCompletion()
{
    std::cout << "Contract completion: " << contractCompletion << std::endl;
}

void Contract::GetContractStatus()
{
    std::cout << "Contract status: " << contractStatus << std::endl;
}

void Contract::GetContractPayment()
{
    std::cout << "Contract payment: " << contractPayment << std::endl;
}

void Contract::GetContractLateFee()
{
    std::cout << "Contract late fee: " << contractLateFee << std::endl;
}

// Path: Contract.h