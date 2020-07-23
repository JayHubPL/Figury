#pragma once
#include <exception>
#include <typeinfo>
#include <iostream>

namespace MojeFigury {
	class Figura {
	public:
		virtual void rysuj() const = 0;
		virtual void przesun(double dx, double dy) = 0;
		virtual void skaluj(double skala) = 0;

		class ZlaSkala : public std::exception {
		private:
			double skala;
			std::string klasa;
		public:
			void komunikat() const {
				std::cerr << "Nieprawidlowa wartosc skali (" << skala << ") przy wywolaniu metody skaluj() na obiekcie typu " + klasa + ".\n";
			}
			ZlaSkala(double skala, const std::type_info& gdzie) : skala(skala) {
				klasa = gdzie.name();
			}
		};
	};
}