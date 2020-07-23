#include "Prostokat.h"
using namespace MojeFigury;

const char* Prostokat::ZleBoki::what() const {
	return "Podano nieprawidlowe dlugosci bokow prostokata!\n";
}

Prostokat::Prostokat(Punkt lgr, double a, double b) : lgr(lgr), a(a), b(b) {
	if (a <= 0 or b <= 0) {
		throw Prostokat::ZleBoki();
	}
}

void Prostokat::rysuj() const {
	std::cout << "Rysuje prostokat z lewym gornym rogiem w punkcie " << lgr << " i bokach o dlugosciach " << a << " oraz " << b << ".\n";
}

void Prostokat::przesun(double dx, double dy) {
	lgr += Punkt(dx, dy);
}

void Prostokat::skaluj(double skala) {
	if (skala <= 0) {
		throw Figura::ZlaSkala(skala, typeid(*this));
	}
	a *= skala;
	b *= skala;
}