#include "Utils.h"

namespace Util {
	clock_t markTime() {
		return clock();
	}

	void calculateTime(clock_t const startTime, std::string const functionName)
	{
		clock_t endTime = clock();
		double seconds = (double)(endTime - double(startTime)) / CLOCKS_PER_SEC;
		if (functionName == "NULL")
		{
			std::cout << "EXECUTION TIME : " << seconds << std::endl;
		}
		else
		{
			std::cout << "[" << functionName << "]EXECUTION TIME : " << seconds << std::endl;
		}
	}

	template<typename T>
	void pop_front(std::vector<T>& vec)
	{
		assert(!vec.empty());
		vec.erase(vec.begin());
	}

	template<typename T>
	void print2dArrayVec(std::vector <std::vector<T>>& array, int currPosX, int currPosY) {
		for (int i = 0; i < array.size(); i++)
		{
			for (int j = 0; j < array[i].size(); j++)
			{
				if (i == currPosY && j == currPosX)
				{
					std::cout << "X ";
					continue;
				}
				std::cout << array[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	template<typename T>
	void print2dArrayVec(std::vector <std::vector<T>>& array) {
		for (int i = 0; i < array.size(); i++)
		{
			for (int j = 0; j < array[i].size(); j++)
			{
				std::cout << array[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	template<typename T>
	void print2dArray(T& array, int sizeX, int sizeY, int currPosX, int currPosY) {
		for (int i = 0; i < sizeY; i++)
		{
			for (int j = 0; j < sizeX; j++)
			{
				if (i == currPosY && j == currPosX)
				{
					std::cout << "X ";
					continue;
				}
				std::cout << array[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	template<typename T>
	void print2dArray(T& array, int sizeX, int sizeY) {
		for (int i = 0; i < sizeY; i++)
		{
			for (int j = 0; j < sizeX; j++)
			{
				std::cout << array[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
}