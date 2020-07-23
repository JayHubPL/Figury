#include "Odcinek.h"
using namespace MojeFigury;

const char* Odcinek::ZleKonce::what() const {
	return "Podano nieprawidlowe konce odcinka!\n";
}

Odcinek::Odcinek(Punkt poczatek, Punkt koniec) : poczatek(poczatek), koniec(koniec) {
	if (poczatek == koniec) {
		throw Odcinek::ZleKonce();
	}
}

void Odcinek::rysuj() const {
	std::cout << "Rysuje odcinek o poczatku w punkcie " << poczatek << " i koncu w punkcie " << koniec << ".\n";
}

void Odcinek::przesun(double dx, double dy) {
	poczatek += Punkt(dx, dy);
	koniec += Punkt(dx, dy);
}

void Odcinek::skaluj(double skala) {
	if (skala <= 0) {
		throw Figura::ZlaSkala(skala, typeid(*this));
	}
	koniec = Punkt(poczatek.getX() + (koniec.getX() - poczatek.getX()) * skala, poczatek.getY() + (koniec.getY() - poczatek.getY()) * skala);
}
