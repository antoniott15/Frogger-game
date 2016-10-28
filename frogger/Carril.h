#pragma once
#include "Area.h"
#include "lib\Grafic.h"
#include "Cua.h"

class Carril
{
	public:
			Carril();
			~Carril();
			Carril(Grafic grafic,int velocitat, bool direccio, int posY);
			Area getArea ();
			void dibuixa();
			void mouVehicleInici();
			void mouVehicle();
			
	private:
		bool m_dreta;
		Vehicle m_vehicle;
		Grafic m_graficVehicle;
		int m_posIniciY;
};
