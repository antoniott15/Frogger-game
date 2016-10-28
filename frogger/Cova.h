#pragma once
#include "Area.h"
#include "lib\Grafic.h"
#include "Granota.h"

#define AMPLADA_LATERAL 10
#define INICI_X 0
#define INICI_Y 0


class Cova
{
public:
	Cova();
	Cova(Grafic grafic, int posicioX, int posicioY);
	~Cova();
	void Cova::dibuixa();
	bool esAccessible(Area area);
	bool esDins(Area area);
	bool esOcupada();
	void setBuida(bool estat);
	Area getAreaOcupada();
private:
	int m_posicioX;
	int m_posicioY;
	Grafic m_grafic;
	Area m_lateralD;
	Area m_lateralE;
	Area m_interior;
	bool m_estat;
	Grafic m_graficGranota;
};

