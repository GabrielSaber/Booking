#include <iostream>
#include <sstream>
#include <iomanip>
#include "algorithm"
#include "Itinerary.h"


void Itinerary::Add(Flight flight)
{
	_flightList.push_back(flight);
}

bool Itinerary::IsContain(std::string flight)
{
	bool bContain = false;

	auto airports = getAirports(flight);

	if(airports.size() == 2)
	{
		bContain = IsContain(Flight(airports[0], airports[1]));
	}

	return bContain;
	
}


bool Itinerary::IsContain(Flight flight)
{
	bool bContain = false;
	auto it= find(_flightList.begin(), _flightList.end(), flight);

	if(it != _flightList.end())
	{
		bContain = true;
	}

	return bContain;
}

void Itinerary::SetDateTime(std::string tString)
{
	_dateTime.SetTime(tString);
}

void Itinerary::SetFlights(std::string flights)
{

	auto airports = getAirports(flights);

	for(int i = 0; i < airports.size() -1; i++)
	{
		_flightList.push_back(Flight(airports[i], airports[i + 1]));
	}
}

DateTime Itinerary::GetDateTime()
{
	return _dateTime;
}

void Itinerary::Print()
{
	std::cout << "Itinerary :";
	_dateTime.Print();

	for(auto flight : _flightList)
	{
		flight.Print();
	}
}

std::vector<std::string> Itinerary::getAirports(std::string flights)
{
	std::vector<std::string> airports;

	const std::string delimiter = "->";
	size_t pos = 0;
	while ((pos = flights.find(delimiter)) != std::string::npos) 
	{
		std::string token = flights.substr(0, pos);
		airports.push_back(token);
		flights.erase(0, pos + delimiter.length());
	}
	airports.push_back(flights);

	return airports;
}

