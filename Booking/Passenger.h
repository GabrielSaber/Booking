#pragma once
#include <string>
#include "IPrintable.h"

class Passenger : public IPrintable
{
public:
	Passenger() = default;
	explicit Passenger(std::string name);

	virtual ~Passenger() = default;
	void Name(const std::string& m_name);
	void Passport(const std::string& m_passport);
	void Nationality(const std::string& m_nationality);
	void DateOfBirth(const std::string& m_date_of_birth);

	[[nodiscard]] std::string Name() const;
	[[nodiscard]] std::string Passport() const;
	[[nodiscard]] std::string Nationality() const;
	[[nodiscard]] std::string DateOfBirth() const;

	void Print() override;

private:
	std::string _name;
	std::string _passport;
	std::string _nationality;
	std::string _dateOfBirth;
};

