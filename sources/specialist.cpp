#include "../headers/specialist.h"

Specialist::Specialist() : id(nextId++) {}
Specialist::Specialist(std::string_view nameTemp, SpecialistType specializationTemp, std::string_view phoneTemp, std::string_view emailTemp) : id(nextId++), name(nameTemp), specialization(specializationTemp), phone(phoneTemp), email(emailTemp) {}

int Specialist::getId() const { return id; }
std::string_view Specialist::getName() const { return name; }
SpecialistType Specialist::getSpecialization() const { return specialization; }
std::string_view Specialist::getPhone() const { return phone; }
std::string_view Specialist::getEmail() const { return email; }

void Specialist::setName(std::string_view nameTemp) { name = nameTemp; }
void Specialist::setSpecialization(SpecialistType specializationTemp) { specialization = specializationTemp; }
void Specialist::setPhone(std::string_view phoneTemp) { phone = phoneTemp; }
void Specialist::setEmail(std::string_view emailTemp) { email = emailTemp; }