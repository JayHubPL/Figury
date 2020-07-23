#pragma once
#include "Figura.h"
#include "Punkt.h"

namespace MojeFigury {
	class Prostokat : public Figura {
	private:
		Punkt lgr;
		double a, b;
	public:
		void rysuj() const override;
		void przesun(double dx, double dy) override;
		void skaluj(double skala) override;
		Prostokat(Punkt lgr, double a, double b);

		class ZleBoki : public std::exception {
		public:
			const char* what() const override;
		};
	};
}