#pragma once
#include "IPrintable.h"
#include "Passenger.h"
#include "Itinerary.h"

class Booking : public IPrintable
{
public:
	Booking() = default;
	virtual ~Booking() = default;

	void Print() override;

	[[nodiscard]] Passenger GetPassenger() const;
	[[nodiscard]] Itinerary GetItinerary() const;

	void SetPassenger(const Passenger& passenger);
	void SetItinerary(const Itinerary& itinerary);

	void SetBooking(Passenger p, std::string flights, std::string time);

private:
	Passenger _passenger;
	Itinerary _itinerary;
};

