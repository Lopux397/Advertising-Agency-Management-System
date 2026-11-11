#pragma once

#include "../headers/service.h"

enum class DifLevels
{
    Simple,
    Medium,
    Complex
};

class DesignService : public Service
{
private:
    double pricePerUnit;
    int quantity;
    DifLevels complexity;
public:
    DesignService(std::string_view nameTemp, std::string_view descriptionTemp, const std::vector<int>& specialistIdsTemp, double pricePerUnitTemp, int quantityTemp, DifLevels complexityTemp);

    double getPricePerUnit() const;
    int getQuantity() const;
    DifLevels getComplexity() const;

    void setPricePerUnit(double pricePerUnitTemp);
    void setQuantity(int quantityTemp);
    void setComplexity(DifLevels complexityTemp);

    double calculateCost() const override;
    std::string_view getType() const override;
};