/**
 * @author  Vincent AZINCOURT alias Wiiz
 * @file Scheduler.hpp
 * @date 09 oct. 2021
 * @brief Cette classe permet de definir la frequence a laquelle les
 * donnees des capteurs seront recuperees pour etre transmises au serveur.
 */

#ifndef HEADERS_SCHEDULE_HPP
#define HEADERS_SCHEDULE_HPP

/**
*Include
*/

/* Include de toutes les classes filles de Sensor
 * pour récupérer les données.
 * Include de Server pour pouvoir transmettre
 * ces données à ce dernier.
 * */
#include "Server.hpp"
#include "Temperature.hpp"
#include "Humidity.hpp"
#include "Pression.hpp"
#include "Light.hpp"
#include "Sensor.hpp"
#include <string>
#include <iostream>
#include <time.h>


using namespace std;


/**
 * @class Scheduler
 * @brief  Cette classe permet de definir la frequence a laquelle les
 * donnees des capteurs seront recuperees pour etre transmises au serveur.
 */
class Scheduler {
	private:

		Server m_server;

		bool _switch=true;

		Temperature m_temperature;
		Humidity m_humidity;
		Pression m_pression;
		Light m_light;



		// Tempe d'attente entre chaque récupération des données des capteurs
		unsigned int m_temperatureSleepTime;
		unsigned int m_humiditySleepTime;
		unsigned int m_pressionSleepTime;
		unsigned int m_lightSleepTime;

	public:
		/**
		 * @fn void getSensorData(void)
		 * @brief Récupère les données des différents capteurs
		 * @return void
		 */
		void getSensorData(void);

    	// Définition de la forme canonique
		/* construteur par defaut */
		Scheduler(): m_server(true, true, "../logs/"), m_temperature(), m_humidity(),
		m_pression(), m_light(), m_temperatureSleepTime(1000), m_humiditySleepTime(1500),
		m_pressionSleepTime(2000), m_lightSleepTime(2500){};
		/*constructeur par recopie*/
		Scheduler(const Scheduler& scheduler):m_server(scheduler.m_server), m_temperature(scheduler.m_temperature),
				 m_humidity(scheduler.m_humidity),m_pression(scheduler.m_pression), m_light(scheduler.m_light),
				m_temperatureSleepTime(scheduler.m_temperatureSleepTime),m_humiditySleepTime(scheduler.m_humiditySleepTime),
				m_pressionSleepTime(scheduler.m_pressionSleepTime),	m_lightSleepTime(scheduler.m_lightSleepTime){};
		/*constructeur par operateur = */
		Scheduler& operator=(const Scheduler& scheduler){
			this->m_server = scheduler.m_server;
			this->m_temperature = scheduler.m_temperature;
			this->m_humidity = scheduler.m_humidity;
			this->m_pression = scheduler.m_pression;
			this->m_light = scheduler.m_light;
			this->m_temperatureSleepTime = scheduler.m_temperatureSleepTime;
			this->m_humiditySleepTime = scheduler.m_humiditySleepTime;
			this->m_pressionSleepTime = scheduler.m_pressionSleepTime;
			this->m_lightSleepTime = scheduler.m_lightSleepTime;

			return *this;
		};
		/*destructeur*/
		virtual ~Scheduler(){};

};

#endif /* HEADERS_SCHEDULE_HPP */


