#include <iostream>
#include <vector>
#include <memory>

#include "BilinearInterpolation.h"

int main()
{
    std::vector<double> x;
    std::vector<double> y;
    std::vector<std::vector<double>> z;

    for(int i=0; i < 100; i=i+4)
    {
        x.push_back(i);
        std::vector<double> aux;

        y.clear();
        for(int j=0; j < 100; j=j+8)
        {
            double a = 2.2*i - 1.1*j;
            aux.push_back(a);
            y.push_back(j);
        }
        z.push_back(aux);
    }

    auto bi = std::make_unique<BilinearInterpolation> (x, y, z);
    auto result = bi->getInterpolatedZ(10.2, 11.2);
    std::cout<<"Calculado "<<result<<" Valor real "<<(2.2*10.2 - 1.1*11.2)<<std::endl;

    return 0;
}
