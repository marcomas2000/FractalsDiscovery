#include <math.h>
#include "mandelbrot.h"
#include <vector>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

Mandelbrot::Mandelbrot(): m_maxiter(0), m_divergencyFactor(3.0)
{
}

Mandelbrot::~Mandelbrot()
{
}

double Mandelbrot::checkDivergency(double x_pos, double y_pos)
{
    double x,y,x2,y2,temp, ret= 0.0;
    int iter;

    x=0.0;
    y=0.0;
    x2=0.0;
    y2=0.0;
    for(iter=0;(iter < m_maxiter)&&((x2 + y2) < m_divergencyFactor);iter++)
    {
        temp=x2-y2+x_pos;
        y=2*x*y+y_pos;
        x=temp;
        x2=x*x;
        y2=y*y;
    }
    if(iter >= m_maxiter)
    {
        ret = 0.0;
    }
    else
    {
        ret = x2 + y2;
    }
    return(ret);
}

void Mandelbrot::storeImage(const char * standardPath)
{
    const std::chrono::_V2::system_clock::time_point timenow = std::chrono::system_clock::now();
    const std::time_t timestamp = std::chrono::system_clock::to_time_t(timenow);
    
    char filename_timestamp[100];
    std::strftime(filename_timestamp, sizeof(filename_timestamp), "%Y%m%d_%H%M%S", std::localtime(&timestamp));

    std::string fileNameXML(standardPath);
    fileNameXML += "/";
    fileNameXML += filename_timestamp;
    fileNameXML += "_Mandelbrot.xml";
     
    std::ofstream specs;
    specs.open(fileNameXML.c_str());
    specs << "<FRACTAL fractaltype=\"Mandelbrot\">" << std::endl;
    specs << "<IMAGERESOLUTION xres=" << m_xres << " yres=" << m_yres << "/>" << std::endl;
    specs << "<FUNCTIONDOMAIN>" << std::endl;
    specs << "    <TOPLEFTCORNER xmin=" << m_xmin << " ymin=" << m_ymin << "/>" << std::endl;
    specs << "    <BOTTOMRIGHTCORNER xmax=" << m_xmax << " ymax=" << m_ymax << "/>" << std::endl;
    specs << "</FUNCTIONDOMAIN>" << std::endl;
    specs << "<MAXITERATIONS> " << m_maxiter << " </MAXITERATIONS>" << std::endl;
    specs << "<DIVERGENCYFACTOR> " << m_divergencyFactor << " </DIVERGENCYFACTOR>" << std::endl;
    specs << "</FRACTAL>" << std::endl;
    specs.close();

    std::string fileNameIm(standardPath);
    fileNameIm += "/";
    fileNameIm += filename_timestamp;
    fileNameIm += "_Mandelbrot.csv";

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
