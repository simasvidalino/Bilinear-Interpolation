#include "BilinearInterpolation.h"

BilinearInterpolation::BilinearInterpolation(std::vector<double> &x, std::vector<double> &y, std::vector<std::vector<double>> &z) :
    x(x),
    y(y),
    z(z)
{
}

double BilinearInterpolation::getInterpolatedZ(double x, double y)
{
    xValue = x;
    yValue = y;
    auto result = calculateBilinearInterpolate();
    return result;
}

void BilinearInterpolation::setBilinearInterpolateTerm(std::vector<double> &coodenates, double &value, double &a,
                                                       double &b, int &indexa, int &indexb)
{
    for (int i = 1; i < int(coodenates.size()); i++)
        if(coodenates[i-1] <= value && coodenates[i] >= value)
        {
           b = coodenates[i];
           a = coodenates[i-1];
           indexb = i;
           indexa = i-1;
        }
}

double BilinearInterpolation::calculateBilinearInterpolate()
{
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

