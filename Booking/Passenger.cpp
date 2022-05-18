#include "Passenger.h"

#include <iostream>

Passenger::Passenger(std::string name):
_name(std::move(name))
{
}

void Passenger::Name(const std::string& name)
{
	this->_name = name;
}

void Passenger::Passport(const std::string& passport)
{
	this->_passport = passport;
}

void Passenger::Nationality(const std::string& nationality)
{
	this->_nationality = nationality;
}

void Passenger::DateOfBirth(const std::string& date_of_birth)
{
	_dateOfBirth = date_of_birth;
}

std::string Passenger::Name() const
{
	return _name;
}

std::string Passenger::Passport() const
{
	return _passport;
}

std::string Passenger::Nationality() const
{
	return _nationality;
}

std::string Passenger::DateOfBirth() const
{
	return _dateOfBirth;
}

void Passenger::Print()
{
	std::cout << "Passenger: " << _name << ", " << _passport << std::endl;
}


