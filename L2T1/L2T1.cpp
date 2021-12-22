#include <iostream>
#include <fstream>
#include "Utils/Utils.h"
#include "Error/Error.h"
#include "Utils/big_int.hpp" //source:https://github.com/devanshu-raj/big_int

Error err;

const int lowerBorder = 1;
const int upperBorder = 100;

int K = 0;
std::vector<big_int> cache;

void readFile(std::string const filename, int& _N, int& _K) 
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        err.addCriticalError("CANNOT OPEN FILE: " + filename, "READ");
    }

    file >> _N;
    file >> _K;
    if (_K < lowerBorder && _K > upperBorder)
    {
        err.addCriticalError("K IS OUT OF RANGE: [1 <= " + std::to_string(_K) + " <= 100]", "READ");
    }

    if (_N < lowerBorder && _N > upperBorder)
    {
        err.addCriticalError("N IS OUT OF RANGE: [1 <= " + std::to_string(_N) + " <= " + std::to_string(_N) + "]", "READ");
    }
}

big_int F(int n, std::vector<big_int>& cache)
{
    if (cache.at(n) == 0)
    {
        int it = 1;

        (n >= K) ? it = K : it = n;

        big_int res = 0;
        for (int i = it; i > 0; i--)
        {
            res += F(n - i, cache);
        }
        cache.at(n) = res;
        std::cout << "Found value for " << n << " : " << res << std::endl;
    }
    return cache.at(n);
}

big_int f_wrap(int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        cache.push_back(0);
    }
    cache[0] = 1;
    cache[1] = 1;
    return F(n, cache);
}

template <typename T>
void writeToFile(std::string filename, T val)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        err.addCriticalError("CANNOT OPEN FILE: " + filename, "WRITE");
    }
    file << val;
}

int main()
{
    clock_t start = Util::markTime();

    int N = 0;

    readFile("INPUT.txt", N, K);

    int offset = 0; 

    big_int result = f_wrap(N + offset);

    writeToFile("OUTPUT.txt", result.get());

    Util::calculateTime(start, "MAIN");
    return 0;
}