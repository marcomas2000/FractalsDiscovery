#include <math.h>
#include "juliaexp.h"
#include <vector>

JuliaExp::JuliaExp(): m_maxiter(0), m_lx(0.0), m_ly(0.0), m_divergenceFactor(3.0)
{
}

JuliaExp::~JuliaExp()
{
}

int JuliaExp::msetlevel(double x_pos, double y_pos)
{
    double x,y,x2,y2,mod;
    int iter;

    mod=0.0;
    x=x_pos;
    y=y_pos;
    for(iter=0;(iter < m_maxiter)&&(fabs(x) < m_divergenceFactor);iter++)
    {
        x2=m_lx*exp(x)*cos(y);
        y2=m_lx*exp(x)*sin(y);
        x=x2;
        y=y2;
    }
    return(iter);
}

QRgb JuliaExp::setColour(int level)
{
    QRgb value;
    std::vector<QRgb> colours;
    QRgb colour1 = qRgb(255,0,0);
    QRgb colour2 = qRgb(255,128,0);
    QRgb colour3 = qRgb(255,255,0);
    QRgb colour4 = qRgb(0,255,0);
    QRgb colour5 = qRgb(0,0,255);
    QRgb colour6 = qRgb(75,0,130);
    QRgb colour7 = qRgb(143,0,255);
    colours.push_back(colour1);
    colours.push_back(colour2);
    colours.push_back(colour3);
    colours.push_back(colour4);
    colours.push_back(colour5);
    colours.push_back(colour6);
    colours.push_back(colour7);

    if (level != m_maxiter)
    {
        value = colours[level%(colours.size())];
    }
    else
    {
        value = qRgb(0,0,0);
    }

    return value;
}

