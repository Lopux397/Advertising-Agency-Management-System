#include "../headers/service.h"

#include <algorithm>
#include <ranges>

Service::Service(std::string_view nameTemp, std::string_view descriptionTemp, const std::vector<int>& specialistIdsTemp)
    : id(nextId++), name(nameTemp), description(descriptionTemp), specialistIds(specialistIdsTemp){}

int Service::getId() const { return id; }
std::string_view Service::getName() const { return name; }
std::string_view Service::getDescription() const { return description; }
const std::vector<int>& Service::getSpecialistIds() const { return specialistIds; }

void Service::setName(std::string_view nameTemp) { name = nameTemp; }
void Service::setDescription(std::string_view descriptionTemp) { description = descriptionTemp; }

bool Service::assignSpecialist(int specialistId)
{
    if (auto it = std::ranges::find(specialistIds, specialistId);
        it != std::ranges::end(specialistIds))
        return false;

    specialistIds.push_back(specialistId);
    return true;
}
bool Service::removeSpecialist(int specialistId)
{
    auto it = std::ranges::find(specialistIds, specialistId);

    if (it == std::ranges::end(specialistIds)) return false;

    specialistIds.erase(it);
    return true;
}
