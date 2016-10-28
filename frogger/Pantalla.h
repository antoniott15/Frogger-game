#pragma once
#include "Area.h"
#include "lib\Grafic.h"
#include "Cova.h"
#include "Vehicle.h"
#include "Granota.h"
#include "Carril.h"
using namespace std;

// Inici del taulell respecte la cantonada superior esquerre
#define INICI_X 0
#define INICI_Y 0

// Fi del taulell respecte la cantonada superior esquerre
#define FI_X 600
#define FI_Y 450

#define AMUNT 0
#define AVALL 1
#define DRETA 2
#define ESQUERRA 3

#define COVES 5
#define MAX_CARRILS 5
#define DIRECCIO 2





class Pantalla
{
public:
	Pantalla();
	~Pantalla();
	void inicia(int nivell);
	void dibuixa();
	void mouGranota(int direccio);
	bool esGranotaDinsCova();
	void mouVehicle();
	bool haMortLaGranota();
	void actualitza();
	bool nivellSuperat();
	void mouGranotaInici();
	void buidaCoves();
	void getPuntuacio(int puntuacio);
private:
	Carril m_carrils[MAX_CARRILS];
	Grafic m_graficFons;
	Grafic m_graficCoves[COVES];
	Grafic m_graficCarrils[MAX_CARRILS];
	Grafic m_graficGranota;
	Area m_areaTotal;
	Cova m_cova[COVES];
	Granota m_granota;
	Granota m_granotaAux;
	int m_iniciCarrilsY;
	int m_nCarrils;
	int m_velCarrils[MAX_CARRILS];
	bool m_dirCarrils[MAX_CARRILS];
	bool espaiPermes(Area area);
};

