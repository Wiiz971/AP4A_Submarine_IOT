/**
 * @author  Vincent AZINCOURT alias Wiiz
 * @file Sensor.hpp
 * @date 28 sept. 2021
 * @brief Cette classe doit vous permettre de generer les donnees qui devront etre
 * remontees via le Scheduler, au Server.
 */


/**
 * Define  guards
 */
#ifndef HEADERS_SENSOR_HPP_
#define HEADERS_SENSOR_HPP_

/**
*Include
*/

#include "DataType.hpp"
#include "SensorType.hpp"
#include <chrono>
#include <random>
#include <iostream>
#include <cmath>

using namespace std;

/**
 * @class sensor
 */

template<class T>class Sensor{

	protected :
		DataType<T> m_data;
	public :

		// Définition de la forme canonique
		/* construteur par defaut */
		Sensor(): m_data(){};
		/*constructeur par recopie*/
		Sensor(const Sensor& sensor): m_data(sensor.m_data){};
		/*constructeur par operateur = */
		Sensor& operator=(const Sensor& server){
		    this->m_data = server.m_data;

		    return *this;
		}
		/*destructeur*/
		virtual ~Sensor(){};

		/**
		 * @fn float aleaGenVal(const float&, const float&, const float&, const float&)
		 * @brief Cette fonction génère des nombres aléatoires
		 * @param min - valeur floattante minimale
		 * @param max - valeur floattante maximale
		 * @param previousData - Précédente données floattante enregistrée
		 * @param maxChange - Ecart maximale floattant encore acceptable
		 * @return float
		 */
		T aleaGenVal(const T& min, const T& max, const T& previousData, const T& maxChange){
		    // Si min > max, la méthode renvoie une exception de type domain_error
		    if(min > max) {
		        throw domain_error("aleaGenVal(): min > max");
		    }
		    // Si min > previousData, la méthode renvoie une exception de type domain_error
		    if(min > previousData) {
		        throw domain_error("aleaGenVal(): min > previousData");
		    }
		    // Si max < previousData, la méthode renvoie une exception de type domain_error
		    if(max < previousData) {
		        throw domain_error("aleaGenVal(): max < previousData");
		    }

		    T newData; // Nouvelle Data du capteur

			if (min == max)
			  return min;

			// Si tout va bien, on génère un entier
			newData = previousData + fmod(rand(), (previousData + maxChange) -  (previousData - maxChange));

		    if(newData < min) {
		        newData = min;
		    }else if(newData > max) {
		        newData = max;
		    }

		    return newData;
		};

		/**
		 * @fn DataType getData&()
		 * @brief Cette fonction renvoie les données relatives au sensor
		 * @return DataType
		 */
		DataType<T>& getData(){
			return this->m_data;
		}


		friend class temperature;
		friend class humidity;
		friend class light;
		friend class pression;
};


#endif /* HEADERS_SENSOR_HPP_ */
