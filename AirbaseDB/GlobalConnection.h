#pragma once
#include<vector>
#include<string>
#include "Attribute.h"
class GlobalConnection{
public:
	const std::string filename;
	GlobalConnection();
	bool isNumber(const std::string& str);
	bool isValidRecord(Attribute&);
};

