#pragma once
#include <string>
#include "IPrintable.h"


class Flight : public IPrintable
{

public:
	Flight(std::string m_origin, std::string m_destination);

	Flight(const Flight& other);

	Flight(Flight&& other) noexcept;

	Flight& operator=(const Flight& other);

	Flight& operator=(Flight&& other) noexcept;

	virtual ~Flight();

	friend bool operator==(const Flight& lhs, const Flight& rhs);

	friend bool operator!=(const Flight& lhs, const Flight& rhs);

	void Origin(const std::string& m_origin);

	void Destination(const std::string& m_destination);

	[[nodiscard]] std::string Origin() const;

	[[nodiscard]] std::string Destination() const;

	void Print() override;

private:
	std::string _origin;
	std::string _destination;
};


