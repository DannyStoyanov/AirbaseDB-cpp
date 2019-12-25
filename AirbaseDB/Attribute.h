#pragma once
class Attribute {
private:
	unsigned long long id;
	char* plane;
	char* type;
	unsigned long long flights;
public:
	Attribute();
	Attribute(unsigned long long, char[], char[], unsigned long long);
	void setId(unsigned long long);
	void setPlane(char*);
	void setType(char*);
	void setFlights(unsigned long long);
	unsigned long long getId() const;
	char* getPlane() const;
	char* getType() const;
	unsigned long long getFlights() const;
};

