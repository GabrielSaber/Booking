#pragma once
#include <vector>
#include "IPrintable.h"
#include "DateTime.h"
#include "Flight.h"


class Itinerary : public IPrintable
{
public:
	Itinerary() = default;

	virtual ~Itinerary() = default;

	void Add(Flight flight);

	bool IsContain(std::string flight);

	bool IsContain (Flight flight);

	void SetDateTime(std::string tString);

	void SetFlights(std::string flights);

	DateTime GetDateTime();

	void Print() override;

private:

	std::vector<std::string> getAirports(std::string flights);

	std::vector<Flight> _flightList;
	DateTime _dateTime;
};

