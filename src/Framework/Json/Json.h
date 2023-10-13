// ===== ===== ===== ===== ===== ===== ===== =====
// @file	Json.h
// @brief	Json‚ðŽæ‚èˆµ‚¤
// 
// @date	2023-10-13
// @update	2023-10-13
// 
// @author	UNLUCKY
// ===== ===== ===== ===== ===== ===== ===== =====

#pragma once

#include <fstream>
#include <picojson.h>

#include "JsonImport.h"

class Json
{
private:
	std::ifstream m_ifs;
	picojson::value m_value;

public:
	Json();
	~Json();

	void Load(const std::string& file_name);

	template <typename Type>
	inline Type GetAs(std::string path)
	{
		return JsonImport::get_as<Type>(JsonImport::get_value(m_value, path));
	}
};