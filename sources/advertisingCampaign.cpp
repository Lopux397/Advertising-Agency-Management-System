#include "../headers/advertisingCampaign.h"

AdvertisingCampaign::AdvertisingCampaign(int clientIdTemp,const Budget& budgetTemp, std::string_view nameTemp, std::string_view descriptionTemp, const Date& startDateTemp, const Date& endDateTemp, CampaignStatus statusTemp) : id(nextId++) , clientId(clientIdTemp), budget(budgetTemp), name(nameTemp), description(descriptionTemp), startDate(startDateTemp), endDate(endDateTemp), status(statusTemp)
{
    if (endDate < startDate)
        throw std::invalid_argument("End date cannot be earlier than start date");
}

int AdvertisingCampaign::getId() const { return id; }
int AdvertisingCampaign::getClientId() const { return clientId; }
Budget& AdvertisingCampaign::getBudget() { return budget; }
const Budget& AdvertisingCampaign::getBudget() const { return budget; }
std::string_view AdvertisingCampaign::getName() const { return name; }
std::string_view AdvertisingCampaign::getDescription() const { return description; }
const Date& AdvertisingCampaign::getStartDate() const { return startDate; }
const Date& AdvertisingCampaign::getEndDate() const { return endDate; }
CampaignStatus AdvertisingCampaign::getStatus() const { return status; }

void AdvertisingCampaign::setName(std::string_view nameTemp) { name = nameTemp; }
void AdvertisingCampaign::setDescription(std::string_view descriptionTemp) { description = descriptionTemp; }
void AdvertisingCampaign::setStartDate(const Date& startDateTemp) { startDate = startDateTemp; }
void AdvertisingCampaign::setEndDate(const Date& endDateTemp) { endDate = endDateTemp; }
void AdvertisingCampaign::setStatus(CampaignStatus statusTemp) { status = statusTemp; }
