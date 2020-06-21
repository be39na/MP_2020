#pragma once

#include "Utils.h"
#include <ctime>


class myArray
{
public:
	myArray() 
	{
	};
	double* data = nullptr;
	int size;
	void SetData(double* dataPtr,int sizeData);
	void SetSize(int Size);
	void DebugOutput();
	void GetRandomArrayToFile(int size, std::string pathToFile);
	void WriteToFile(std::string FilePath);
	void GetArrayFromFile(std::string FilePath);
};
