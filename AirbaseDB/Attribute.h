#pragma once
#include<string>
class Attribute {
private:
	unsigned long long id;
	std::string plane;
	std::string type;
	unsigned long long flights;
public:
	Attribute();
	Attribute(unsigned long long, std::string, std::string, unsigned long long);
	void setId(unsigned long long);
	void setPlane(std::string);
	void setType(std::string);
	void setFlights(unsigned long long);
	unsigned long long getId() const;
	std::string getPlane() const;
	std::string getType() const;
	unsigned long long getFlights() const;
};

