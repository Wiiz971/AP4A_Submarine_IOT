/**
 * @author  Vincent AZINCOURT alias Wiiz
 * @file Light.hpp
 * @date 03 oct. 2021
 * @brief Cette classe herite de la classe Sensor et renvoie une valeur
 * flottante qui correspond au taux de luminosité dans le sous-marin [0 (faible)-100%(bien eclaire)]
 */


/**
 * Define  guards
 */
#ifndef HEADERS_LIGHT_HPP_
#define HEADERS_LIGHT_HPP_

/**
*Include
*/
#include "Sensor.hpp"
#include "DataType.hpp"

/**
 * @class Light
 */

class Light : public Sensor<bool> {
	public:
		// Définition de la forme canonique
		/* construteur par defaut */
		Light();
		/*constructeur par recopie*/
		Light(const Light& light);
		/*constructeur par operateur = */
		Light& operator=(const Light& light){
			this->m_data = light.m_data;

				return *this;
			};
		/*destructeur*/
		~Light(){};

		/**
		 * @fn DataType getData&()
		 * @brief Cette fonction renvoie le nouveau taux de lumiere capturé
		 * @return DataType
		 */
		DataType<bool>& getData();
};



#endif /* HEADERS_LIGHT_HPP_ */
