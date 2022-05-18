#pragma once
#include "Booking.h"
#include "DateTime.h"
#include "Flight.h"
#include "IPrintable.h"


class BookingTable : public IPrintable
{

public:
	BookingTable() = default;

	virtual ~BookingTable() = default;

	void Add(Booking booking);

	BookingTable SearchTime(std::string dtString);

	BookingTable SearchTimeLessThan(std::string dtString);

	BookingTable SearchFlight(std::string flight);

	void CreateBooking(Passenger p, std::string flights, std::string time);

	void Print() override;


private:
	std::vector<Booking> _table;
};

