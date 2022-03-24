/**
 * @author  Vincent AZINCOURT alias Wiiz
 * @file Pression.cpp
 * @date 07 oct. 2021
 * @brief Cette classe herite de la classe Sensor et renvoie une valeur
 * flottante qui correspond la pression atmosphérique à l'experieur du sous-marin ~10 kPa
 */



/**
*Include
*/
#include "../Headers/Sensor.hpp"
#include "../Headers/DataType.hpp"
#include "../Headers/SensorType.hpp"
#include "../Headers/Pression.hpp"


Pression::Pression() {
    this->m_data.setData(10000);
    this->m_data.setSensorType(e_pression);
}

Pression::Pression(const Pression& pression) {
    this->m_data = pression.m_data;
}

DataType<int>& Pression::getData() {
    this->m_data.setData(Sensor::aleaGenVal(9500, 20000, this->m_data.getData(), 5000));

    return this->m_data;
}




