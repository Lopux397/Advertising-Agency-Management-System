#pragma once

class Budget
{
private:
    double allocatedAmount{};
    double spentAmount{};
public:
    Budget();
    Budget(double allocatedAmountTemp, double spentAmountTemp);

    double getAllocatedAmount() const;
    double getSpentAmount() const;

    void setAllocatedAmount(double allocatedAmountTemp);

    double getRemainingAmount() const;

    bool checkAvailability(double amount) const;

    void addExpense(double amount);

    bool isOverBudget() const;
};