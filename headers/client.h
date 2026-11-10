#pragma once

#include <string>
#include <iostream>
#include <limits>
#include <string_view>

class Client
{
private:
    int id{};
    inline static int nextId{1};
    std::string name;
    std::string contactPerson;
    std::string phone;
    std::string email;
public:
    Client();
    Client(std::string_view nameTemp, std::string_view contactPersonTemp, std::string_view phoneTemp, std::string_view emailTemp);

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

    friend std::ostream& operator<< (std::ostream& os, const Client& client)
    {
        os << client.id << std::endl;
        os << client.name << std::endl;
        os << client.contactPerson << std::endl;
        os << client.phone << std::endl;
        os << client.email << std::endl;
        return os;
    }
    friend std::istream& operator>> (std::istream& is, Client& client)
    {
        std::getline(is, client.name);
        std::getline(is, client.contactPerson);
        std::getline(is, client.phone);
        std::getline(is, client.email);
        return is;
    }
};