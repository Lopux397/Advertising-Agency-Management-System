#pragma once

#include <string>

class Specialist
{
private:
    int id;
    std::string name;
    std::string specialization;
    std::string phone;
    std::string email;
public:
    Specialist();
    Specialist(int idTemp, std::string_view nameTemp, std::string_view specializationTemp, std::string_view phoneTemp, std::string_view emailTemp);

    int getId() const;
    std::string getName() const;
    std::string getSpecialization() const;
    std::string getPhone() const;
    std::string getEmail() const;

    void setName(std::string_view nameTemp);
    void setSpecialization(std::string_view specializationTemp);
    void setPhone(std::string_view phoneTemp);
    void setEmail(std::string_view emailTemp);
};