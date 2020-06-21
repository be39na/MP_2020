#pragma once

#include "Utils.h"
#include <ctime>
#include "Array.h"



class Matrix
{
public:
	Matrix() {};
	double** data = nullptr;
	int M, N;
	void GetMatrixFromFile(std::string FilePath);
	void GetArrayFromFile(std::string FilePath);
	void DebugOutpurMatrix();
	void MatrixToArray(myArray &arr);
	void GetRandomMatrixToFile(int, int, std::string);
	void WriteToFile(std::string);
	
};