#pragma once

#include <string>
#include <string_view>
#include <vector>

class Service
{
private:
    int id{};
    inline static int nextId{1};
    std::string name;
    std::string description;
    std::vector<int> specialistIds;
protected:
    Service(std::string_view nameTemp, std::string_view descriptionTemp, const std::vector<int>& specialistIdsTemp);
public:
    virtual ~Service() = default;

    int getId() const;
    std::string_view getName() const;
    std::string_view getDescription() const;
    const std::vector<int>& getSpecialistIds() const;

    void setName(std::string_view nameTemp);
    void setDescription(std::string_view descriptionTemp);

    bool assignSpecialist(int specialistId);
    bool removeSpecialist(int specialistId);

    virtual double calculateCost() const = 0;
    virtual std::string_view getType() const = 0;
};