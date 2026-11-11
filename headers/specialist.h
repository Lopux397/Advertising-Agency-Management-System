#pragma once

#include <string>
#include <string_view>

enum class SpecialistType
{
    Unspecified,
    Designer,
    Marketer,
    Copywriter
};

class Specialist
{
private:
    int id{};
    inline static int nextId{1};
    std::string name;
    SpecialistType specialization {SpecialistType::Unspecified};
    std::string phone;
    std::string email;
public:
    Specialist();
    Specialist(std::string_view nameTemp, SpecialistType specializationTemp, std::string_view phoneTemp, std::string_view emailTemp);

    int getId() const;
    std::string_view getName() const;
    SpecialistType getSpecialization() const;
    std::string_view getPhone() const;
    std::string_view getEmail() const;

    void setName(std::string_view nameTemp);
    void setSpecialization(SpecialistType specializationTemp);
    void setPhone(std::string_view phoneTemp);
    void setEmail(std::string_view emailTemp);
};