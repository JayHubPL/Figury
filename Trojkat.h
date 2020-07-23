#pragma once
#include "Figura.h"
#include "Punkt.h"

namespace MojeFigury {
	class Trojkat : public Figura {
	private:
		Punkt p1, p2, p3;
	public:
		void rysuj() const override;
		void przesun(double dx, double dy) override;
		void skaluj(double skala) override;
		Trojkat(Punkt p1, Punkt p2, Punkt p3);

		class ZleWierzcholki : public std::exception {
		public:
			const char* what() const override;
		};
	};
}