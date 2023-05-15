// Codigo por:
// Felipe Vallejo Molina
// felipevm07@gmail.com
// 2022.6
// Proyecto: Traductor de textoss
#pragma once

#include "DocumentLoader.hpp"

namespace textTrad
{

	class API DocxLoader : public DocumentLoader
	{
	public:

		std::shared_ptr< Document > load (const std::string& path) override;
	};

}
