#include "Granota.h"

/**
 * Constructor per defecte.
 */
Granota::Granota()
{
}

/**
 * Constructor de la Granota.
 * @param grafic Grafic amb el que ilustrar la granota
 * @param posicioInicialX Posició inicial en coordenada horitzontal
 * @param posicioInicialY Posició inicial en coordenada vertical
 */
Granota::Granota(Grafic grafic, int posicioInicialX, int posicioInicialY)
{
	m_grafic[ESQUERRA][REPOS].crea("Program/data/GraficsGranota/Granota_Esquerra_1.png");
	m_grafic[ESQUERRA][MOVI].crea("Program/data/GraficsGranota/Granota_Esquerra_2.png");
	m_grafic[DRETA][REPOS].crea("Program/data/GraficsGranota/Granota_Dreta_1.png");
	m_grafic[DRETA][MOVI].crea("Program/data/GraficsGranota/Granota_Dreta_2.png");
	m_grafic[AMUNT][REPOS].crea("Program/data/GraficsGranota/Granota_Amunt_1.png");
	m_grafic[AMUNT][MOVI].crea("Program/data/GraficsGranota/Granota_Amunt_2.png");
	m_grafic[AVALL][REPOS].crea("Program/data/GraficsGranota/Granota_Avall_1.png");
	m_grafic[AVALL][MOVI].crea("Program/data/GraficsGranota/Granota_Avall_2.png");
	
	m_durada = T_MOVIMENT;
	m_estat = REPOS;
	m_direccio = AMUNT;
	m_grafic[m_direccio][m_estat] = grafic;
	m_posicioInicialX = posicioInicialX;
	m_posicioInicialY = posicioInicialY;
}

/**
 * Destructor per defecte.
 */
Granota::~Granota()
{
}

/**
 * Obté l'àrea ocupada per la granota.
 * @return Area ocupada
 */
Area Granota::getAreaOcupada()
{
	return Area(m_posicioX,m_posicioX+m_grafic[m_direccio][m_estat].getScaleX(),m_posicioY,m_posicioY+m_grafic[m_direccio][m_estat].getScaleY()); 
}

/**
 * Dibuixa la granota a la posició actual.
 */
void Granota::dibuixa()
{
	
		m_grafic[m_direccio][m_estat].dibuixa(m_posicioX,m_posicioY);
	
}


/**
 * Mou la granota cap a l'esquerra.
 */
void Granota::mouEsquerra()
{
	if (m_estat == REPOS)
	{
		m_estat = MOVI;
		m_direccio = ESQUERRA;
		//m_posicioMovX = m_posicioX- DESPLACAMENT_GRANOTA/2;
		m_posicioX -= DESPLACAMENT_GRANOTA;
	}
}

/**
 * Mou la granota cap a la dreta.
 */
void Granota::mouDreta()
{
	if (m_estat == REPOS)
	{
		m_estat = MOVI;
		m_direccio = DRETA;
		//m_posicioMovX = m_posicioX + DESPLACAMENT_GRANOTA/2;
		m_posicioX += DESPLACAMENT_GRANOTA;
	}
}

/**
 * Mou la granota cap amunt.
 */
void Granota::mouAmunt()
{
	if (m_estat == REPOS)
	{
		m_estat = MOVI;
		m_direccio = AMUNT;
		//m_posicioMovY =  m_posicioY - DESPLACAMENT_GRANOTA/2;
		m_posicioY -= DESPLACAMENT_GRANOTA;
	}
}

/**
 * Mou la granota cap avall.
 */
void Granota::mouAvall()
{
	if (m_estat == REPOS)
	{
		m_estat = MOVI;
		m_direccio = AVALL;
		//m_posicioMovY =  m_posicioY + DESPLACAMENT_GRANOTA/2;
		m_posicioY += DESPLACAMENT_GRANOTA;
	}
}


/**
 * Mou la granota a la seva posició inicial.
 */
void Granota::mouAPosicioInicial()
{
	m_posicioX = m_posicioInicialX;
	m_posicioY= m_posicioInicialY;

}

/**
 *Actualitza la posicio de la granota (permet la visualitzacio del moviment de les potes)
 */
void Granota::actualitza()
{
	if (m_estat == MOVI) 
	{
		m_durada --;
		if (m_durada == 0)
		{
			m_estat = REPOS;
			m_durada = T_MOVIMENT;
		}
	}
}


