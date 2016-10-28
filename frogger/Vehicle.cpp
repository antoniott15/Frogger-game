#include "Vehicle.h"
#include "Pantalla.h"




/**
 * Constructor per defecte.
 */
Vehicle::Vehicle()
{
}

/**
 * Constructor del Vehicle.
 * @param grafic Grafic amb el que ilustrar el vehicle
 * @param velocitat Velocitat de moviment
 */
Vehicle::Vehicle(Grafic grafic, int velocitat, bool direccio)
{
	m_grafic = grafic;
	m_velocitat = velocitat;
	m_dreta = direccio;
}

/**
 * Destructor per defecte.
 */
Vehicle::~Vehicle()
{
}

/**
 * Retorna l'area ocupada pel vehicle.
 */
Area Vehicle::getAreaOcupada()
{
	return Area(m_posicioX,m_posicioX+m_grafic.getScaleX(),m_posicioY,m_posicioY+m_grafic.getScaleY()); 
}

/**
 * Dibuixa el vehicle a la posició actual.
 */
void Vehicle::dibuixa()
{
	m_grafic.dibuixa(m_posicioX,m_posicioY);
}

/**
 * Mou el vehicle tenint en compte la velocitat d'aquest i la direccio en la que es mou.
 */
void Vehicle::mou()
{
	if (m_dreta) {
		m_posicioX += m_velocitat;
	}
	else m_posicioX -= m_velocitat;
}

/**
 * Mou el vehicle a l'inici d'un carril tenint en compte la direccio del vehicle.
 * @param iniciXCarril Coordenada X inicial del carril
 * @param iniciYCarril Coordenada Y del carril
 */
void Vehicle::mouAIniciCarril(int iniciXCarril, int iniciYCarril)
{
	m_posicioX = iniciXCarril;
	m_posicioY = iniciYCarril;
	if (m_dreta)
	{
		m_grafic.dibuixa(m_posicioX,m_posicioY);
	}
	else  m_grafic.dibuixa(FI_X-m_grafic.getScaleX(),m_posicioY);

}