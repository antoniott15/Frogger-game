#include "Joc.h"
#include "lib\libreria.h"
#include <stdlib.h>
#include "lib\event.h"
#include "lib\Grafic.h"
#include "Pantalla.h"
#include <time.h>



/**
 * Juga una partida de tres vides
 *
 * @param nivell nivell de la partida
 * @return
 */
int juga(int dificultat)
{
	
	t_programStatus estat;
	InitGame (estat); // inicialitzacions de les llibreries
	
	int nivell = 1;
	int punts = 0; // Punts acumulats durant la partida
	int vides = 3; // Vides que li queden a la granot

	Pantalla pantalla;

	

	//grafics nivell, temps i punts
	Grafic level;
	level.crea("Program/data/numeros/nivell.png");
	Grafic mostra_Punts;
	mostra_Punts.crea("Program/data/numeros/punts.png");
	Grafic mostra_Temps;
	mostra_Temps.crea("Program/data/numeros/temps.png");

	//grafics numeros

	Grafic numero[MAX_NUM];
	numero[0].crea("Program/data/numeros/Numero0000.png");
	numero[1].crea("Program/data/numeros/Numero0001.png");
	numero[2].crea("Program/data/numeros/Numero0002.png");
	numero[3].crea("Program/data/numeros/Numero0003.png");
	numero[4].crea("Program/data/numeros/Numero0004.png");
	numero[5].crea("Program/data/numeros/Numero0005.png");
	numero[6].crea("Program/data/numeros/Numero0006.png");
	numero[7].crea("Program/data/numeros/Numero0007.png");
	numero[8].crea("Program/data/numeros/Numero0008.png");
	numero[9].crea("Program/data/numeros/Numero0009.png");
	
	//grafic vides
	Grafic granota_vida1;
	granota_vida1.crea("Program/data/GraficsGranota/Granota_Amunt_2.png");


	// Grafics objectes aleatoris
	Grafic objecte[MAX_OBJECTES];
	objecte[0].crea("Program/data/GraficsGranota/Granota_Avall_2.png");
	objecte[1].crea("Program/data/GraficsGranota/Granota_Avall_2.png");
	objecte[2].crea("Program/data/GraficsGranota/Granota_Avall_2.png");
	objecte[3].crea("Program/data/GraficsGranota/Granota_Avall_2.png");
	objecte[4].crea("Program/data/GraficsGranota/Granota_Avall_2.png");

	Video_ShowWindow(); //mostra finestra del joc
	

	
	int posicioVida1X = (FI_X - 200);
	int posicioVida1Y = FI_Y + 5;
	
	do
	{
		
	//inicialitzacio nivell
	pantalla.inicia(nivell+dificultat/2);
	bool nivellSuperat = false;
	pantalla.buidaCoves();
	
		
		do
	    {
			int objApareguts = 0;
			bool haMortLaGranota = false;
			int t_inicial = time(0);
			int t_lim = TEMPS_LIMIT;
			bool esDinsCova = false;

			//inicialitzacio granota
			pantalla.mouGranotaInici();

		do {
			ProcessEvents (estat); // Captura els events que s'han produit en el darrer cicle
		pantalla.dibuixa();

		//mostrar nivell
		level.dibuixa(INICI_X + 35, FI_Y + 10);
		numero[0].dibuixa(INICI_X + 85, FI_Y + 12);
		numero[nivell].dibuixa(INICI_X + 100, FI_Y + 12);

		//mostrar vides
		for (int i = vides-1; i >= 0; i --)
		{
			granota_vida1.dibuixa(posicioVida1X+granota_vida1.getScaleX()*i*1.5,posicioVida1Y);
		}

		int t_iteracio = time(0);
		t_lim = TEMPS_LIMIT - (t_iteracio - t_inicial);

		//mostrar temps limit
		int num1 = t_lim/10;
		int num2 = t_lim % 10;

		mostra_Temps.dibuixa(INICI_X + 275, FI_Y + 10);
		numero[num1].dibuixa(INICI_X + 335, FI_Y + 10);
		numero[num2].dibuixa(INICI_X + 348, FI_Y + 10);

		//mostrar puntuacio
		int punt1 = punts/100;
		int punt2 = (punts / 10) % 10;
		int punt3= punts % 10;
		mostra_Punts.dibuixa(INICI_X + 185, FI_Y + 10);
		numero[punt1].dibuixa(INICI_X + 235, FI_Y + 10);
		numero[punt2].dibuixa(INICI_X + 248, FI_Y + 10);
		numero[punt3].dibuixa(INICI_X + 260, FI_Y + 10);
		
		

		if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
		{
				// Movem la granota cap a l'esquerra
				pantalla.mouGranota(ESQUERRA); 
		}
		if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
		{
				// Movem la granota cap a la dreta
				pantalla.mouGranota(DRETA);
		}
		if (Keyboard_GetKeyTrg(KEYBOARD_UP))
		{
				//movem la granota cap a dalt
				pantalla.mouGranota(AMUNT);
				if (pantalla.esGranotaDinsCova())
				{
					esDinsCova = true;
				}
		}

		if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
		{
				//movem la granota cap a baix
				pantalla.mouGranota(AVALL);
		}

		if (pantalla.haMortLaGranota())
		{
			haMortLaGranota = true;
		}

		if (t_lim <= 0)
		{
			//perds una vida
			haMortLaGranota = true;
			t_lim = TEMPS_LIMIT;
		}

		//pantalla.mouVehicle();
		pantalla.actualitza();
		VideoUpdate(estat); // Actualitza la pantalla

		} while ((!esDinsCova) && (!haMortLaGranota) && (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE)) && (!estat.bExit));

		if (esDinsCova)
			punts = punts + 10 * nivell;
			nivellSuperat = pantalla.nivellSuperat();
		if (haMortLaGranota)
			vides--;

		} while ((!nivellSuperat) && (vides > 0) && (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE)) && (!estat.bExit));

		if (nivellSuperat)
		{
			punts = punts + (100 * nivell);
			nivell ++;
		}
			
		
        } while ((nivell < 4) && (vides > 0) && (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE)) && (!estat.bExit));

	granota_vida1.destrueix();
	return punts;
	Video_Release(); // allibera i tanca la finestra del joc
}




