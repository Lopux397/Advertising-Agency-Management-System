#include "../headers/client.h"

Client::Client() = default;
Client::Client(int idTemp, std::string_view nameTemp, std::string_view contactPersonTemp, std::string_view phoneTemp, std::string_view emailTemp) : id(idTemp), name(nameTemp), contactPerson(contactPersonTemp), phone(phoneTemp), email(emailTemp) {}

int Client::getId() const { return id; }
std::string Client::getName() const { return name; }
std::string Client::getContactPerson() const { return contactPerson; }
std::string Client::getPhone() const { return phone; }
std::string Client::getEmail() const { return email; }

void Client::setName(std::string_view nameTemp) { name = nameTemp; }
void Client::setContactPerson(std::string_view contactPersonTemp) { contactPerson = contactPersonTemp; }
void Client::setPhone(std::string_view phoneTemp) { phone = phoneTemp; }
void Client::setEmail(std::string_view emailTemp) { email = emailTemp; }

bool Client::operator== (const Client& client) const
{
    return id == client.id;
}

