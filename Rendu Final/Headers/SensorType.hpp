/**
 * @author  Vincent AZINCOURT alias Wiiz
 * @file SensorType.hpp
 * @date 01 oct. 2021
 * @brief Cette classe vous permet d'enumérer(enum) la liste les types de capteurs existants.
 */

/**
 * Define  guards
 */
#ifndef HEADERS_SENSORTYPE_HPP_
#define HEADERS_SENSORTYPE_HPP_


/**
 * @brief types (names) du sensor
 */

enum SensorType{
	e_unknown_type, //=1
	e_temperature, //=2...
	e_humidity,
	e_light,
	e_pression
};


#endif /* HEADERS_SENSORTYPE_HPP_ */
