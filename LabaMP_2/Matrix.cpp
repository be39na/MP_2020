#include "stdafx.h"
#include "Matrix.h"

void Matrix::DebugOutpurMatrix()
{

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			std::cout << data[i][j] << " ";
		std::cout << std::endl;
	}

}


void Matrix::GetRandomMatrixToFile(int M, int N, std::string pathToFile)
{
	srand(time(0));
	this->M = M;
	this->N = N;
	data = new double*[M];

	for (int i = 0; i < M; i++)
	{
		data[i] = new double[N];
		for (int j = 0; j < N; j++)
		{
			data[i][j] = 1 + rand() % 100;
		}

	}

	WriteToFile(pathToFile);

	rand();


}

void Matrix::WriteToFile(std::string FilePath)
{
	std::ofstream out;          // поток для записи
	out.open(FilePath); // окрываем файл для записи
	if (out.is_open())
	{
		out << M << " " << N << std::endl;

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				out << data[i][j];
				if (j != N - 1) { out << " "; }
			}
			out << std::endl;
		}


	}

}

void Matrix::MatrixToArray(myArray& arr)
{
	arr.data = new double[M*N];
	int count=0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr.data[count] = data[i][j];
			count++;
		}
		
		
	}

	arr.size = count;
	
}


void Matrix::GetMatrixFromFile(std::string FilePath)
{

	std::string line;

	std::ifstream in(FilePath); // окрываем файл для чтения
	if (in.is_open())
	{

		//get first line with delimeter- M
		std::getline(in, line, ' ');
		M = atoi(line.c_str());
		//get first line - N
		std::getline(in, line);
		N = atoi(line.c_str());


		data = new double*[M];
		for (int i = 0; i < M; i++)
		{

			std::getline(in, line);
			std::vector<std::string> tokens = Utils::Split(line, ' ');
			data[i] = new double[N];
			for (int j = 0; j < N; j++)
			{
				data[i][j] = atof(tokens[j].c_str());
			}

		}
	}
	in.close();
	//DebugOutpurMatrix();
	std::cout << std::endl;




}

void Matrix::GetArrayFromFile(std::string FilePath)
{
	std::string line;

	std::ifstream in(FilePath); // окрываем файл для чтения
	if (in.is_open())
	{

		//get first line with delimeter- M
		std::getline(in, line);
		M = atoi(line.c_str());
		//get first line - N
		N = 1;


		data = new double*[M];
		for (int i = 0; i < M; i++)
		{

			std::getline(in, line);
			std::vector<std::string> tokens = Utils::Split(line, ' ');
			data[i] = new double[N];
			for (int j = 0; j < N; j++)
			{
				data[i][j] = atof(tokens[j].c_str());
			}

		}
	}
	in.close();
	//DebugOutpurMatrix();
	std::cout << std::endl;

}