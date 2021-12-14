#ifndef BILINEARINTERPOLATION_H
#define BILINEARINTERPOLATION_H
#include <vector>
#include <iostream>

class BilinearInterpolation
{
public:
    BilinearInterpolation(std::vector<double>&x, std::vector<double>&y, std::vector<std::vector<double>>&z);
    double getInterpolatedZ(double x, double y);

private:
    std::vector<double> x;
    std::vector<double> y;
    std::vector<std::vector<double>> z;
    double xValue;
    double yValue;
    double xb;
    double yb;
    double xa;
    double ya;
    double r1;
    double r2;
    int ixa;
    int ixb;
    int iya;
    int iyb;

    void setBilinearInterpolateTerm(std::vector<double> &coodenates, double &value,
                                    double &a, double &b, int &indexa, int &indexb);
    double calculateBilinearInterpolate();
};

#endif // BILINEARINTERPOLATION_H
