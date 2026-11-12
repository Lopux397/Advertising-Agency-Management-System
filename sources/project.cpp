#include "../headers/project.h"

#include <utility>
#include <stdexcept>
#include <algorithm>

Project::Project(int campaignIdTemp, std::string_view nameTemp, std::string_view descriptionTemp, const Date& startDateTemp, const Date& plannedEndDateTemp, ProjectStatus statusTemp, ServiceList servicesTemp)
    : id(nextId++), campaignId(campaignIdTemp), name(nameTemp), description(descriptionTemp), startDate(startDateTemp), plannedEndDate(plannedEndDateTemp), actualEndDate(std::nullopt), status(statusTemp), services(std::move(servicesTemp))
{
    if (std::any_of(services.begin(), services.end(), [](const auto& service){ return !service; }))
        throw std::invalid_argument("Service cannot be null");
    if (isCompleted())
        throw std::invalid_argument("A project cannot be created in a completed state");
}

int Project::getId() const {return id;}
int Project::getCampaignId() const { return campaignId; }
std::string_view Project::getName() const { return name; }
std::string_view Project::getDescription() const { return description; }
const Date& Project::getStartDate() const { return startDate; }
const Date& Project::getPlannedEndDate() const { return plannedEndDate; }
const std::optional<Date>& Project::getActualEndDate() const { return actualEndDate; }
ProjectStatus Project::getStatus() const { return status; }
const ServiceList& Project::getServices() const { return services; }

void Project::setName(std::string_view nameTemp) { name = nameTemp; }
void Project::setDescription(std::string_view descriptionTemp) { description = descriptionTemp; }
void Project::setStartDate(const Date& startDateTemp)
{
    if (startDateTemp > plannedEndDate)
        throw std::invalid_argument("Start date cannot be later than planned end date");
    if (actualEndDate && *actualEndDate < startDateTemp)
        throw std::invalid_argument("Start date cannot be later than actual end date");

    startDate = startDateTemp;
}
void Project::setPlannedEndDate(const Date& plannedEndDateTemp)
{
    if (plannedEndDateTemp < startDate)
        throw std::invalid_argument("Planned end date cannot be earlier than start date");

    plannedEndDate = plannedEndDateTemp;
}
void Project::setActualEndDate(std::optional<Date> actualEndDateTemp)
{
    if (actualEndDateTemp && *actualEndDateTemp < startDate)
        throw std::invalid_argument("Actual end date cannot be earlier than start date");

    actualEndDate = std::move(actualEndDateTemp);
}
void Project::setStatus(ProjectStatus statusTemp) { status = statusTemp; }

void Project::addService(ServicePtr service)
{
    if (!service)
        throw std::invalid_argument("Service cannot be null");

    int serviceId = service->getId();

    if (auto it = std::find_if(services.begin(), services.end(),
    [serviceId](const auto& existingService){  return existingService->getId() == serviceId; })
    ; it != services.end())
        throw std::invalid_argument("Service already exists in project");

    services.push_back(std::move(service));
}
bool Project::removeService(int serviceId)
{
    auto it = std::find_if(services.begin(), services.end(),
        [serviceId](const auto& existingService){ return existingService->getId() == serviceId; });

    if (it == services.end()) return false;

    services.erase(it);
    return true;
}

Service* Project::findServiceById(int serviceId)
{
    auto it = std::find_if(services.begin(), services.end(),
       [serviceId](const auto& existingService){ return existingService->getId() == serviceId; });

    if (it == services.end())
        return nullptr;

    return it->get();
}
const Service* Project::findServiceById(int serviceId) const
{
    auto it = std::find_if(services.begin(), services.end(),
        [serviceId](const auto& existingService){ return existingService->getId() == serviceId; });

    if (it == services.end())
        return nullptr;

    return it->get();
}

bool Project::isOverdue(const Date& currentDate) const
{
    return (currentDate > plannedEndDate) && !isCompleted();
}
bool Project::isCompleted() const
{
    return status == ProjectStatus::Completed;
}

double Project::calculateTotalCost() const
{
    double totalCost{};

    for(const auto& service: services)
    {
        totalCost += service->calculateCost();
    }

    return totalCost;
}