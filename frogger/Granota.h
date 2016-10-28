#pragma once
#include "Area.h"
#include "lib\Grafic.h"

#define MOVI 0
#define REPOS 1

#define T_MOVIMENT 4

#define DIRECCIONS 4
#define ESTATS 2

#define AMUNT 0
#define AVALL 1
#define DRETA 2
#define ESQUERRA 3



// nº de píxels que es desplaça la granota a cada moviment
#define DESPLACAMENT_GRANOTA 20


class Granota
{
public:
	Granota();
	Granota(Grafic grafic, int posicioInicialX, int posicioInicialY);
	~Granota();
	Area getAreaOcupada();
	void dibuixa();
	void mouAmunt();
	void mouAvall();
	void mouDreta();
	void mouEsquerra();
	void mouAPosicioInicial();
	void actualitza();

private:
	int m_estat;
	int m_direccio;
	Grafic m_grafic[DIRECCIONS][ESTATS];
	int m_posicioX;
	int m_posicioY;
	int m_posicioInicialX;
	int m_posicioInicialY;
	int m_posicioMovX;
	int m_posicioMovY;
	int m_durada;
};

