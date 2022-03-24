/**
 * @author  Vincent AZINCOURT alias Wiiz
 * @file Temperature.hpp
 * @date 03 oct. 2021
 * @brief Cette classe hérite de la classe Sensor et renvoie une valeur
 * flottante qui correspond a la température sous-marine
 */

/**
*Include
*/
#include "../Headers/Sensor.hpp"
#include "../Headers/DataType.hpp"
#include "../Headers/SensorType.hpp"
#include "../Headers/Temperature.hpp"



Temperature::Temperature() {
    this->m_data.setData(19.0f);
    this->m_data.setSensorType(e_temperature);
}

Temperature::Temperature(const Temperature& temperature) {
    this->m_data = temperature.m_data;
}

DataType<float>& Temperature::getData() {
    this->m_data.setData(Sensor::aleaGenVal(10.0f, 26.0f, this->m_data.getData(), 1.5f));

    return this->m_data;
}
