#include "Figura.h"
#include "Odcinek.h"
#include "Punkt.h"
#include "Trojkat.h"
#include "Prostokat.h"
#include "Okrag.h"
#include <iostream>

using namespace MojeFigury;

class ZlyZakres : public std::exception {
public:
	const char* what() const {
		return "Nieprawidlowe odwolanie do elementu kontenera poza zakresem!\n";
	}
};

template<class T, std::size_t N> class Kontener {
	T** tab;
	std::size_t rozmiar;
	int liczbaElem;
public:
	T*& operator[] (int el) {
		if (el >= 0 and el < rozmiar) {
			return *(tab + el);
		}
		throw ZlyZakres();
	}
	Kontener() {
		rozmiar = N;
		liczbaElem = 0;
		try {
			tab = new T* [rozmiar];
		}
		catch (...) {
			std::cerr << "Alokacja pamieci nie powiodla sie!\n";
			exit(0);
		}
		for (int i = 0; i < rozmiar; ++i) {
			*(tab + i) = NULL;
		}
	}
	~Kontener() {
		for (int i = 0; i < rozmiar; ++i) {
			delete *(tab + i);
		}
		delete[] tab;
		tab = NULL;
	}
};

int main(void) {
	try {
		// statyczna alokacja pamieci
		Okrag okrag(Punkt(2, 2), 5);
		okrag.rysuj();
		okrag.skaluj(.1);
		okrag.przesun(3, -0.4);
		okrag.rysuj();
		// dynamiczna alokacja pamieci
		Prostokat* prostokat = new Prostokat(Punkt(3, -1), 4, 6);
		prostokat->rysuj();
		prostokat->skaluj(.1);
		prostokat->przesun(3, -0.4);
		prostokat->rysuj();
		delete prostokat;
		// uzycie kontenera oraz polimorfizmu
		const int N = 4;
		Kontener<Figura, N> k;
		k[0] = new Odcinek(Punkt(5, 1), Punkt(1, 3));
		k[1] = new Trojkat(Punkt(7, 1), Punkt(1, 3), Punkt(3, 1));
		k[2] = new Prostokat(Punkt(1, 1), 3, 5);
		k[3] = new Okrag(Punkt(1, 1), 7);
		for (int i = 0; i < N; ++i) {
			k[i]->rysuj();
			k[i]->skaluj(.5);
			k[i]->przesun(1.2, 5.4);
			k[i]->rysuj();
		}
	}
	catch (Odcinek::ZleKonce& zk) {
		std::cerr << zk.what();
	}
	catch (Trojkat::ZleWierzcholki& zw) {
		std::cerr << zw.what();
	}
	catch (Prostokat::ZleBoki& zb) {
		std::cerr << zb.what();
	}
	catch (Okrag::ZlyPromien& zp) {
		std::cerr << zp.what();
	}
	catch (Figura::ZlaSkala& zs) {
		zs.komunikat();
	}
	catch (ZlyZakres& zz) {
		std::cerr << zz.what();
	}
	catch (...) {
		std::cerr << "Nieznany wyjatek!\n";
		exit(1);
	}
	return 0;
}