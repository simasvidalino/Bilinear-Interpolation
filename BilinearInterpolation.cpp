#include "BilinearInterpolation.h"

BilinearInterpolation::BilinearInterpolation(std::vector<double> &x, std::vector<double> &y, std::vector<std::vector<double>> &z) :
    x(x),
    y(y),
    z(z)
{
std::cout<<"cheguei "<<std::endl;
}

double BilinearInterpolation::getInterpolatedZ(double x, double y)
{
    xValue = x;
    yValue = y;
    std::cout<<"x "<<xValue<<" y "<< yValue<<std::endl;
    auto result = calculateBilinearInterpolate();
    return result;
}

void BilinearInterpolation::setBilinearInterpolateTerm(std::vector<double> &coodenates, double &value, double &a,
                                                       double &b, int &indexa, int &indexb)
{
    for (std::size_t i = 1; i < coodenates.size(); i++)
        if(coodenates[i-1] <= value && coodenates[i] >= value)
        {
           b = coodenates[i];
           a = coodenates[i-1];
           indexb = i;
           indexa = i-1;
           std::cout<<"Valor "<<value<<" Maior "<<b<<" Menor "<<a<<"\na "<<a<<" b "<<b<<std::endl;
        }
}

double BilinearInterpolation::calculateBilinearInterpolate()
{
    for(auto value : x)
        std::cout<<"x "<<value<<std::endl;

    for(auto value : y)
        std::cout<<"y "<<value<<std::endl;

    setBilinearInterpolateTerm(x, xValue, xa, xb, ixa, ixb);
    setBilinearInterpolateTerm(y, yValue, ya, yb, iya, iyb);

    if(xValue == xb)
    {
        r1 = z[ixb][iya]*( (xValue-xa)/(xb-xa) );
        r2 = z[ixb][iyb]*( (xValue-xa)/(xb-xa) );

        if(yValue == yb)
            return r2*( (yValue-ya)/(yb-ya) );
    }
    else
    {
        r1 = (( z[ixa][iya]*(xb-xValue) ) + z[ixb][iya]*(xValue-xa))/(xb-xa);
        r2 = (( z[ixa][iyb]*(xb-xValue) ) + z[ixb][iyb]*(xValue-xa))/(xb-xa);
    }

    return ( (r1*(yb-yValue)) + (r2*(yValue-ya)) )/(yb-ya);
}

