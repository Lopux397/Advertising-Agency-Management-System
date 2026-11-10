#include "../headers/specialist.h"

Specialist::Specialist() = default;
Specialist::Specialist(int idTemp, std::string_view nameTemp, std::string_view specializationTemp, std::string_view phoneTemp, std::string_view emailTemp) : id(idTemp), name(nameTemp), specialization(specializationTemp), phone(phoneTemp), email(emailTemp) {}

int Specialist::getId() const { return id; }
std::string Specialist::getName() const { return name; }
std::string Specialist::getSpecialization() const { return specialization; }
std::string Specialist::getPhone() const { return phone; }
std::string Specialist::getEmail() const { return email; }

void Specialist::setName(std::string_view nameTemp) { name = nameTemp; }
void Specialist::setSpecialization(std::string_view specializationTemp) { specialization = specializationTemp; }
void Specialist::setPhone(std::string_view phoneTemp) { phone = phoneTemp; }
void Specialist::setEmail(std::string_view emailTemp) { email = emailTemp; }