// Codigo por:
// Felipe Vallejo Molina
// felipevm07@gmail.com
// 2022.6
// Proyecto: Traductor de textos
#pragma once

#include <string>
#include <memory>
#include "API.hpp"
#include "Document.hpp"

namespace textTrad
{

	class API DocumentLoader
	{
	public:

		virtual std::shared_ptr< Document > load (const std::string & path) = 0;

		virtual ~DocumentLoader() = default;

	};

}

