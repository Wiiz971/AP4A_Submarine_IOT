/**
 * @author  Vincent AZINCOURT alias Wiiz
 * @file Server.hpp
 * @date 25 sept. 2021
 * @brief Cette classe permet de recevoir les donnees des capteurs
 * 		  et de les visualiser dans la console et/ou de les stocker dans des fichiers de logs.
 */


/**
 * Define  guards
 */
#ifndef SERVER_HPP_
#define SERVER_HPP_

/**
*Include
*/

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "DataType.hpp"

using namespace std;

/**
 * @class Server
 * @brief  Cette classe recoit les données du sensor et les affiche dans la console et/ou les stock dans un LogFile
 */

class Server{
	private:

		bool m_consoleActivated; // si vrai -> données du capteur affichées dans console
		bool m_logsActivated; // si vrai -> ecrit les données du capteur dans ./Logs/ <sensorName>

		string m_Directory; //chemin vers le dossier log du sensor

		/**
		 * @fn void fileWrite(const DataType&)
		 * @brief Cette fonction stocke dans un LogFile les données
		 * @return void
		 * @param type
		 */
		template<class T> void fileWrite(DataType<T>& type) {
			SensorType sensorType = type.getSensorType();

			if(sensorType == e_temperature) {
				stringstream stream;
				stream << setprecision(1) << fixed << type.getData();
				this->logData("temperature.log", stream.str() + "°C");
			}
			else if(sensorType == e_humidity) {
				stringstream stream;
				stream << setprecision(1) << fixed << type.getData();
				this->logData("humidity.log", stream.str() + "%");
			}else if(sensorType == e_light) {
				this->logData("light.log", (type.getData()? "On" : "Off"));
			}else if(sensorType == e_pression) {
				this->logData("pression.log", to_string(type.getData()) + " Pa");
			}
		};

		/**
		 * @fn void consoleWrite(const DataType&)
		 * @brief Cette donction affiche les données dans la console
		 * @return void
		 * @param type
		 */
		template<class T> void consolWrite(DataType<T>& type) {
		            SensorType sensorType = type.getSensorType();

		            if(sensorType == e_humidity) {
		                std::cout << "Taux de humidité: " << std::setprecision(1) << std::fixed << type.getData() << "%" << std::endl << std::endl;
		            }else if(sensorType == e_light) {
		                std::cout << "La lumiere est " << (type.getData() ? "allumee" : "eteinte") << std::endl << std::endl;
		            }else if(sensorType == e_pression) {
		                std::cout << "Pression: " << type.getData() << " Pa" << std::endl << std::endl;
		            }else if(sensorType == e_temperature) {
		                std::cout << "Temperature: " << std::setprecision(1) << std::fixed << type.getData() << "°C" << std::endl << std::endl;
		            }
		        };


	public:

		// Définition de la forme canonique
		/* construteur par defaut */
		Server(): m_consoleActivated(true), m_logsActivated(true), m_Directory("../logs/"){};
		/*constructeur par recopie*/
		Server(const Server& server): m_consoleActivated(server.m_consoleActivated), m_logsActivated(server.m_logsActivated), m_Directory(server.m_Directory){};
		/*constructeur par operateur = */
		Server& operator=(const Server& server);
		/*destructeur*/
		~Server(){};

		/**
		 * @fn  Server(const bool&, const bool&, const string&)
		 * @brief Permet de modifier les attributs de la classe Server
		 * @param consoleActivated
		 * @param logsActivated
		 * @param directory
		 */
		Server(const bool& consoleActivated, const bool& logsActivated, const string& directory): m_consoleActivated(consoleActivated), m_logsActivated(logsActivated), m_Directory(directory) {};

		/**
		 * @fn void receiveData(dataType&)
		 * @brief cette fonction utilise 2 fonctions privées (fileWrite and consoleWrite)
		 * @return void
		 * @param type
		 */

		template<class T> void receiveData(DataType<T>& type) {
			// Si m_consoleActivated est true, les données sont affichées dans la console
			if(this->m_consoleActivated) {
				this->consolWrite(type);
			}
			// Si m_logsActivated est true, les données sont stocker dans des fichiers de log
			if(this->m_logsActivated) {
				this->fileWrite(type);
			}
		};


		/**
		 * @fn void logData(const string&, const string&)
		 * @brief Cette fonction permet de stocker les logs dans un file (associé au sensor)
		 * @return void
		 * @param fileName
		 * @param data
		 */

		void logData(const string& fileName, const string& data);


		/**
		 * @fn void setLogsActivated(bool&)
		 * @brief Cette fonction permet de modifier m_logsActivated
		 * @return void
		 * @param activated - Nouvelle valeur de m_logsActivated
		 */
        void setLogsActivated(bool& activated);

        /**
		 * @fn void setConsoleActivated(bool&)
         * @brief Cette fonction permet de modifier m_consoleActivated
         * @return void
         * @param activated - Nouvelle valeur de m_consoleActivated
         */
		void setConsoleActivated(bool& activated);

		/**
		 * @fn bool getLogsActivated()
		 * @brief Cette fonction renvoie la valeur de m_logsActivated
		 * @return bool
		 */
		bool getLogsActivated();

		/**
		 * @fn bool getConsoleActivated()
		 * @brief Cette fonction renvoie la valeur de m_consoleActivated
		 * @return bool
		 */
		bool getConsoleActivated();
};

#endif // SERVER_HPP_
