/**
 * @author  Vincent AZINCOURT alias Wiiz
 * @file Pression.hpp
 * @date 07 oct. 2021
 * @brief Cette classe herite de la classe Sensor et renvoie une valeur
 * flottante qui correspond la pression atmosphérique à l'experieur du sous-marin ~10 kPa
 */


/**
 * Define  guards
 */
#ifndef HEADERS_PRESSION_HPP_
#define HEADERS_PRESSION_HPP_

/**
*Include
*/
#include "Sensor.hpp"
#include "DataType.hpp"

/**
 * @class Pression
 */

class Pression : public Sensor<int> {
	public:
	// Définition de la forme canonique
			/* construteur par defaut */
			Pression();
			/*constructeur par recopie*/
			Pression(const Pression& pression);
			/*constructeur par operateur = */
			Pression& operator=(const Pression& pression){
				this->m_data = pression.m_data;

					return *this;
				};
			/*destructeur*/
			~Pression(){};

			/**
			 * @fn DataType getData&()
			 * @brief Cette fonction renvoie la nouvele valeur de la pression atmosphérique capturé
			 * @return DataType
			 */
			DataType<int>& getData();
	};


#endif /* HEADERS_PRESSION_HPP_ */
