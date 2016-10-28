#include "Pantalla.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

/**
 * Constructor de la Pantalla.
 * Aquesta pantalla té una sola cova imaginària ja que no té parets.
 */
Pantalla::Pantalla()
{
	// Carreguem els components gràfics a fer servir.
	m_graficFons.crea("Program/data/GraficsGranota/Fons.png");
	for (int i = 0; i < COVES; i++)
	{
		m_graficCoves[i].crea("Program/data/GraficsGranota/Cova120.png");
	}
	m_graficGranota.crea("Program/data/GraficsGranota/Granota_Amunt_1.png"); 
	
	// Inicialitzem l'area total de la pantalla, així com l'espai pels carrils, el número de carrils i instanciem els objectes granota i cova.
	m_areaTotal = Area(INICI_X, FI_X, INICI_Y, FI_Y);
	m_iniciCarrilsY = INICI_Y + m_graficCoves[0].getScaleY();
	m_granota = Granota(m_graficGranota, (FI_X - INICI_X - m_graficGranota.getScaleX())/2, FI_Y - m_graficGranota.getScaleY());

	for (int i = 0; i < COVES; i++)
	{
		m_cova[i] = Cova(m_graficCoves[i], INICI_X + m_graficCoves[0].getScaleX() * i, INICI_Y);
	}
	// Fixem l'hora actual com a llavor pel generador d'aleatoris.
	std::srand(std::time(0));

		//creacio dels grafics dels 5 vehicles diferents
		m_dirCarrils[0] = true;
		m_dirCarrils[1] = false;
		m_dirCarrils[2] = true;
		m_dirCarrils[3] = false;
		m_dirCarrils[4] = true;

		m_velCarrils[0] = DESPLACAMENT_COTXE + 2;
		m_velCarrils[1] = DESPLACAMENT_COTXE + 1;
		m_velCarrils[2] = DESPLACAMENT_COTXE + 4;
		m_velCarrils[3] = DESPLACAMENT_COTXE;
		m_velCarrils[4] = DESPLACAMENT_COTXE + 5;

	if (m_dirCarrils[0])
	{
		m_graficCarrils[0].crea("Program/data/GraficsGranota/Cotxe_1.png");
	}
	else m_graficCarrils[0].crea("Program/data/GraficsGranota/Cotxe_1Girat.png");

	if (m_dirCarrils[1])
	{
		m_graficCarrils[1].crea("Program/data/GraficsGranota/Camio.png");
	}
	else m_graficCarrils[1].crea("Program/data/GraficsGranota/CamioGirat.png");

	if (m_dirCarrils[2])
	{
		m_graficCarrils[2].crea("Program/data/GraficsGranota/Cotxe_3.png");
	}
	else m_graficCarrils[2].crea("Program/data/GraficsGranota/Cotxe_3Girat.png");

	if (m_dirCarrils[3])
	{
		m_graficCarrils[3].crea("Program/data/GraficsGranota/Tractor.png");
	}
	else m_graficCarrils[3].crea("Program/data/GraficsGranota/TractorGirat.png");

	if (m_dirCarrils[4])
	{
		m_graficCarrils[4].crea("Program/data/GraficsGranota/Cotxe_2.png");
	}
	else m_graficCarrils[4].crea("Program/data/GraficsGranota/Cotxe_2Girat.png");

}	

/**
 * Destructor per defecte
 */
Pantalla::~Pantalla()
{
	m_graficFons.destrueix();
	for (int i = 0; i < COVES; i++)
	{
		m_cova[i].~Cova();
	}
	m_graficGranota.destrueix();
	for (int i = 0; i < COVES; i++)
	{
		m_carrils[i].~Carril();
	}
}

/**
 * Inicia la pantalla instanciant l'objecte vehicle i colocant la granota i el vehicle a la posició inicial.
 * @param nivell Nivell de la pantalla.
 */
void Pantalla::inicia(int nivell)
{
	m_granota.mouAPosicioInicial();
	

	for (int i = 0; i < MAX_CARRILS; i++)
	{
		m_carrils[i] = Carril(m_graficCarrils[i],nivell*m_velCarrils[i]/2, m_dirCarrils[i], m_iniciCarrilsY + m_graficCarrils[1].getScaleY() * i * 1.8);
	}
	for (int i = 0; i < MAX_CARRILS; i++)
	{
		m_carrils[i].mouVehicleInici();
	}
}



