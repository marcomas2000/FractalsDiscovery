#include <math.h>
#include "bifurcation.h"
#include <vector>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>

Bifurcation::Bifurcation()
{
}

Bifurcation::~Bifurcation()
{
}

double Bifurcation::bifur(double a, double b, double x)
{
    int i,j;
    double ret=0.0;

    return(ret);
}

void Bifurcation::storeImage(const char * standardPath)
{
    const std::chrono::system_clock::time_point timenow = std::chrono::system_clock::now();
    const std::time_t timestamp = std::chrono::system_clock::to_time_t(timenow);
    
    char filename_timestamp[100];
    std::strftime(filename_timestamp, sizeof(filename_timestamp), "%Y%m%d_%H%M%S", std::localtime(&timestamp));
    /****

    std::string fileNameXML(standardPath);
    fileNameXML += "/";
    fileNameXML += filename_timestamp;
    fileNameXML += "Bifurcation.xml";
     
    std::ofstream specs;
    specs.open(fileNameXML.c_str());
    specs << "<FRACTAL fractaltype=\"Bifurcation\">" << std::endl;
    specs << "<IMAGERESOLUTION xres=" << m_xres << " yres=" << m_yres << "/>" << std::endl;
    specs << "<FUNCTIONDOMAIN>" << std::endl;
    specs << "    <TOPLEFTCORNER xmin=" << m_xmin << " ymin=" << m_ymin << "/>" << std::endl;
    specs << "    <BOTTOMRIGHTCORNER xmax=" << m_xmax << " ymax=" << m_ymax << "/>" << std::endl;
    specs << "</FUNCTIONDOMAIN>" << std::endl;
    specs << "<MAXITERATIONS> " << m_maxiter << " </MAXITERATIONS>" << std::endl;
    specs << "<INITIALPOINT> " << m_x << " </INITIALPOINT>" << std::endl;
    specs << "<SUCCESSION> ";
          for (int j=0; j < m_suclen; j++)
          {
              specs << m_suc[j];
          } 
    specs << " </SUCCESSION>" << std::endl;
    specs << "</FRACTAL>" << std::endl;
    specs.close();

    std::string fileNameIm(standardPath);
    fileNameIm += "/";
    fileNameIm += filename_timestamp;
    fileNameIm += "Bifurcation.csv";

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
    *****/

}
