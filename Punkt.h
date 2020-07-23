#pragma once
#include <iostream>

namespace MojeFigury {

	class Punkt {
	private:
		double x, y;
	public:
		Punkt& operator+=(const Punkt& p);
		void rysuj() const;
		void przesun(double dx, double dy);
		double getX() const;
		double getY() const;
		Punkt(double x, double y);
	};

	bool operator==(const Punkt& p1, const Punkt& p2);
	std::ostream& operator<<(std::ostream& os, const Punkt& o);
}