/**
 * Comprova si la granota es troba dins d'una cova
 * @return true si la granota es troba dins d'alguna de les coves, false en cas contrari
 */
bool Pantalla::esGranotaDinsCova()
{
	return (m_cova[0].esDins(m_granota.getAreaOcupada()) || m_cova[1].esDins(m_granota.getAreaOcupada()) || m_cova[2].esDins(m_granota.getAreaOcupada()) || m_cova[3].esDins(m_granota.getAreaOcupada()) || m_cova[4].esDins(m_granota.getAreaOcupada()));
}

/**
 * Comprova si una àrea donada es troba dins l'espai permés de moviment.
 * @param area Area a comprovar si es troba dins l'espai permés de moviment.
 * @return true si l'àrea es troba dins l'espai permés de moviment i false si no és així.
 */
bool Pantalla::espaiPermes(Area area)
{
	return m_areaTotal.inclou(area);
}

/**
 * Dibuixa tots els elements grafics a la posició on es troben.
 */
void Pantalla::dibuixa()
{
	m_graficFons.dibuixa(0,0);
	for (int i = 0; i < COVES; i++)
	{
		m_cova[i].dibuixa();
	}

	m_granota.dibuixa();
	for (int i = 0; i < MAX_CARRILS; i++)
	{
		m_carrils[i].dibuixa();
	}
}

/**
 * Mou el vehicle.
 */
void Pantalla::mouVehicle()
{
	for (int i = 0; i < MAX_CARRILS; i++)
	{
		if (espaiPermes(m_carrils[i].getArea()))
		{
			m_carrils[i].mouVehicle();
		}
		else m_carrils[i].mouVehicleInici();
	}
}

/**
 * Comprova si la granota ha mort.
 * @return true si la granota és morta i false si és viva.
 */
bool Pantalla::haMortLaGranota()
{
	bool impacte = false;
	int i = 0;
	for (int i = 0; i < MAX_CARRILS; i++)
	{
		if (m_granota.getAreaOcupada().solapa(m_carrils[i].getArea()))
		{
			impacte = true;
		}
	}
	return impacte;
}

/**
 * Mou la granota en la direcció donada.
 * @param direccio Direcció cap on s'ha de moure la granota. Fer servir constants AMUNT, AVALL, DRETA i ESQUERRA.
 */
void Pantalla::mouGranota(int direccio)
{
	bool accessible = true;
		m_granotaAux = m_granota;
		switch(direccio) 
		{
		case AMUNT: m_granotaAux.mouAmunt();
			break;
		case AVALL: m_granotaAux.mouAvall();
			break;
		case DRETA: m_granotaAux.mouDreta();
			break;
		case ESQUERRA: m_granotaAux.mouEsquerra();
			break;
		}
		if (espaiPermes(m_granotaAux.getAreaOcupada()))
		{
			int i = 0;
			do
			{
				accessible = (m_cova[i].esAccessible(m_granotaAux.getAreaOcupada()));
					i++;
			}while (i < COVES && accessible);
				if(accessible)
					m_granota = m_granotaAux;	
		}
}

/**
 * Actualitza la posicio de la granota
 */
void Pantalla::actualitza()
{
	m_granota.actualitza();
}

/**
 * Comprova si totes les coves estan ocupades
 * @return true si totes les coves estan ocupades i false si no es aixi.
 */
bool Pantalla::nivellSuperat()
{
	return ((m_cova[0].esOcupada()) && (m_cova[1].esOcupada()) && (m_cova[2].esOcupada()) && (m_cova[3].esOcupada()) && (m_cova[4].esOcupada()));
}

/**
 * Mou la granota a la posicio inicial.
 */
void Pantalla::mouGranotaInici()
{
	m_granota.mouAPosicioInicial();
}

/**
 *Inicialitzacio de totes les coves com a buides
 */
void Pantalla::buidaCoves()
{
	for (int i = 0; i < COVES; i++)
	{
		m_cova[i].setBuida(false);
	}
}


