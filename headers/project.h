#pragma once

#include "../headers/date.h"
#include "../headers/service.h"

#include <memory>
#include <vector>
#include <string>
#include <optional>
#include <string_view>

using ServicePtr = std::unique_ptr<Service>;
using ServiceList = std::vector<ServicePtr>;

enum class ProjectStatus
{
    Planned,
    InProgress,
    Completed,
    Suspended
};

class Project
{
private:
    int id{};
    inline static int nextId{1};
    int campaignId{};
    std::string name;
    std::string description;
    Date startDate;
    Date plannedEndDate;
    std::optional<Date> actualEndDate;
    ProjectStatus status;
    ServiceList services;
public:
    Project(int campaignIdTemp, std::string_view nameTemp, std::string_view descriptionTemp, const Date& startDateTemp, const Date& plannedEndDateTemp, ProjectStatus statusTemp, ServiceList servicesTemp);

    int getId() const;
    int getCampaignId() const;
    std::string_view getName() const;
    std::string_view getDescription() const;
    const Date& getStartDate() const;
    const Date& getPlannedEndDate() const;
    const std::optional<Date>& getActualEndDate() const;
    ProjectStatus getStatus() const;
    const ServiceList& getServices() const;

    void setName(std::string_view nameTemp);
    void setDescription(std::string_view descriptionTemp);
    void setStartDate(const Date& startDateTemp);
    void setPlannedEndDate(const Date& plannedEndDateTemp);
    void setActualEndDate(std::optional<Date> actualEndDateTemp);
    void setStatus(ProjectStatus statusTemp);

    void addService(ServicePtr service);
    bool removeService(int serviceId);

    Service* findServiceById(int serviceId);
    const Service* findServiceById(int serviceId) const;

    bool isOverdue(const Date& currentDate) const;
    bool isCompleted() const;

    double calculateTotalCost() const;
};