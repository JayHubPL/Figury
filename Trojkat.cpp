#include "Trojkat.h"
#include <cmath>
using namespace MojeFigury;

const char* Trojkat::ZleWierzcholki::what() const {
	return "Podano nieprawidlowe wierzcholki trojkata!\n";
}

Trojkat::Trojkat(Punkt p1, Punkt p2, Punkt p3) : p1(p1), p2(p2), p3(p3) {
	const double epsilon = 1e-8;
	if(p1 == p2 or p1 == p3 or p2 == p3 or (std::abs((p2.getX()-p1.getX())*(p3.getY()-p1.getY())-(p2.getY()-p1.getY())*(p3.getX()-p1.getX())) < epsilon)) {
		throw Trojkat::ZleWierzcholki();
	}
}

void Trojkat::rysuj() const {
	std::cout << "Rysuje trojkat o wierzcholkach: " << p1 << ", " << p2 << ", " << p3 << ".\n";
}

void Trojkat::przesun(double dx, double dy) {
	p1 += Punkt(dx, dy);
	p2 += Punkt(dx, dy);
	p3 += Punkt(dx, dy);
}

void Trojkat::skaluj(double skala) {
	if (skala <= 0) {
		throw Figura::ZlaSkala(skala, typeid(*this));
	}
	p2 = Punkt(p1.getX() + (p2.getX() - p1.getX()) * skala, p1.getY() + (p2.getY() - p1.getY()) * skala);
	p3 = Punkt(p1.getX() + (p3.getX() - p1.getX()) * skala, p1.getY() + (p3.getY() - p1.getY()) * skala);
}