/**
 * @author  Vincent AZINCOURT alias Wiiz
 * @file Server.cpp
 * @date 25 sept. 2021
 * @brief Cette classe permet de recevoir les donnees des capteurs
 * 		  et de les visualiser dans la console et/ou de les stocker dans des fichiers de logs.
 */


#include "../Headers/Server.hpp"
#include "../Headers/DataType.hpp"
#include "../Headers/SensorType.hpp"
#include <fstream>
#include <iostream>
#include <string>


using namespace std;

Server& Server::operator=(const Server& server) {
    this->m_consoleActivated = server.m_consoleActivated;
    this->m_logsActivated = server.m_logsActivated;
    this->m_Directory = server.m_Directory;
    return *this;
}

void Server::logData(const string& fileName, const string& data){

		ofstream logInfo;
		logInfo.open(this->m_Directory + fileName, ios::app);
		if(logInfo){
		logInfo << data << endl;
		logInfo.close();
	}else
	{
		 cerr << "Probleme ouverture fichier logs"<<endl;
	}

}

