#include "../headers/designService.h"

DesignService::DesignService(std::string_view nameTemp, std::string_view descriptionTemp, const std::vector<int>& specialistIdsTemp, double pricePerUnitTemp, int quantityTemp, DifLevels complexityTemp)
    : Service(nameTemp, descriptionTemp, specialistIdsTemp), pricePerUnit(pricePerUnitTemp), quantity(quantityTemp), complexity(complexityTemp) {}

double DesignService::getPricePerUnit() const { return pricePerUnit; }
int DesignService::getQuantity() const { return quantity; }
DifLevels DesignService::getComplexity() const { return complexity; }

void DesignService::setPricePerUnit(double pricePerUnitTemp) { pricePerUnit = pricePerUnitTemp; }
void DesignService::setQuantity(int quantityTemp) { quantity = quantityTemp; }
void DesignService::setComplexity(DifLevels complexityTemp) { complexity = complexityTemp; }

double DesignService::calculateCost() const
{
    switch(complexity)
    {
    case DifLevels::Simple :
        return pricePerUnit * quantity * 1.0;
    case DifLevels::Medium :
        return pricePerUnit * quantity * 1.5;
    case DifLevels::Complex :
        return pricePerUnit * quantity * 2.0;
    }
}
std::string_view DesignService::getType() const { return "DesignService"; }
