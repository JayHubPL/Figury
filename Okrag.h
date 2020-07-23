#pragma once
#include "Figura.h"
#include "Punkt.h"

namespace MojeFigury {
	class Okrag : public Figura {
	private:
		Punkt srodek;
		double promien;
	public:
		void rysuj() const override;
		void przesun(double dx, double dy) override;
		void skaluj(double skala) override;
		Okrag(Punkt srodek, double promien);

		class ZlyPromien : public std::exception {
		public:
			const char* what() const override;
		};
	};
}
