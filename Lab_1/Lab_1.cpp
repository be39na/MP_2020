#include "Matrix.h"
#include <omp.h>
#include <chrono>

void MultiplyLinear(Matrix*, Matrix*, Matrix*);
void MultiplyStatic(Matrix*, Matrix*, Matrix* );
void MultiplyDynamic(Matrix*, Matrix*, Matrix* );
void MultiplyGuided(Matrix*, Matrix*, Matrix* );
int main()
{
	Matrix *firstMatrix, *secondMatrix;

	Matrix* resultMatrix;


	firstMatrix = new Matrix();
	resultMatrix = new Matrix();
	secondMatrix = new Matrix();
	int startSize = 500;
	for (int i = 0; i < 6; i++) {


		std::cout << startSize << " Size" << std::endl;
		firstMatrix->GetRandomMatrixToFile(startSize, startSize, "../11.txt", 10);
		secondMatrix->GetRandomMatrixToFile(startSize, startSize, "../22.txt", 10);


#pragma omp parallel sections
		{
#pragma omp section
			{
				firstMatrix->GetMatrixFromFile("../11.txt");  // ¬вод исходных матриц
			}
#pragma omp section
			{
				secondMatrix->GetMatrixFromFile("../22.txt");
			}
		}




		MultiplyDynamic(firstMatrix, secondMatrix, resultMatrix);
		MultiplyStatic(firstMatrix, secondMatrix, resultMatrix);
		MultiplyGuided(firstMatrix, secondMatrix, resultMatrix);
		MultiplyLinear(firstMatrix, secondMatrix, resultMatrix);
		//resultMatrix->DebugOutpurMatrix();

		resultMatrix->WriteToFile("../result.txt");

		startSize += 100;
	}

	


std:getchar();
	return 0;
}

void MultiplyStatic(Matrix* firstMatrix, Matrix* secondMatrix,Matrix* resultMatrix)
{
	try
	{
		std::cout << "Paralel:\n";
		auto  start = std::chrono::system_clock::now();
		if (firstMatrix->N != secondMatrix->M)  throw "can't multiply n1 not equal m2";
		resultMatrix->Init(firstMatrix->M, secondMatrix->N);


		int str;
		int stolb;
		int k;
		int i;



#pragma omp parallel
		{
		
#pragma omp for private(str, stolb, k, i) schedule(static)

			for (i = 0; i < resultMatrix->M * resultMatrix->N; i++)
			{
				str = i % resultMatrix->M;
				stolb = i / resultMatrix->M;


				for (k = 0; k < firstMatrix->N; k++)
				{
					resultMatrix->matrix[str][stolb] += firstMatrix->matrix[str][k] * secondMatrix->matrix[k][stolb];
				}
			}
		}
		std::chrono::duration<double>  time = std::chrono::system_clock::now() - start;
		std::cout << "Static time:" << time.count() << std::endl;

	}
	catch (const char* str)
	{
		std::cout << str << std::endl;
		return;
	}

}

void MultiplyGuided(Matrix* firstMatrix, Matrix* secondMatrix, Matrix* resultMatrix)
{
	try
	{
		std::cout << "Paralel:\n";
		auto  start = std::chrono::system_clock::now();
		if (firstMatrix->N != secondMatrix->M)  throw "can't multiply n1 not equal m2";
		resultMatrix->Init(firstMatrix->M, secondMatrix->N);


		int str;
		int stolb;
		int k;
		int i;



#pragma omp parallel
		{

#pragma omp for private(str, stolb, k, i) schedule(guided)

			for (i = 0; i < resultMatrix->M * resultMatrix->N; i++)
			{
				str = i % resultMatrix->M;
				stolb = i / resultMatrix->M;


				for (k = 0; k < firstMatrix->N; k++)
				{
					resultMatrix->matrix[str][stolb] += firstMatrix->matrix[str][k] * secondMatrix->matrix[k][stolb];
				}
			}
		}
		std::chrono::duration<double>  time = std::chrono::system_clock::now() - start;
		std::cout << "Guided time:" << time.count() << std::endl;

	}
	catch (const char* str)
	{
		std::cout << str << std::endl;
		return;
	}
}

void MultiplyDynamic(Matrix* firstMatrix, Matrix* secondMatrix, Matrix* resultMatrix)
{
	try
	{
		std::cout << "Paralel:\n";
		auto  start = std::chrono::system_clock::now();
		if (firstMatrix->N != secondMatrix->M)  throw "can't multiply n1 not equal m2";
		resultMatrix->Init(firstMatrix->M, secondMatrix->N);


		int str;
		int stolb;
		int k;
		int i;



#pragma omp parallel
		{

#pragma omp for private(str, stolb, k, i) schedule(dynamic)

			for (i = 0; i < resultMatrix->M * resultMatrix->N; i++)
			{
				str = i % resultMatrix->M;
				stolb = i / resultMatrix->M;


				for (k = 0; k < firstMatrix->N; k++)
				{
					resultMatrix->matrix[str][stolb] += firstMatrix->matrix[str][k] * secondMatrix->matrix[k][stolb];
				}
			}
		}
		std::chrono::duration<double>  time = std::chrono::system_clock::now() - start;
		std::cout << "Dynamic time:" << time.count() << std::endl;

	}
	catch (const char* str)
	{
		std::cout << str << std::endl;
		return;
	}

}

void MultiplyLinear(Matrix* firstMatrix, Matrix* secondMatrix,Matrix *resultMatrix)
{

	try
	{
		std::cout << "Linear:\n";
		auto  start = std::chrono::system_clock::now();
		if (firstMatrix->N != secondMatrix->M)  throw "can't multiply n1 not equal m2";
		resultMatrix->Init(firstMatrix->M, secondMatrix->N);

		int str;
		int stolb;
		int k;
		int i;




			for (i = 0; i < resultMatrix->M * resultMatrix->N; i++)
			{
				str = i / resultMatrix->M;
				stolb = i % resultMatrix->M;

				for (k = 0; k < firstMatrix->N; k++)
				{
					
					resultMatrix->matrix[str][stolb] += firstMatrix->matrix[str][k] * secondMatrix->matrix[k][stolb];
					
					//resultMatrix->matrix[str][stolb] = k;
				}
			}
			std::chrono::duration<double>  time = std::chrono::system_clock::now() - start;
			std::cout << "time2:" << time.count() << std::endl;

			
	}
	catch (const char* str)
	{
		std::cout << str << std::endl;
		return;
	}

}




