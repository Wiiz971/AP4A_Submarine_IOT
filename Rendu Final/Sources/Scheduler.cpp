/**
 * @author  Vincent AZINCOURT alias Wiiz
 * @file Scheduler.cpp
 * @date 09 oct. 2021
 * @brief Cette classe permet de definir la frequence a laquelle les
 * donnees des capteurs seront recuperees pour etre transmises au serveur.
 */

#include "../Headers/Scheduler.hpp"
#include "../Headers/Server.hpp"
#include "../Headers/Temperature.hpp"
#include "../Headers/Humidity.hpp"
#include "../Headers/Pression.hpp"
#include "../Headers/Light.hpp"
#include "../Headers/Sensor.hpp"
#include <iostream>
#include <windows.h>


void Scheduler::getSensorData()
{


	/*Message de début de scheduler*/
	cout << "Debut du scheduler ...\n\n"<< "Récupération des données... :\n";

	time_t t,h,l,p;
	unsigned int x = time(&t);
	unsigned int y= time(&h);
	unsigned int z = time(&l);
	unsigned int w = time(&p);

	while(_switch){
		if(time(&h)-y>= m_humiditySleepTime){
			m_server.receiveData(m_humidity.getData());
			y=time(&h);
		}
		if(time(&h)-x>= m_humiditySleepTime){
			m_server.receiveData(m_temperature.getData());
			x=time(&t);
		}
		if(time(&h)-z>= m_humiditySleepTime){
			m_server.receiveData(m_light.getData());
			z=time(&l);
		}
		if(time(&h)-w>= m_humiditySleepTime){
			m_server.receiveData(m_pression.getData());
			w=time(&p);
		}


		//Cette fonction permet de vider le buffer
		fflush(stdout);


		if(GetKeyState(32) & 0x8000 ){//Si on appuie sur la touche espace du clavier => exit

			_switch=false;// On sort de la boucle si l'utilisateur clique sur espace.
			cout<<"Fin du scheduler";
		}
	}
}

