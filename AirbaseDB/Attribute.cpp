#include "Attribute.h"
#include<cstring>
Attribute::Attribute() {
	this->id = 0;
	this->plane = strcpy(this->plane, "");
	this->type = strcpy(this->type, "");
	this->flights = 0;
}
Attribute::Attribute(unsigned long long _id, char _plane[], char _type[], unsigned long long _flights) {
	this->id = _id;
	this->plane = strcpy(this->plane, _plane);
	this->type = strcpy(this->type, type);
	this->flights = _flights;
}
void Attribute::setId(unsigned long long _id) {
	this->id = _id;
}
void Attribute::setPlane(char* _plane) {
	strcpy(this->plane, _plane);
}
void Attribute::setType(char* _type) {
	strcpy(this->type, _type);
}
void Attribute::setFlights(unsigned long long _flights) {
	this->flights = _flights;
}
unsigned long long Attribute::getId() const {
	return this->id;
}
char* Attribute::getPlane() const {
	return this->plane;
}
char* Attribute::getType() const {
	return this->type;
}
unsigned long long Attribute::getFlights() const {
	return this->flights;
}