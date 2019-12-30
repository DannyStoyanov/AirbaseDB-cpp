#include "BinaryData.h"
#include "Attribute.h"
#include<fstream>
#include<cstring>
#include<iostream>
#include<cstring>
#include<sstream>
#include<vector>
BinaryData::BinaryData() {
}
BinaryData::~BinaryData() {

}
void BinaryData::setData(unsigned long long _id, std::string _plane, std::string _type, unsigned long long _flights) {
	this->id = _id;
	sprintf_s(this->plane, "%s", _plane.c_str());
	sprintf_s(this->type, "%s", _type.c_str());
	this->flights = _flights;
}
void BinaryData::save(std::ofstream& of) {
	of.write((char*)&id, sizeof(id));
	of.write((char*)&plane, sizeof(plane));
	of.write((char*)&type, sizeof(type));
	of.write((char*)&flights, sizeof(flights));
}
void BinaryData::copyFile(std::string from, std::string to) {
	std::ifstream readFile;
	Attribute record;
	long long size2 = 0;
	readFile.open(from, std::ios::in | std::ios::binary);
	readFile.seekg(0, std::ios::end);
	size2 = (long long)readFile.tellg();
	readFile.seekg(0, std::ios::beg);

	std::ofstream writeFile;
	writeFile.open(to, std::ios::out | std::ios::binary);

	while (readFile.tellg() < size2 && readFile.tellg() >= 0) {
		readFile.read((char*)&record.id, sizeof(record.id));
		readFile.read((char*)&record.plane, sizeof(record.plane));
		readFile.read((char*)&record.type, sizeof(record.type));
		readFile.read((char*)&record.flights, sizeof(record.flights));
		writeFile.write((char*)&record.id, sizeof(record.id));
		writeFile.write((char*)&record.plane, sizeof(record.plane));
		writeFile.write((char*)&record.type, sizeof(record.type));
		writeFile.write((char*)&record.flights, sizeof(record.flights));
	}
	writeFile.close();
	readFile.close();
}
void BinaryData::writeToBinaryFile(std::string strFile) {
	std::ofstream fs;
	fs.open(strFile, std::ios::app | std::ios::binary);
	if (!fs.is_open()) {
		std::cout << "Error while openning the file!" << std::endl;
	}
	else {
		this->save(fs);
	}
}
void BinaryData::readBinaryFile(std::string strFile, int from, int to) {
	Attribute record;
	long long space = sizeof(record.id) + sizeof(record.plane) + sizeof(record.type) + sizeof(record.flights);
	std::ifstream binaryFile;
	long long size = 0;
	binaryFile.open(strFile, std::ios::in | std::ios::binary);
	binaryFile.seekg(0, std::ios::end);
	size = (long long)binaryFile.tellg();
	binaryFile.seekg(from * space, std::ios::beg);
	size /= space;
	if (from <= size) {
		if (to > size)to = size;
		for (int i = 0; i < to; i++)
		{
			binaryFile.read((char*)&record.id, sizeof(record.id));
			binaryFile.read((char*)&record.plane, sizeof(record.plane));
			binaryFile.read((char*)&record.type, sizeof(record.type));
			binaryFile.read((char*)&record.flights, sizeof(record.flights));
			if (record.id == pow(2, 50) + 1)continue;
			record.print();
		}
	}
	binaryFile.close();
	/*
	long long distance = to * space;
	if (distance > size) {
		distance = size;
	}
	while (binaryFile.tellg() < distance) {
		binaryFile.read((char*)&record.id, sizeof(record.id));
		binaryFile.read((char*)&record.plane, sizeof(record.plane));
		binaryFile.read((char*)&record.type, sizeof(record.type));
		binaryFile.read((char*)&record.flights, sizeof(record.flights));
		record.print();
	}
	*/
}
void BinaryData::searchIdInBinaryFile(std::string strFile, std::vector<std::string> attributes) {
	std::string _attribute, _argument;
	unsigned long long _id;
	std::stringstream buffer;
	buffer << attributes[0];
	buffer >> _id;

	Attribute record;
	long long space = sizeof(record.id) + sizeof(record.plane) + sizeof(record.type) + sizeof(record.flights);
	std::ifstream binaryFile;
	long long size = 0;
	binaryFile.open(strFile, std::ios::in | std::ios::app | std::ios::binary);
	binaryFile.seekg(0, std::ios::end);
	size = (long long)binaryFile.tellg();
	binaryFile.seekg(0, std::ios::beg);

	while (binaryFile.tellg() < size) {
		binaryFile.read((char*)&record.id, sizeof(record.id));
		binaryFile.read((char*)&record.plane, sizeof(record.plane));
		binaryFile.read((char*)&record.type, sizeof(record.type));
		binaryFile.read((char*)&record.flights, sizeof(record.flights));
		if (_id == record.id) {
			record.print();
			binaryFile.close();
			return;
		}
	}
	std::cout << "Record with id:" << _id << " not found!" << std::endl;
	binaryFile.close();
}
void BinaryData::updateBinaryFile(std::string strFile, std::vector<std::string> attributes) {
	std::string _attribute, _argument;
	unsigned long long _id;
	std::stringstream buffer;
	buffer << attributes[0];
	buffer >> _id;
	buffer.clear();
	buffer << attributes[1];
	buffer >> _attribute;
	buffer.clear();
	buffer << attributes[2];
	buffer >> _argument;

	Attribute record;
	std::ifstream binaryFile;
	long long size = 0;
	binaryFile.open(strFile, std::ios::in | std::ios::binary);
	binaryFile.seekg(0, std::ios::end);
	size = (long long)binaryFile.tellg();
	binaryFile.seekg(0, std::ios::beg);
	bool isUpdated = false;

	std::ofstream writeFile;
	writeFile.open("temp.db", std::ios::out | std::ios::binary);

	while (binaryFile.tellg() < size && binaryFile.tellg() >= 0) {
		binaryFile.read((char*)&record.id, sizeof(record.id));
		binaryFile.read((char*)&record.plane, sizeof(record.plane));
		binaryFile.read((char*)&record.type, sizeof(record.type));
		binaryFile.read((char*)&record.flights, sizeof(record.flights));
		if (_id == record.id) {
			if (_attribute == "id" || _attribute == "Id" || _attribute == "ID") {
				std::stringstream tempBuffer(_argument);
				unsigned long long temp;
				tempBuffer >> temp;
				record.id = temp;
			}
			else if (_attribute == "plane" || _attribute == "Plane") {
				strcpy_s(record.plane, _argument.c_str());
			}
			else if (_attribute == "type" || _attribute == "Type") {
				strcpy_s(record.type, _argument.c_str());
			}
			else if (_attribute == "flights" || _attribute == "Flights") {
				std::stringstream tempBuffer(_argument);
				unsigned long long temp;
				tempBuffer >> temp;
				record.flights = temp;
			}
			isUpdated = true;
		}
		writeFile.write((char*)&record.id, sizeof(record.id));
		writeFile.write((char*)&record.plane, sizeof(record.plane));
		writeFile.write((char*)&record.type, sizeof(record.type));
		writeFile.write((char*)&record.flights, sizeof(record.flights));
	}
	writeFile.close();
	binaryFile.close();

	copyFile("temp.db", strFile);

	if (isUpdated)std::cout << "Record is successfuly updated!" << std::endl;
	else std::cout << "Error! Record didn't update!" << std::endl;
}
void BinaryData::deleteBinaryFile(std::string strFile, std::vector<std::string> attributes) {
	unsigned long long _id;
	std::stringstream buffer;
	buffer << attributes[0];
	buffer >> _id;

	Attribute record;
	std::ifstream binaryFile;
	long long size = 0;
	binaryFile.open(strFile, std::ios::in | std::ios::binary);
	binaryFile.seekg(0, std::ios::end);
	size = (long long)binaryFile.tellg();
	binaryFile.seekg(0, std::ios::beg);
	bool isDeleted = false;

	std::ofstream writeFile;
	writeFile.open("temp.db", std::ios::out | std::ios::binary);

	while (binaryFile.tellg() < size && binaryFile.tellg() >= 0) {
		binaryFile.read((char*)&record.id, sizeof(record.id));
		binaryFile.read((char*)&record.plane, sizeof(record.plane));
		binaryFile.read((char*)&record.type, sizeof(record.type));
		binaryFile.read((char*)&record.flights, sizeof(record.flights));
		if (_id != record.id) {
			writeFile.write((char*)&record.id, sizeof(record.id));
			writeFile.write((char*)&record.plane, sizeof(record.plane));
			writeFile.write((char*)&record.type, sizeof(record.type));
			writeFile.write((char*)&record.flights, sizeof(record.flights));
		}
		else {
			isDeleted = true;
		}
	}
	writeFile.close();
	binaryFile.close();

	copyFile("temp.db", strFile);
	if (isDeleted)std::cout << "Record is successfuly deleted!" << std::endl;
	else std::cout << "Record with id:" << _id << " not found!" << std::endl;
}