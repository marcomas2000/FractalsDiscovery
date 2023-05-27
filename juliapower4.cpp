#include <qmath.h>
#include "juliapower4.h"

JuliaPower4::JuliaPower4() : m_maxiter(0), m_lx(0.0), m_ly(0.0), m_divergenceFactor(3.0)
{
}

JuliaPower4::~JuliaPower4()
{
}

/************************************************
int JuliaPower4::msetlevel(double x_pos, double y_pos)
{
    double x,y,x2,y2, theta, mod;
    int iter;
//  z = x + iy
//  (z exp n) = (mod(z) exp n) (cos(n theta) +i sin(n theta))
//  theta = arctg (y / x)

    mod=0.0;
    x=x_pos;
    y=y_pos;

    for(iter=0;(iter < m_maxiter)&&(mod < m_divergenceFactor);iter++)
    {
        x2 = m_ly*y;
        y2 = 1 + x- m_lx*y*y;
        mod=sqrt(x*x+y*y);
        x=x2;
        y=y2;

    }
    return(iter);
}
******************************************************/

int JuliaPower4::msetlevel(double x_pos, double y_pos)
{
    double x,y,x2,y2, theta, mod;
    int iter;
//  z = x + iy
//  (z exp n) = (mod(z) exp n) (cos(n theta) +i sin(n theta))
//  theta = arctg (y / x)

    mod=0.0;
    x=x_pos;
    y=y_pos;

    for(iter=0;(iter < m_maxiter)&&(mod < m_divergenceFactor);iter++)
    {
        theta = qAtan(y/x);
        mod=sqrt(x*x+y*y);
        x2 = qPow(mod, 4.0) * qCos( 4 * theta);
        y2 = qPow(mod, 4.0) * qSin( 4 * theta);
        x=x2;
        y=y2;
    }
    return(iter);
}

QRgb JuliaPower4::setColour(int level)
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


