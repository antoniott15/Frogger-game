#include "Cova.h"

/**
 * Constructor per defecte.
 */
Cova::Cova()
{
}

/**
 * Constructor de la cova.
 * @param grafic Grafic ilustrant la cova
 * @param posicioX Coordenada horitzontal de la cova
 * @param posicioY Coordenada vertical de la cova
 */
Cova::Cova(Grafic grafic, int posicioX, int posicioY)
{
	m_estat = false;
	m_posicioX = posicioX;
	m_posicioY = posicioY;
	m_grafic = grafic;
	m_interior = Area(m_posicioX+AMPLADA_LATERAL, m_posicioX + m_grafic.getScaleX()-AMPLADA_LATERAL, m_posicioY+AMPLADA_LATERAL * 2, m_posicioY + m_grafic.getScaleY());
	m_lateralD = Area(m_posicioX, m_posicioX + AMPLADA_LATERAL, m_posicioY, m_posicioY + m_grafic.getScaleY());
	m_lateralE = Area(m_posicioX + m_grafic.getScaleX()-AMPLADA_LATERAL, m_posicioX + m_grafic.getScaleX(), m_posicioY, m_posicioY + m_grafic.getScaleY());
	m_graficGranota.crea("Program/data/GraficsGranota/Granota_Amunt_1.png"); 

}

/**
 * Destructor per defecte.
 */
Cova::~Cova(void)
{
}

/**
 * Dibuixa la cova a la seva posició.
 */
void Cova::dibuixa()
{
	m_grafic.dibuixa(m_posicioX, m_posicioY);
	if (m_estat)
	{
		m_graficGranota.dibuixa(m_posicioX+40,m_posicioY+30); 
	}
	
}

/**
 * Comprova si una àrea donada no es solapa amb cap paret de la cova.
 * @param area Area a comprovar
 * @returns true si l'àrea no es solapa amb cap parets de la cova.
 */
bool Cova::esAccessible(Area area)
{
	if (!esOcupada())
	{
		return !(m_lateralD.solapa(area) || m_lateralE.solapa(area));
	}
	else return !m_interior.solapa(area);
}

/*
 * Comprova si l'àrea donada es troba totalment a l'interior de la cova.
 * @param area Area a comprovar
 * @returns true si l'àrea es troba totalment dins la cova i false si no és així.
 */
bool Cova::esDins(Area area)
{	
	if (m_interior.inclou(area))
	{
		m_estat = true;
	}
	return m_interior.inclou(area);
}

/*
 * @returns true si la cova es troba ocupada, i false si no es aixi.
 */
bool Cova::esOcupada()
{
	return m_estat;
}

/*
 * Permet modificar si la cova esta ocupada o no
 * @param estat Estat de la cova, true = ocupada, flase = no ocupada
 */
void Cova::setBuida(bool estat)
{
	m_estat = estat;
}

/**
 * Obté l'àrea ocupada per la granota.
 * @return Area ocupada
 */
Area Cova::getAreaOcupada()
{
	return Area(m_posicioX,m_posicioX+m_grafic.getScaleX(),m_posicioY,m_posicioY+m_grafic.getScaleY()); 
}