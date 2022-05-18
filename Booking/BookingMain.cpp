// Booking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BookingTable.h"

void SearchFlight(std::string flight, BookingTable bt);

void SearchFlightsBeforeTime(std::string time, BookingTable bt);

int main()
{

	BookingTable bt;

	
	bt.CreateBooking(Passenger("Alice"), "LHR->AMS", "May-26 06:45 2020");
	bt.CreateBooking(Passenger("Bruce"), "GVA->AMS->LHR", "Jun-04 11:04 2020");
	bt.CreateBooking(Passenger("Cindy"), "AAL->AMS->LHR->JFK->SFO", "Jun-06 10:00 2020");
	bt.CreateBooking(Passenger("Derek"), "AMS->LHR", "Jun-12 08:09 2020");
	bt.CreateBooking(Passenger("Erica"), "ATL->AMS->AAL", "Jun-13 20:40 2020");
	bt.CreateBooking(Passenger("Fred"), "AMS->CDG->LHR", "Jun-14 09:10 2020");

	
	SearchFlight("AMS->LHR", bt);

	SearchFlight("GVA->AMS", bt);

	SearchFlight("AAL->AMS", bt);

	SearchFlight("AMS->AAL", bt);

	SearchFlightsBeforeTime("Jun-04 11:04 2020", bt);

	SearchFlightsBeforeTime("Jun-14 09:10 2020", bt);

	SearchFlightsBeforeTime("Jun-15 09:10 2020", bt);

	getchar();

}

void SearchFlight(std::string flight, BookingTable bt)
{
	std::cout << "Search Flight " << flight << std::endl;
	BookingTable out = bt.SearchFlight(flight);
	out.Print();
	std::cout << "End Search Result\n************" << std::endl;
	std::cout << std::endl;
}

void SearchFlightsBeforeTime(std::string time, BookingTable bt)
{
	std::cout << "Search Flight before " << time << std::endl;
	BookingTable out = bt.SearchTimeLessThan(time);
	out.Print();
	std::cout << "End Search Result\n************" << std::endl;
	std::cout << std::endl;
}
