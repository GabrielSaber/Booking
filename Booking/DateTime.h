#pragma once
#include <string>
#include <ctime>
#include "IPrintable.h"

class DateTime : public  IPrintable
{
public:
	DateTime() = default;

	DateTime(const std::string& tmString);

	virtual ~DateTime() = default;


	void SetTime(const std::string& tmString);

	std::tm GetTime();

	std::string GetTimeString();

	friend bool operator==(const DateTime& lhs, const DateTime& rhs);

	friend bool operator!=(const DateTime& lhs, const DateTime& rhs);

	friend bool operator<(const DateTime& lhs, const DateTime& rhs);

	friend bool operator<=(const DateTime& lhs, const DateTime& rhs);

	friend bool operator>(const DateTime& lhs, const DateTime& rhs);

	friend bool operator>=(const DateTime& lhs, const DateTime& rhs);

	void Print() override;


private:
	std::string _tmString;
	std::tm _datetime;
};

