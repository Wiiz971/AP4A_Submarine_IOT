/**
 * @author  Vincent AZINCOURT alias Wiiz
 * @file main.cpp
 * @date 23 sept. 2021
 * @brief main program
 */

/**
*Include
*/
#include <iostream>
#include "../Headers/Scheduler.hpp"

using namespace std;

int main(void) {

  // Création du scheduler
  Scheduler Sc;
  // Lancement de la simulation
  Sc.getSensorData();

  return 0;
}
