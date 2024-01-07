#include <math.h>
#include "juliacosh.h"
#include <vector>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

JuliaCosH::JuliaCosH(): m_maxiter(0), m_lx(0.0), m_ly(0.0), m_divergencyFactor(3.0)
{
}

JuliaCosH::~JuliaCosH()
{
}

double JuliaCosH::checkDivergency(double x_pos, double y_pos)
{
    double x,y,x2,y2, ret=0.0;
    int iter;

    x=x_pos;
    y=y_pos;
    for(iter=0;(iter < m_maxiter)&&(fabs(y) < m_divergencyFactor);iter++)
    {
        x2=sin(x)*cosh(y);
        y2=cos(x)*sinh(y);
        x=m_lx*x2-m_ly*y2;
        y=m_ly*x2+m_lx*y2;
    }
    if(iter >= m_maxiter)
    {
        ret = 0.0;
    }
    else
    {
        ret = fabs(y);
    }
    return(ret);
}

void JuliaCosH::storeImage()
{
    const std::chrono::_V2::system_clock::time_point timenow = std::chrono::system_clock::now();
    const std::time_t timestamp = std::chrono::system_clock::to_time_t(timenow);
    
    char filename_timestamp[100];
    std::strftime(filename_timestamp, sizeof(filename_timestamp), "%Y%m%d_%H%M%S", std::localtime(&timestamp));

    std::string fileNameXML(filename_timestamp);
    fileNameXML += "_JuliaCosH.xml";
     
    std::ofstream specs;
    specs.open(fileNameXML.c_str());
    specs << "<FRACTAL fractaltype=\"JuliaCosH\">" << std::endl;
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

    std::string fileNameIm(filename_timestamp);
    fileNameIm += "_JuliaCosH.csv";

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

