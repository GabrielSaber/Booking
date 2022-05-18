#include "Booking.h"

#include <iostream>

void Booking::Print()
{
	_passenger.Print();
	_itinerary.Print();
}

Passenger Booking::GetPassenger() const
{
	return _passenger;
}

Itinerary Booking::GetItinerary() const
{
	return _itinerary;
}

void Booking::SetPassenger(const Passenger& passenger)
{
	_passenger = passenger;
}

void Booking::SetItinerary(const Itinerary& itinerary)
{
	_itinerary = itinerary;
}

void Booking::SetBooking(Passenger p, std::string flights, std::string time)
{
	_passenger = p;
	_itinerary.SetDateTime(time);
	_itinerary.SetFlights(flights);
}
