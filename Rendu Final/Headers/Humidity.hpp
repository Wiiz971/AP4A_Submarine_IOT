/**
 * @author  Vincent AZINCOURT alias Wiiz
 * @file Humidity.hpp
 * @date 03 oct. 2021
 * @brief Cette classe hérite de la classe Sensor et renvoie une valeur
 * flottante (que l'on precise) qui correspond a l'humidite dans le sous-marin (~50.0%)
 */


/**
 * Define  guards
 */
#ifndef HEADERS_HUMIDITY_HPP_
#define HEADERS_HUMIDITY_HPP_

/**
*Include
*/
#include "Sensor.hpp"
#include "DataType.hpp"

/**
 * @class Humidity
 */

class Humidity : public Sensor<float> {
	public:
		// Définition de la forme canonique
		/* construteur par defaut */
		Humidity();
		/*constructeur par recopie*/
		Humidity(const Humidity& humidity);
		/*constructeur par operateur = */
		Humidity& operator=(const Humidity& humidity){
			this->m_data = humidity.m_data;

				return *this;
			};
		/*destructeur*/
		~Humidity(){};

		/**
		 * @fn DataType getData&()
		 * @brief Cette fonction renvoie la nouvelle Humidité capturée
		 * @return DataType
		 */
		DataType<float>& getData();
};
#endif /* HEADERS_HUMIDITY_HPP_ */
