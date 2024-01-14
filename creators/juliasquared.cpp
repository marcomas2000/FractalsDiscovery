#include <math.h>
#include "juliasquared.h"
#include <vector>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

JuliaSquared::JuliaSquared(): m_maxiter(0), m_lx(0.0), m_ly(0.0), m_divergencyFactor(3.0)
{
}

JuliaSquared::~JuliaSquared()
{
}

double JuliaSquared::checkDivergency(double x_pos, double y_pos)
{
    double x,y,x2,y2,mod, ret=0.0;
    int iter;

    mod=0.0;
    x=x_pos;
    y=y_pos;
    for(iter=0;(iter < m_maxiter)&&(mod < m_divergencyFactor);iter++)
    {
        x2=x*x-y*y+m_lx;
        y2=2*x*y+m_ly;
        x=x2;
        y=y2;
        mod=sqrt(x*x+y*y);
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

void JuliaSquared::storeImage(const char * standardPath)
{
    const std::chrono::_V2::system_clock::time_point timenow = std::chrono::system_clock::now();
    const std::time_t timestamp = std::chrono::system_clock::to_time_t(timenow);
    
    char filename_timestamp[100];
    std::strftime(filename_timestamp, sizeof(filename_timestamp), "%Y%m%d_%H%M%S", std::localtime(&timestamp));

    std::string fileNameXML(standardPath);
    fileNameXML += "/";
    fileNameXML += filename_timestamp;
    fileNameXML += "_JuliaSquared.xml";
     
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
    fileNameIm += "_JuliaSquared.csv";

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
