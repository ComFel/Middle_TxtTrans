// Codigo por:
// Felipe Vallejo Molina
// felipevm07@gmail.com
// 2022.6
// Proyecto: Traductor de textos

#pragma once

#include <Document.hpp>
#include <map>
#include <string>
#include <list>

using namespace std;


namespace textTrad 
{
	// Idioma disponibles, se podrá aumentar la cantidad
	enum lengEnum
	{
		English,
		Spanish,
		French
	};

	class Data
	{
	public:
		// Referencia al idioma que se quiera traducir
		lengEnum myLenguage;


		list<map<string, string>> myList;

	private:
		string caracter;
		string word;
		string words;


		// Listas con la informacion que se guardará del archivo subido
		list<map<string, string>> EnglishList = 
		{ 
				{"star_button","Start Game"},
				{"optins_button" , "Options"},
				{"exit_button", "Exit"} 
		};
		list<map<string, string>> SpanishList = 
		{
				{"star_button","Nueva Partida"},
				{"optins_button" , "Opciones"},
				{"exit_button", "Salir"}
		};
		list<map<string, string>> FrenchList = 
		{
				{"star_button","NOUVEAU POSTE"},
				{"optins_button" , "Options"},
				{"exit_button", "Sortie"}
		};


	public:

		// Idioma -> Id -> Traduccion
		map<string, map<string, string>> lenguages = 
		{
			{"Ingles",{
				{"star_button","Start Game"},
				{"optins_button" , "Options"},
				{"exit_button", "Exit"}
			}},
			{"Spanish",{
				{"star_button","Nueva Partida"},
				{"optins_button" , "Opciones"},
				{"exit_button", "Salir"}
			}},
			{"Ingles",{
				{"star_button","NOUVEAU POSTE"},
				{"optins_button" , "Options"},
				{"exit_button", "Sortie"}
			}},
			
		};
	
		// Seleccionamos el idioma que queremos trabajar
		void getLenguage(lengEnum myLeng);

		// Funcion que se encarga de buscar por la lista correspondiente al idioma para buscar la traduccion correspondiente
		string getTradfromId(string id, map<string, string> myList) {}

		// Devuelve toda la lista traducida
		list<string> getTradfromLenguage(int lengEnum);

	};


}


