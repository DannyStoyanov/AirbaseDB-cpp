#include "BinaryData.h"
#include "Attribute.h"
#include "GlobalConnection.h"
#include<fstream>
#include<cstring>
#include<iostream>
#include<cstring>
#include<sstream>
#include<vector>
static GlobalConnection data;

BinaryData::BinaryData() {
	this->id = 0;
	strcpy_s(this->plane, "");
	strcpy_s(this->type, "");
	this->flights = 0;
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
bool BinaryData::isUniqueID(std::string strFile, unsigned long long _id) {
	Attribute record;
	std::ifstream binaryFile;
	long long size = 0;
	binaryFile.open(strFile, std::ios::in | std::ios::binary);
	binaryFile.seekg(0, std::ios::end);
	size = (long long)binaryFile.tellg();
	binaryFile.seekg(0, std::ios::beg);

	while (binaryFile.tellg() < size && binaryFile.tellg() >= 0) {
		binaryFile.read((char*)&record.id, sizeof(record.id));
		binaryFile.read((char*)&record.plane, sizeof(record.plane));
		binaryFile.read((char*)&record.type, sizeof(record.type));
		binaryFile.read((char*)&record.flights, sizeof(record.flights));
		if (_id == record.id) {
			binaryFile.close();
			return false;
		}
	}
	binaryFile.close();
	return true;
}
void BinaryData::writeToBinaryFile(std::string strFile) {
	if (isUniqueID(strFile, this->id) == true) {
		std::ofstream fs;
		fs.open(strFile, std::ios::app | std::ios::binary);
		if (!fs.is_open()) {
			std::cout << "-----Message: Error while openning the file!" << std::endl;
		}
		else {
			this->save(fs);
			std::cout << "-----Message: Record created: [ID:" << this->id << "\t Plane:" << this->plane << "\t Type:" << this->type << "\t Flights:" << this->flights << "]" << std::endl;
		}
	}
	else {
		std::cout << "-----Message: Record with id:" << this->id << " is already existing!" << std::endl;
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
	long long border = to;
	if (from < size) {
		if (border > size)border = size;
		for (int i = 0; i < border && !binaryFile.eof(); i++)
		{
			binaryFile.read((char*)&record.id, sizeof(record.id));
			binaryFile.read((char*)&record.plane, sizeof(record.plane));
			binaryFile.read((char*)&record.type, sizeof(record.type));
			binaryFile.read((char*)&record.flights, sizeof(record.flights));
			record.print();
		}
	}
	else {
		std::cout << "-----Message: Invalid arguments of \"show\" " << std::endl;
	}
	binaryFile.close();
}
void BinaryData::searchBinaryFile(std::string strFile, std::vector<std::string> attributes) {
	std::string _attribute, _argument;
	unsigned long long _id;
	std::stringstream buffer;
	buffer << attributes[0];
	buffer >> _id;

	Attribute record;
	long long space = sizeof(record.id) + sizeof(record.plane) + sizeof(record.type) + sizeof(record.flights);
	std::ifstream binaryFile;
	long long size = 0;
	binaryFile.open(strFile, std::ios::in | std::ios::binary);
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
	std::cout << "-----Message: Record with id:" << _id << " not found!" << std::endl;
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
				if (!data.isValidNumber(temp)) {
					std::cout << "-----Message: Incorrect \"id\"!" << std::endl;
					return;
				}
				record.id = temp;
			}
			else if (_attribute == "plane" || _attribute == "Plane") {
				if (!data.isValidString(_argument)) {
					std::cout << "-----Message: Incorrect \"plane\"!" << std::endl;
					return;
				}
				strcpy_s(record.plane, _argument.c_str());
			}
			else if (_attribute == "type" || _attribute == "Type") {
				if (!data.isValidString(_argument)) {
					std::cout << "-----Message: Incorrect \"type\"!" << std::endl;
					return;
				}
				strcpy_s(record.type, _argument.c_str());
			}
			else if (_attribute == "flights" || _attribute == "Flights") {
				std::stringstream tempBuffer(_argument);
				unsigned long long temp;
				tempBuffer >> temp;
				if (!data.isValidNumber(temp)) {
					std::cout << "-----Message: Incorrect \"flights\"!" << std::endl;
					return;
				}
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

	if (isUpdated)std::cout << "-----Message: Record is successfuly updated!" << std::endl;
	else std::cout << "-----Message: Error! Record didn't update!" << std::endl;
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
	if (isDeleted)std::cout << "-----Message: Record is successfuly deleted!" << std::endl;
	else std::cout << "-----Message: Record with id:" << _id << " not found!" << std::endl;
}
void merge(Attribute* arr, int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	Attribute* L = new(std::nothrow) Attribute[n1];
	Attribute* R = new(std::nothrow) Attribute[n2];
	if (!L || !R) {
		std::cout << "-----Message: Error in merge! Not enough memory!";
		return;
	}
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i].id < R[j].id)
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
}
void mergeSort(Attribute* arr, int left, int right) {
	if (left < right)
	{
		int middle = left + (right - left) / 2;
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);
		merge(arr, left, middle, right);
	}
}
void BinaryData::optimizeBinaryFile(std::string strFile) {
	Attribute currentRecord;
	std::ifstream binaryFile;
	long long size = 0;
	long long space = sizeof(currentRecord.id) + sizeof(currentRecord.plane) + sizeof(currentRecord.type) + sizeof(currentRecord.flights);
	binaryFile.open(strFile, std::ios::in | std::ios::binary);
	binaryFile.seekg(0, std::ios::end);
	size = (long long)binaryFile.tellg();
	binaryFile.seekg(0, std::ios::beg);
	size_t len = size / space;
	Attribute* records = new(std::nothrow) Attribute[len];
	int index = 0;

	while (binaryFile.tellg() < size && binaryFile.tellg() >= 0) {
		binaryFile.read((char*)&currentRecord.id, sizeof(currentRecord.id));
		binaryFile.read((char*)&currentRecord.plane, sizeof(currentRecord.plane));
		binaryFile.read((char*)&currentRecord.type, sizeof(currentRecord.type));
		binaryFile.read((char*)&currentRecord.flights, sizeof(currentRecord.flights));
		records[index] = currentRecord;
		++index;
	}
	binaryFile.close();
	mergeSort(records, 0, index - 1);

	std::ofstream writeFile;
	writeFile.open("temp.db", std::ios::out | std::ios::binary);
	for (int i = 0; i < index; i++)
	{
		writeFile.write((char*)&records[i].id, sizeof(records[i].id));
		writeFile.write((char*)&records[i].plane, sizeof(records[i].plane));
		writeFile.write((char*)&records[i].type, sizeof(records[i].type));
		writeFile.write((char*)&records[i].flights, sizeof(records[i].flights));
	}
	writeFile.close();

	delete[] records;
	copyFile("temp.db", strFile);
}
Attribute* binarySearch(Attribute* arr, int l, int r, unsigned long long x) {
	if (r >= l) {
		unsigned long long mid = l + (r - l) / 2;
		if (arr[mid].id == x)
			return &arr[mid];
		if (arr[mid].id > x)
			return binarySearch(arr, l, mid - 1, x);
		return binarySearch(arr, mid + 1, r, x);
	}
	return nullptr;
}
void BinaryData::binarySearchBinaryFile(std::string strFile, std::vector<std::string> attributes) {
	std::string _attribute, _argument;
	unsigned long long _id;
	std::stringstream buffer;
	buffer << attributes[0];
	buffer >> _id;

	Attribute currentRecord;
	std::ifstream binaryFile;
	long long size = 0;
	long long space = sizeof(currentRecord.id) + sizeof(currentRecord.plane) + sizeof(currentRecord.type) + sizeof(currentRecord.flights);
	binaryFile.open(strFile, std::ios::in | std::ios::binary);
	binaryFile.seekg(0, std::ios::end);
	size = (long long)binaryFile.tellg();
	binaryFile.seekg(0, std::ios::beg);
	size_t len = size / space;
	Attribute* records = new(std::nothrow) Attribute[len];
	int index = 0;

	while (binaryFile.tellg() < size && binaryFile.tellg() >= 0) {
		binaryFile.read((char*)&currentRecord.id, sizeof(currentRecord.id));
		binaryFile.read((char*)&currentRecord.plane, sizeof(currentRecord.plane));
		binaryFile.read((char*)&currentRecord.type, sizeof(currentRecord.type));
		binaryFile.read((char*)&currentRecord.flights, sizeof(currentRecord.flights));
		records[index] = currentRecord;
		++index;
	}
	binaryFile.close();
	Attribute* isExisting;
	isExisting = binarySearch(records, 0, index - 1, _id);
	if (isExisting)isExisting->print();
	else {
		std::cout << "-----Message: Record with id:" << _id << " not found!" << std::endl;
	}

	delete[] records;
}