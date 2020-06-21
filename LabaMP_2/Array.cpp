#include "stdafx.h"
#include "Array.h"

void myArray::SetData(double * dataPtr, int sizeData)
{
	this->size = sizeData;
	this->data = dataPtr;

}

void myArray::SetSize(int Size)
{
	this->size = Size;
}

void myArray::DebugOutput()
{

	for (int i = 0; i < size; i++)
	{
	
		std::cout << data[i] << " ";
		
	}

}
void myArray::GetRandomArrayToFile(int size, std::string pathToFile)
{
	srand(time(0));
	this->size = size;
	data = new double[size];


		for (int j = 0; j < size; j++)
		{
			data[j] = 1 + rand() % 100;
		}

	

	WriteToFile(pathToFile);

	rand();
}

void myArray::WriteToFile(std::string FilePath)
{
	std::ofstream out;          // поток для записи
	out.open(FilePath); // окрываем файл для записи
	if (out.is_open())
	{
		out << size<<std::endl;
		for (int j = 0; j < size; j++)
		{
			out << data[j]<< std::endl;
		}
	}

}

void myArray::GetArrayFromFile(std::string FilePath)
{
	std::string line;

	std::ifstream in(FilePath); // окрываем файл для чтения
	if (in.is_open())
	{

		//get first line with delimeter- M
		std::getline(in, line);
		this->size = atoi(line.c_str());
		//get first line - N
	
		data = new double[this->size];
		for (int i = 0; i < this->size; i++)
		{
			std::getline(in, line);
			data[i] = atof(line.c_str());
		}
	}
	in.close();
	//DebugOutpurMatrix();
	std::cout << std::endl;

}