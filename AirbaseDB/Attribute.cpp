#include "Attribute.h"
#include<cstring>
Attribute::Attribute() {
	this->id = 0;
	this->plane = "";
	this->type = "";
	this->flights = 0;
}
Attribute::Attribute(unsigned long long _id, std::string _plane, std::string _type, unsigned long long _flights) {
	this->id = _id;
	this->plane = _plane;
	this->type = _type;
	this->flights = _flights;
}
void Attribute::setId(unsigned long long _id) {
	this->id = _id;
}
void Attribute::setPlane(std::string _plane) {
	this->plane = _plane;
}
void Attribute::setType(std::string _type) {
	this->type = _type;
}
void Attribute::setFlights(unsigned long long _flights) {
	this->flights = _flights;
}
unsigned long long Attribute::getId() const {
	return this->id;
}
std::string Attribute::getPlane() const {
	return this->plane;
}
std::string Attribute::getType() const {
	return this->type;
}
unsigned long long Attribute::getFlights() const {
	return this->flights;
}