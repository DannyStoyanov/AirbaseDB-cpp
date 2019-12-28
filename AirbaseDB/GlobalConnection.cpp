#include "GlobalConnection.h"
#include "Attribute.h"
GlobalConnection::GlobalConnection(): filename("Planes.db") {
}
bool GlobalConnection::isNumber(const std::string& str) {
	std::string::const_iterator it = str.begin();
	while (it != str.end() && std::isdigit(*it)) ++it;
	return !str.empty() && it == str.end();
}
bool GlobalConnection::isValidRecord(Attribute& record) {
	if (record.getId() > pow(2, 50) || record.getId() < 0) {
		return false;
	}
	else if (record.getPlane().size() > 256 || record.getPlane() == "") {
		return false;
	}
	else if (record.getType().size() > 256 || record.getType() == "") {
		return false;
	}
	else if (record.getFlights() > pow(2, 50) || record.getFlights() < 0) {
		return false;
	}
	return true;
}