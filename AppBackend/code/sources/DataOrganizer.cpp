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

	void Data::SetLenguage(lengEnum sel) 
	{
		auto iterator = lenguagesList.find(sel);

		if (iterator != lenguagesList.end()) 
		{
			myList = iterator->second;
		}
	}


	// Pasamos el id para traducir la lista
	string Data::getTranslationfromId(string id, map<string, string> myList)
	{
		if (myList.find(id) != myList.end()) 
		{
			return myList[id];
		}
	}

	string Data::getTranslationfromId(const string& id)
	{
		for(const auto& item : myList)
		{
			auto iterator = item.find(id);

			if (iterator != item.end())
			{
				return iterator->second;
			}
		}

		// Devolucion de cadena vacia si no encuentra traduccion
		return "";
	}

	// Devolucion de la lista completa traducida
	list<string> Data::getTranslationList()
	{
		list<string> translations;

		for (const auto& item : myList)
		{
			for (const auto& value : item)
			{
				translations.push_back(value.second);
			}
		}

		return translations;
	}
}