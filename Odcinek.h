#pragma once
#include "Figura.h"
#include "Punkt.h"

namespace MojeFigury {
	class Odcinek : public Figura {
	private:
		Punkt poczatek, koniec;
	public:
		void rysuj() const override;
		void przesun(double dx, double dy) override;
		void skaluj(double skala) override;
		Odcinek(Punkt poczatek, Punkt koniec);
		
		class ZleKonce : public std::exception {
		public:
			const char* what() const override;
		};
	};
}