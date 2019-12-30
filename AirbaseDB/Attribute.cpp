#include "Attribute.h"
#include<iostream>
#include<cstring>
#include<iomanip>
#include<fstream>
Attribute::Attribute() {
	this->id = 0;
	strcpy_s(this->plane, "");
	strcpy_s(this->type, "");
	this->flights = 0;
}
Attribute::Attribute(unsigned long long _id, std::string _plane, std::string _type, unsigned long long _flights) {
	this->id = _id;
	strcpy_s(this->plane, _plane.c_str());
	strcpy_s(this->type, _type.c_str());
	this->flights = _flights;
}
Attribute::Attribute(const Attribute& att) {
	this->id = att.id;
	strcpy_s(this->plane, att.plane);
	strcpy_s(this->type, att.type);
	this->flights = att.flights;
}
Attribute& Attribute::operator=(const Attribute& other) {
	if (this != &other) {
		this->id = other.id;
		strcpy_s(this->plane, other.plane);
		strcpy_s(this->type, other.type);
		this->flights = other.flights;
	}
	return *this;
}
Attribute::~Attribute() {

}
void Attribute::setId(unsigned long long _id) {
	this->id = _id;
}
void Attribute::setPlane(std::string _plane) {
	strcpy_s(this->plane, _plane.c_str());
}
void Attribute::setType(std::string _type) {
	strcpy_s(this->type, _type.c_str());
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

void Attribute::print() const {
	std::cout << "[ID:" << std::setw(10) << std::setiosflags(std::ios::left) << this->id << " ";
	std::cout << "Plane:" << std::setw(10) << std::setiosflags(std::ios::left) << this->plane << " ";
	std::cout << "Type:" << std::setw(10) << std::setiosflags(std::ios::left) << this->type << " ";
	std::cout << "Flights:" << std::setw(10) << std::setiosflags(std::ios::left) << this->flights << "]" << std::endl;
}