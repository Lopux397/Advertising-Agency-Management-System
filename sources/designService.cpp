#include "../headers/designService.h"

#include <stdexcept>
#include <cmath>

DesignService::DesignService(std::string_view nameTemp, std::string_view descriptionTemp, const std::vector<int>& specialistIdsTemp, double pricePerUnitTemp, int quantityTemp, DifLevels complexityTemp)
    : Service(nameTemp, descriptionTemp, specialistIdsTemp), pricePerUnit(pricePerUnitTemp), quantity(quantityTemp), complexity(complexityTemp)
{
    if (!std::isfinite(pricePerUnitTemp) || pricePerUnitTemp < 0)
        throw std::invalid_argument("Price per unit of time cannot be negative or invalid");
    if (quantityTemp < 1)
        throw std::invalid_argument("The quantity cannot be negative or equal to zero");
    //complexity должна соответствовать одному из трёх допустимых значений.
}

double DesignService::getPricePerUnit() const { return pricePerUnit; }
int DesignService::getQuantity() const { return quantity; }
DifLevels DesignService::getComplexity() const { return complexity; }

void DesignService::setPricePerUnit(double pricePerUnitTemp)
{
    if (!std::isfinite(pricePerUnitTemp) || pricePerUnitTemp < 0)
        throw std::invalid_argument("Price per unit of time cannot be negative or invalid");

    pricePerUnit = pricePerUnitTemp;
}
void DesignService::setQuantity(int quantityTemp)
{
    if (quantityTemp < 1)
        throw std::invalid_argument("The quantity cannot be negative or equal to zero");

    quantity = quantityTemp;
}
void DesignService::setComplexity(DifLevels complexityTemp)
{
    //complexity должна соответствовать одному из трёх допустимых значений.
    complexity = complexityTemp;
}

double DesignService::calculateCost() const
{
    using enum DifLevels;

    switch(complexity)
    {
    case Simple :
        return pricePerUnit * quantity * 1.0;
    case Medium :
        return pricePerUnit * quantity * 1.5;
    case Complex :
        return pricePerUnit * quantity * 2.0;
    default:
        throw std::logic_error("Unknown complexity level");
    }
}
std::string_view DesignService::getType() const { return "DesignService"; }
