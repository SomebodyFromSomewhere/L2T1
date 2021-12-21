#include <iostream>
#include <fstream>
#include "Utils/Utils.h"
#include "Error/Error.h"

Error err;

struct Node
{
    int sum;
    std::vector<int> childs;
    Node(int sum) { this->sum = sum; }
};

const int lowerBorder = 1;
const int upperBorder = 100;
int K;
std::vector<int> cache;

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

int F(int n, std::vector<int> cache) 
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (cache.at(n) == 0)
    {
        int it = 1;
        if (n >= K)
        {
            it = K;
        }
        int res = 0;
        for (int i = it; i > 0; i--)
        {
            res += F(n - i, cache);
        }
        cache.at(n) = res;
    }
    return cache.at(n);
}

int f_wrap(int n) 
{
    for (int i = 0; i < n + 1; i++)
    {
        cache.push_back(0);
    }
    return F(n, cache);
}


int main()
{
    clock_t start = Util::markTime();

    int N = 0;
    K = 0;

    readFile("INPUT.txt", N, K);

    int result = f_wrap(N + 1);

    std::cout << std::to_string(result) << std::endl;

    Util::calculateTime(start, "MAIN");
    return 0;
}