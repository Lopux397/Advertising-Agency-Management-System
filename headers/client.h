#pragma once

#include <string>

class Client
{
private:
    int id;
    std::string name;
    std::string contactPerson;
    std::string phone;
    std::string email;
public:
    Client();
    Client(int idTemp, std::string_view nameTemp, std::string_view contactPersonTemp, std::string_view phoneTemp, std::string_view emailTemp);

    int getId() const;
    std::string getName() const;
    std::string getContactPerson() const;
    std::string getPhone() const;
    std::string getEmail() const;

    void setName(std::string_view nameTemp);
    void setContactPerson(std::string_view contactPersonTemp);
    void setPhone(std::string_view phoneTemp);
    void setEmail(std::string_view emailTemp);

    bool operator== (const Client& client) const;
};