#include <iostream>

#include "Flight.h"


Flight::Flight(std::string m_origin, std::string m_destination) :
_origin(std::move(m_origin)),
_destination(std::move(m_destination))
{
}

Flight::Flight(const Flight& other):
_origin(other._origin),
_destination(other._destination)
{
}

Flight::Flight(Flight&& other) noexcept:
_origin(std::move(other._origin)),
_destination(std::move(other._destination))
{
}

Flight& Flight::operator=(const Flight& other)
{
	if (this == &other)
		return *this;
	_origin = other._origin;
	_destination = other._destination;
	return *this;
}

Flight& Flight::operator=(Flight&& other) noexcept
{
	if (this == &other)
		return *this;
	_origin = std::move(other._origin);
	_destination = std::move(other._destination);
	return *this;
}

Flight::~Flight() = default;


bool operator==(const Flight& lhs, const Flight& rhs)
{
	return lhs._origin == rhs._origin
		&& lhs._destination == rhs._destination;
}

bool operator!=(const Flight& lhs, const Flight& rhs)
{
	return !(lhs == rhs);
}

void Flight::Origin(const std::string& m_origin)
{
	this->_origin = m_origin;
}

void Flight::Destination(const std::string& m_destination)
{
	this->_destination = m_destination;
}

std::string Flight::Origin() const
{
	return _origin;
}

std::string Flight::Destination() const
{
	return _destination;
}

void Flight::Print()
{
	std::cout << "Flight: " << _origin << "->" << _destination << std::endl;
}
