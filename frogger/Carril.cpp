#include "Pantalla.h"
#include "Carril.h"
/**
 * Constructor per defecte.
 */
Carril::Carril()
{
}

/**
 * Constructor del Carril.
 * @param velocitat Velocitat de moviment
 */

Carril::Carril(Grafic grafic, int velocitat, bool direccio, int posY)
{
	
	m_posIniciY = posY;
	m_dreta = direccio;
	m_graficVehicle = grafic;
	m_vehicle = Vehicle(m_graficVehicle, velocitat, m_dreta);
}

/**
 * Destructor per defecte.
 */
Carril::~Carril()
{
}

/**
*Retorna area ocupada per un dels vehicles
*@param num Numero de vehicle
*/
Area Carril::getArea()
{
	return m_vehicle.getAreaOcupada();
}

/**
*Dibuixa el vehicle 
*@num Numero del vehicle a dibuixar
*/
void Carril::dibuixa()
{
	m_vehicle.dibuixa();
}

/**
*Posa un vehicle a la posicio inicial
*@num Numero del vehicle a moure a inici
*@posY posicio Y inicial on comencen els carrils
*/
void Carril::mouVehicleInici()
{
	if (m_dreta)
	{
		 m_vehicle.mouAIniciCarril(INICI_X,m_posIniciY);
	}
	else m_vehicle.mouAIniciCarril(FI_X-m_graficVehicle.getScaleX(), m_posIniciY);
}

/**
*Moviment de un vehicle
*@num Numero del vehicle a moure
*/
void Carril::mouVehicle()
{
		m_vehicle.mou();
}




