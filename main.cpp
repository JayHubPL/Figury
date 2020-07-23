#include "Figura.h"
#include "Odcinek.h"
#include "Punkt.h"
#include "Trojkat.h"
#include "Prostokat.h"
#include "Okrag.h"
#include <iostream>

using namespace MojeFigury;

int main(void) {
	try {
		// tutaj leci dowolny kodzik do demonstracji
		Trojkat od(Punkt(1, 1), Punkt(5, 2), Punkt(2, 2));
		od.skaluj(-1);
		od.rysuj();
		// a tutaj sie konczy
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
	catch(...) {
		std::cerr << "Nieznany wyjatek!\n";
		exit(1);
	}
	return 0;
}