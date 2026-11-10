#include "../headers/budget.h"

#include <stdexcept>
#include <cmath>

Budget::Budget() = default;
Budget::Budget(double allocatedAmountTemp, double spentAmountTemp) : allocatedAmount(allocatedAmountTemp), spentAmount(spentAmountTemp)
{
    if (!std::isfinite(allocatedAmountTemp) || allocatedAmountTemp < 0)
        throw std::invalid_argument("Allocated amount cannot be negative or invalid");
    if (!std::isfinite(spentAmountTemp) || spentAmountTemp < 0)
        throw std::invalid_argument("Spent amount cannot be negative or invalid");
}

double Budget::getAllocatedAmount() const { return allocatedAmount;}
double Budget::getSpentAmount() const { return spentAmount; }

void Budget::setAllocatedAmount(double allocatedAmountTemp)
{
    if (!std::isfinite(allocatedAmountTemp) || allocatedAmountTemp < 0)
        throw std::invalid_argument("Allocated amount cannot be negative or invalid");

    allocatedAmount = allocatedAmountTemp;
}

double Budget::getRemainingAmount() const { return allocatedAmount - spentAmount;}

bool Budget::checkAvailability(double amount) const
{
    if (!std::isfinite(amount) || amount <= 0)
        return false;

    return spentAmount + amount <= allocatedAmount;
}

void Budget::addExpense(double amount)
{
    if (!std::isfinite(amount) || amount <= 0)
        throw std::invalid_argument("Expense must be positive and finite");

    double newSpentAmount = spentAmount + amount;

    if (!std::isfinite(newSpentAmount))
        throw std::overflow_error("Expense amount overflow");

    spentAmount = newSpentAmount;
}

bool Budget::isOverBudget() const
{
    return spentAmount > allocatedAmount;
}