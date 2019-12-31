#pragma once
#include "Attribute.h"
#include<vector>
#include<string>
class BinaryData {
private:
	unsigned long long id;
	char plane[256];
	char type[256];
	unsigned long long flights;
public:
	BinaryData();
	~BinaryData();
	void setData(unsigned long long, std::string, std::string, unsigned long long);
	void save(std::ofstream&);
	void copyFile(std::string, std::string);
	bool isUniqueID(std::string, unsigned long long);
	void writeToBinaryFile(std::string);
	void readBinaryFile(std::string, int, int);
	void searchBinaryFile(std::string, std::vector<std::string>);
	void updateBinaryFile(std::string, std::vector<std::string>);
	void deleteBinaryFile(std::string, std::vector<std::string>);
	void optimizeBinaryFile(std::string);
	void binarySearchBinaryFile(std::string, std::vector<std::string>);
};

