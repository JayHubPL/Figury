#include "Punkt.h"
using namespace MojeFigury;

Punkt::Punkt(double x = 0, double y = 0) : x(x), y(y) { }

namespace MojeFigury {
	std::ostream& operator<<(std::ostream& os, const Punkt& o) {
		os << "(" << o.getX() << ", " << o.getY() << ")";
		return os;
	}

	bool operator==(const Punkt& p1, const Punkt& p2) {
		return (p1.getX() == p2.getX() and p1.getY() == p2.getY());
	}
}

Punkt& Punkt::operator+=(const Punkt& p) {
	(*this).x += p.x;
	(*this).y += p.y;
	return *this;
}

void Punkt::rysuj() const {
	std::cout << "Rysuje punkt o wspolrzednych " << (*this) << ".\n";
}

void Punkt::przesun(double dx, double dy) {
	x += dx;
	y += dy;
}

double Punkt::getX() const {
	return x;
}

double Punkt::getY() const {
	return y;
}
