// Codigo por:
// Felipe Vallejo Molina
// felipevm07@gmail.com
// 2022.6
// Proyecto: Traductor de textos

#pragma once

#include <DataOrganizer.h>
#include <Document.hpp>
#include <map>
#include <string>
#include <list>

namespace textTrad
{
	// Eleccion de idioma
	void Data::getLenguage(lengEnum sel)
	{
		switch (sel)
		{
		case textTrad::English:
			myList = EnglishList;
			break;
		case textTrad::Spanish:
			myList = SpanishList;
			break;
		case textTrad::French:
			myList = FrenchList;
			break;
		default:
			break;
		}

	}

	// Pasamos el id para traducir la lista
	string Data::getTradfromId(string id, map<string, string> myList)
	{
		if (myList.find(id) != myList.end()) 
		{
			return myList[id];
		}
		/*
		for (auto & caracter : myList)
		{
			if(caracter[id,value] == myList)

		}*/

		//return "Start Game";
	}


}