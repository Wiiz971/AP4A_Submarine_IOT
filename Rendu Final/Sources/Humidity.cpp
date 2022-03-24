/**
 * @author  Vincent AZINCOURT alias Wiiz
 * @file Humidity.cpp
 * @date 03 oct. 2021
 * @brief Cette classe hérite de la classe Sensor et renvoie une valeur
 * flottante qui correspond a l'humidite dans le sous-marin (~50.0%)
 */

/**
*Include
*/
#include "../Headers/Sensor.hpp"
#include "../Headers/DataType.hpp"
#include "../Headers/SensorType.hpp"
#include "../Headers/Humidity.hpp"


Humidity::Humidity() {
    this->m_data.setData(50.0f);
    this->m_data.setSensorType(e_humidity);
}

Humidity::Humidity(const Humidity& humidity) {
    this->m_data = humidity.m_data;
}

DataType<float>& Humidity::getData() {
    this->m_data.setData(Sensor::aleaGenVal(45.0f, 75.0f, this->m_data.getData(), 3.0f));

    return this->m_data;
}
