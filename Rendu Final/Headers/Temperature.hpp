/**
 * @author  Vincent AZINCOURT alias Wiiz
 * @file Temperature.hpp
 * @date 03 oct. 2021
 * @brief Cette classe hérite de la classe Sensor et renvoie une valeur
 * flottante qui correspond a la température sous-marine (~20°C)
 */


/**
 * Define  guards
 */
#ifndef HEADERS_TEMPERATURE_HPP_
#define HEADERS_TEMPERATURE_HPP_

/**
*Include
*/
#include "Sensor.hpp"
#include "DataType.hpp"

/**
 * @class Temperature
 */

class Temperature: public Sensor<float>{
	public:
	// Définition de la forme canonique
	/* construteur par defaut */
	Temperature();
	/*constructeur par recopie*/
	Temperature(const Temperature& temperature);
	/*constructeur par operateur = */
	Temperature& operator=(const Temperature& temperature){
		this->m_data = temperature.m_data;

		    return *this;
		};
	/*destructeur*/
	~Temperature(){};

	/**
	 * @fn DataType getData&()
	 * @brief Cette fonction renvoie la nouvelle température
	 * @return DataType
	 */
	DataType<float>& getData();
};

#endif /* HEADERS_TEMPERATURE_HPP_ */
