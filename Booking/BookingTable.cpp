#include "BookingTable.h"
#include <iostream>

void BookingTable::Add(Booking booking)
{
	_table.push_back(booking);
}

BookingTable BookingTable::SearchTime(std::string dtString)
{
	BookingTable bookingTable;
	DateTime dt(dtString);

	for (auto& booking : _table) 
	{
		if (booking.GetItinerary().GetDateTime() == dt) 
		{
			bookingTable.Add(booking);
		}
	}

	return bookingTable;
}

BookingTable BookingTable::SearchTimeLessThan(std::string dtString)
{
	BookingTable bookingTable;
	DateTime dt(dtString);

	for (auto& booking : _table)
	{
		if (booking.GetItinerary().GetDateTime() < dt)
		{
			bookingTable.Add(booking);
		}
	}

	return bookingTable;
}

BookingTable BookingTable::SearchFlight(std::string flight)
{
	BookingTable bookingTable;

	for (auto& booking : _table)
	{
		if (booking.GetItinerary().IsContain(flight))
		{
			bookingTable.Add(booking);
		}
	}

	return bookingTable;
}

void BookingTable::CreateBooking(Passenger p, std::string flights, std::string time)
{
	Booking booking;
	booking.SetBooking(p, flights, time);
	_table.push_back(booking);
}

void BookingTable::Print()
{
	for (auto booking : _table)
	{
		booking.Print();
		std::cout << "---------" << std::endl;
	}
}
