#include "Okrag.h"
using namespace MojeFigury;

const char* Okrag::ZlyPromien::what() const {
	return "Podano nieprawidlowy promien dla okregu!\n";
}

Okrag::Okrag(Punkt srodek, double promien) : srodek(srodek), promien(promien) {
	if (promien <= 0) {
		throw Okrag::ZlyPromien();
	}
}

void Okrag::rysuj() const {
	std::cout << "Rysuje okrag o srodku w punkcie " << srodek << " i promieniu " << promien << ".\n";
}

void Okrag::przesun(double dx, double dy) {
	srodek += Punkt(dx, dy);
}
void Okrag::skaluj(double skala) {
	if (skala <= 0) {
		throw Figura::ZlaSkala(skala, typeid(*this));
	}
	promien *= skala;
}