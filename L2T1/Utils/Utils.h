#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <assert.h>

namespace Util
{
	clock_t markTime();

	void calculateTime(clock_t const startTime, std::string const functionName = NULL);

	template<typename T>
	void pop_front(std::vector<T>& vec);

	template<typename T>
	void print2dArrayVec(std::vector <std::vector<T>>& array, int currPosX, int currPosY);

	template<typename T>
	void print2dArrayVec(std::vector <std::vector<T>>& array);

	template<typename T>
	void print2dArray(T& array, int sizeX, int sizeY, int currPosX, int currPosY);

	template<typename T>
	void print2dArray(T& array, int sizeX, int sizeY);
}


#endif // !UTILS_H