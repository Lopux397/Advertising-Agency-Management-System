#pragma once

#include "../headers/budget.h"
#include "../headers/date.h"

#include <string>
#include <string_view>

enum class CampaignStatus
{
    Planned,
    Active,
    Completed,
    Suspended
};

class AdvertisingCampaign
{
private:
    int id{};
    inline static int nextId{1};
    int clientId{};
    Budget budget;
    std::string name;
    std::string description;
    Date startDate;
    Date endDate;
    CampaignStatus status{CampaignStatus::Planned};
    //ДОБАВИТЬ friend AgencySystem
public:
    AdvertisingCampaign(int clientIdTemp,const Budget& budgetTemp, std::string_view nameTemp, std::string_view descriptionTemp, const Date& startDateTemp, const Date& endDateTemp, CampaignStatus statusTemp);

    int getId() const;
    int getClientId() const;
    Budget& getBudget();
    const Budget& getBudget() const;
    std::string_view getName() const;
    std::string_view getDescription() const;
    const Date& getStartDate() const;
    const Date& getEndDate() const;
    CampaignStatus getStatus() const;

    void setName(std::string_view nameTemp);
    void setDescription(std::string_view descriptionTemp);
    void setStartDate(const Date& startDateTemp);
    void setEndDate(const Date& endDateTemp);
    void setStatus(CampaignStatus statusTemp);

};