#include "GlobalConnection.h"
#include "Attribute.h"
#include<cmath>
GlobalConnection::GlobalConnection() : filename("Planes.db") {

}
bool GlobalConnection::isNumber(const std::string& str) {
	std::string::const_iterator it = str.begin();
	while (it != str.end() && std::isdigit(*it)) ++it;
	return !str.empty() && it == str.end();
}
bool GlobalConnection::isValidNumber(unsigned long long number) {
	return number > 0 && number < pow(2, 50);
}
bool GlobalConnection::isValidString(const std::string& str) {
	if (str.size() > 256 || str == "") {
		return false;
	}
	return true;
}
bool GlobalConnection::isValidRecord(Attribute& record) {
	if (!isValidNumber(record.getId())) {
		return false;
	}
	else if (!isValidString(record.getPlane())) {
		return false;
	}
	else if (!isValidString(record.getType())) {
		return false;
	}
	else if (!isValidNumber(record.getFlights())) {
		return false;
	}
	return true;
}
void GlobalConnection::strcpyPtr(char* dest, const char* src)
{
	while (*dest++ = *src++)
		;
}
