#include "../headers/service.h"

#include <utility>
#include <algorithm>

Service::Service(std::string_view nameTemp, std::string_view descriptionTemp, std::vector<int> specialistIdsTemp) : id(nextId++), name(nameTemp), description(descriptionTemp), specialistIds(specialistIdsTemp){}

int Service::getId() const { return id; }
std::string_view Service::getName() const { return name; }
std::string_view Service::getDescription() const { return description; }
std::vector<int> Service::getSpecialistIds() const { return specialistIds; }

void Service::setName(std::string_view nameTemp) { name = nameTemp; }
void Service::setDescription(std::string_view descriptionTemp) { description = descriptionTemp; }
void Service::setSpecialistIds(std::vector<int> specialistIdsTemp) { specialistIds = std::move(specialistIdsTemp); }

bool Service::assignSpecialist(int specialistId)
{
    auto it = std::find(specialistIds.begin(), specialistIds.end(), specialistId);

    if (it == specialistIds.end()) return false;

    specialistIds.push_back(specialistId);
    return true;
}
bool Service::removeSpecialist(int specialistId)
{
    auto it = std::find(specialistIds.begin(), specialistIds.end(), specialistId);

    if (it == specialistIds.end()) return false;

    specialistIds.erase(it);
    return true;
}
