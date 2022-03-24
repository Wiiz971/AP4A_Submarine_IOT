/**
 * @author  Vincent AZINCOURT alias Wiiz
 * @file Light.cpp
 * @date 03 oct. 2021
 * @brief Cette classe herite de la classe Sensor et renvoie une valeur
 * flottante qui correspond au taux de luminosité dans le sous-marin [0 (faible)-100%(bien eclaire)]
 */

/**
*Include
*/
#include "../Headers/Sensor.hpp"
#include "../Headers/DataType.hpp"
#include "../Headers/SensorType.hpp"
#include "../Headers/Light.hpp"


Light::Light() {
    this->m_data.setData(50.0);
    this->m_data.setSensorType(e_light);
}

Light::Light(const Light& light) {
    this->m_data = light.m_data;
}

DataType<bool>& Light::getData() {
    this->m_data.setData(Sensor::aleaGenVal(0, 1, this->m_data.getData(), 1));

    return this->m_data;
}




