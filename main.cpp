#include <numeric>
#include <iostream>
#include <vector>

struct KahanAccumulation
{
    double sum;
    double correction;
};

KahanAccumulation KahanSum(KahanAccumulation accumulation, double value)
{
    KahanAccumulation result;
    double y = value - accumulation.correction;
    double t = accumulation.sum + y;
    result.correction = (t - accumulation.sum) - y;
    result.sum = t;
    return result;
}

int main()
{
    std::vector<double> numbers = {0.01, 0.001, 0.0001, 0.000001, 0.00000000001};
    KahanAccumulation init = {0};
    KahanAccumulation result =
        std::accumulate(numbers.begin(), numbers.end(), init, KahanSum);

    std::cout << "Kahan Sum: " << result.sum << std::endl;
    return 0;
}
