#include <iostream>
#include <sstream>
#include <iomanip>
#include "DateTime.h"

DateTime::DateTime(const std::string& tmString)
{
	_datetime = { 0 };
	SetTime(tmString);
}

void DateTime::SetTime(const std::string& tmString)
{
	_tmString = tmString;
	std::istringstream timeSs(tmString);
	timeSs >> std::get_time(&_datetime, "%b-%d %H:%M %Y");
}

std::tm DateTime::GetTime()
{
	return _datetime;
}

std::string DateTime::GetTimeString()
{
	return _tmString;
}


bool operator==(const DateTime& lhs, const DateTime& rhs)
{
	std::tm lhsTm = lhs._datetime;
	std::tm rhsTm = rhs._datetime;
	time_t lhsTime = mktime(&lhsTm);
	time_t rhsTime = mktime(&rhsTm);

	double diffSecs = difftime(lhsTime, rhsTime); 

	return (diffSecs == 0);
}

bool operator!=(const DateTime& lhs, const DateTime& rhs)
{
	std::tm lhsTm = lhs._datetime;
	std::tm rhsTm = rhs._datetime;
	time_t lhsTime = mktime(&lhsTm);
	time_t rhsTime = mktime(&rhsTm);

	double diffSecs = difftime(lhsTime, rhsTime);

	return (diffSecs != 0);
}

bool operator<(const DateTime& lhs, const DateTime& rhs)
{
	std::tm lhsTm = lhs._datetime;
	std::tm rhsTm = rhs._datetime;
	time_t lhsTime = mktime(&lhsTm);
	time_t rhsTime = mktime(&rhsTm);

	double diffSecs = difftime(lhsTime, rhsTime);

	return (diffSecs < 0);
}

bool operator<=(const DateTime& lhs, const DateTime& rhs)
{
	std::tm lhsTm = lhs._datetime;
	std::tm rhsTm = rhs._datetime;
	time_t lhsTime = mktime(&lhsTm);
	time_t rhsTime = mktime(&rhsTm);

	double diffSecs = difftime(lhsTime, rhsTime);

	return !(diffSecs > 0);

}

bool operator>(const DateTime& lhs, const DateTime& rhs)
{
	std::tm lhsTm = lhs._datetime;
	std::tm rhsTm = rhs._datetime;
	time_t lhsTime = mktime(&lhsTm);
	time_t rhsTime = mktime(&rhsTm);

	double diffSecs = difftime(lhsTime, rhsTime);

	return (diffSecs > 0);
}

bool operator>=(const DateTime& lhs, const DateTime& rhs)
{
	std::tm lhsTm = lhs._datetime;
	std::tm rhsTm = rhs._datetime;
	time_t lhsTime = mktime(&lhsTm);
	time_t rhsTime = mktime(&rhsTm);

	double diffSecs = difftime(lhsTime, rhsTime);

	return !(diffSecs < 0);
}

void DateTime::Print()
{
	std::cout << "Time: " << _tmString << std::endl;
}
