/**
 * @author  Vincent AZINCOURT alias Wiiz
 * @file DataType.hpp
 * @date 01 oct. 2021
 * @brief Cette classe vous permet de manipuler les sorties de chaque capteur.
 */

/**
 * Define  guards
 */
#ifndef HEADERS_DATATYPE_HPP_
#define HEADERS_DATATYPE_HPP_

/**
*Include
*/
#include "SensorType.hpp"

/**
 *@class  DataType
 *@brief  Cette classe type les valeurs de sortie des capteurs
 */
template<class T>class DataType {
	private:
		T m_data; // stocke les données du sensor
		SensorType m_SensorType;

	public:
		// Définition de la forme canonique
		/* construteur par defaut */
		DataType<T>(): m_data(0), m_SensorType(e_unknown_type){};
		/*constructeur par recopie*/
		DataType<T>(const DataType<T>& Datatype): m_data(Datatype.m_data), m_SensorType(Datatype.m_SensorType){};
		/*constructeur par operateur = */
		DataType<T>& operator=(const DataType<T>& datatype){
			this->m_data = datatype.m_data;
			this->m_SensorType = datatype.m_SensorType;

			return *this;
		}
		/* destructeur*/
		virtual ~DataType<T>(){};

		 /**
		 * @brief Appel du constructeur de la classe DataType
		 * @return DataType
		 * @param data - Data des capteurs
		 * @param sensor - Type/nom du capteur
		 */
		DataType<T>(const float& data, const SensorType& sensor): m_data(data), m_SensorType(sensor){};


		/**
		 * @brief Cette fonction renvoie m_data
		 * @return float
		 */
		T getData(){
			return this->m_data;
		}

		/**
		 * @brief Cette fonction permet de modifier le m_data d'un DataType
		 * @return void
		 * @param data - nouvelle valeur de m_data
		 */
		void setData(const T& data){
			this->m_data = data;
		}

		/**
		 * @brief Cette fonction renvoie m_SensorType
		 * @return TypeSensor
		 */
		SensorType getSensorType(){
			return this->m_SensorType;
		}

		/**
		 * @brief Cette fonction permet de modifier le m_SensorType d'un DataType
		 * @return void
		 * @param sensortype - nouveau m_SensorType
		 */
		void setSensorType(const SensorType& sensortype){
			this->m_SensorType = sensortype;
		}

};



#endif /* HEADERS_DATATYPE_HPP_ */
