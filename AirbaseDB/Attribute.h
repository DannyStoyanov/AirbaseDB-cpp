#pragma once
#include<string>
class Attribute {
public:
	unsigned long long id;
	char plane[256];
	char type[256];
	unsigned long long flights;
	Attribute();
	Attribute(unsigned long long, std::string, std::string, unsigned long long);
	Attribute(const Attribute&);
	Attribute& operator=(const Attribute&);
	~Attribute();
	void setId(unsigned long long);
	void setPlane(std::string);
	void setType(std::string);
	void setFlights(unsigned long long);
	unsigned long long getId() const;
	std::string getPlane() const;
	std::string getType() const;
	unsigned long long getFlights() const;
	void print() const;
};

