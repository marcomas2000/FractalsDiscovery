#include <math.h>
#include "juliapower4.h"
#include <vector>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

JuliaPower4::JuliaPower4() : m_maxiter(0), m_lx(0.0), m_ly(0.0), m_divergencyFactor(3.0)
{
}

JuliaPower4::~JuliaPower4()
{
}


double JuliaPower4::checkDivergency(double x_pos, double y_pos)
{
    double x,y,x2,y2, theta, mod, ret=0.0;
    int iter;
//  z = x + iy
//  (z exp n) = (mod(z) exp n) (cos(n theta) +i sin(n theta))
//  theta = arctg (y / x)

    mod=0.0;
    x=x_pos;
    y=y_pos;

    for(iter=0;(iter < m_maxiter)&&(mod < m_divergencyFactor);iter++)
    {
        /***
        theta = qAtan(y/x);
        mod=sqrt(x*x+y*y);
        x2 = qPow(mod, 4.0) * qCos( 4 * theta);
        y2 = qPow(mod, 4.0) * qSin( 4 * theta);
        x=x2;
        y=y2;
        **/
    }
    if(iter >= m_maxiter)
    {
        ret = 0.0;
    }
    else
    {
        ret = mod;
    }
    return(ret);
}

void JuliaPower4::storeImage(const char * standardPath)
{
    const std::chrono::_V2::system_clock::time_point timenow = std::chrono::system_clock::now();
    const std::time_t timestamp = std::chrono::system_clock::to_time_t(timenow);
    
    char filename_timestamp[100];
    std::strftime(filename_timestamp, sizeof(filename_timestamp), "%Y%m%d_%H%M%S", std::localtime(&timestamp));

    std::string fileNameXML(standardPath);
    fileNameXML += "/";
    fileNameXML += filename_timestamp;
    fileNameXML += "_JuliaPower4.xml";
     
    std::ofstream specs;
    specs.open(fileNameXML.c_str());
    specs << "<FRACTAL fractaltype=\"JuliaSquared\">" << std::endl;
    specs << "<IMAGERESOLUTION xres=" << m_xres << " yres=" << m_yres << "/>" << std::endl;
    specs << "<FUNCTIONDOMAIN>" << std::endl;
    specs << "    <TOPLEFTCORNER xmin=" << m_xmin << " ymin=" << m_ymin << "/>" << std::endl;
    specs << "    <BOTTOMRIGHTCORNER xmax=" << m_xmax << " ymax=" << m_ymax << "/>" << std::endl;
    specs << "</FUNCTIONDOMAIN>" << std::endl;
    specs << "<MAXITERATIONS> " << m_maxiter << " </MAXITERATIONS>" << std::endl;
    specs << "<XDEVIATION> " << m_lx << " </XDEVIATION>" << std::endl;
    specs << "<YDEVIATION> " << m_ly << " </YDEVIATION>" << std::endl;
    specs << "<DIVERGENCYFACTOR> " << m_divergencyFactor << " </DIVERGENCYFACTOR>" << std::endl;
    specs << "</FRACTAL>" << std::endl;
    specs.close();

    std::string fileNameIm(standardPath);
    fileNameIm += "/";
    fileNameIm += filename_timestamp;
    fileNameIm += "_JuliaPower4.csv";

    std::ofstream image;
    image.open(fileNameIm.c_str());
    
    for(long iy=0; iy < m_yres; iy++)
    {
        for(long ix=0; ix < m_xres; ix++)
        {
            image << m_divergency_matrix[iy][ix] << " ";
        }
        image << std::endl;
    }

    image.close();

}
