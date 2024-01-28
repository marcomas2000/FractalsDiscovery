#include <math.h>
#include "bifurcation.h"
#include <vector>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

Bifurcation::Bifurcation()
{
}

Bifurcation::~Bifurcation()
{
}

double Bifurcation::bifur(long ix)
{
    long i = 0;
    double ret=0.0;
    double x= m_initialPoint;
    double c_pos = 0.0;

    m_attractorsOrbits.resize(std::trunc(m_maxIter * m_stability));
    for(i = 0; i < m_maxIter * m_stability; i++)
    {
        m_attractorsOrbits[i] = 0;
    }     
    /* zero results vectors */
    for(i=0; i < m_yres; i++)
    {
        m_attractorsVectorIndex[i] = 0;
        m_attractorsVector[i] = 0; 
    }     
    c_pos=m_cmin+ix*(m_cmax-m_cmin)/(m_xres-1);
    for(i = 0; i < m_noIterationToExclude; i++ )
    {
        x = std::pow(x,2) + c_pos;
    }
    bool stop = false;
    long counter = 0;
    long previousCounter = 0;
    long stability = 0;
    long no_iterations = 0;
    int stackPointer = 0;
    while (stop == false) 
    {
        if (no_iterations <= m_maxIter)
        {
            previousCounter = counter;
            x = std::pow(x,2) + c_pos;
            double idx = std::trunc(((x - m_xmin)*m_yres) / (m_xmax-m_xmin));
            if ((idx >= 0) && (idx < m_yres))
            {
                m_attractorsVector[idx] = x;
                if (m_attractorsOrbits[idx] == 0)
                {
                    // Orbit has passed the point [c_pos][idx]
                    m_attractorsOrbits[stackPointer] = idx;
                    m_attractorsVectorIndex[idx] = 1;
                    stackPointer++; 
                    if (stackPointer >= std::trunc(m_maxIter * m_stability))
                    {
                        stop = true;
                    }
                }
                else
                {
                    while (stackPointer > 0)
                    {                        
                        m_divergency_matrix[m_attractorsOrbits[stackPointer-1]][ix] = 1;
                        stackPointer--;
                    }     
                    stop = true;
                    // Orbit has already passed in [c_pos][idx]
                }
            }
            no_iterations++;
        }
        else
        {
            stop = true;
        }
    }
    //evaluateAttractors(ix);
    return(ret);
}

void Bifurcation::evaluateAttractors(long ix)
{
    long attractorIterations = 0;
    for(int iy=0; iy<m_yres; iy++)
    {
        if ((static_cast<double>(m_attractorsVectorIndex[iy])) >= m_maxIter * m_stability)
        {
            long attractorPosition = std::trunc(((m_attractorsVector[iy] * m_yres )/(m_xmax - m_xmin)) + m_yres/2);
            m_divergency_matrix[attractorPosition][ix] = m_attractorsVectorIndex[iy];
        }
    }     
}

void Bifurcation::storeImage(const char * standardPath)
{
    const std::chrono::system_clock::time_point timenow = std::chrono::system_clock::now();
    const std::time_t timestamp = std::chrono::system_clock::to_time_t(timenow);
    
    char filename_timestamp[100];
    std::strftime(filename_timestamp, sizeof(filename_timestamp), "%Y%m%d_%H%M%S", std::localtime(&timestamp));

    std::string fileNameXML(standardPath);
    fileNameXML += "/";
    fileNameXML += filename_timestamp;
    fileNameXML += "Bifurcation.xml";
     
    std::ofstream specs;
    specs.open(fileNameXML.c_str());
    specs << "<fractal fractaltype=\"Bifurcation\">" << std::endl;
    specs << "<imageresolution xres=" << m_xres << " yres=" << m_yres << "/>" << std::endl;
    specs << "<functiondomain>" << std::endl;
    specs << "    <topleftcorner x_min=" << m_xmin << " c_min=" << m_cmin << "/>" << std::endl;
    specs << "    <bottomrightcorner x_max=" << m_xmax << " c_max=" << m_cmax << "/>" << std::endl;
    specs << "</functiondomain>" << std::endl;
    specs << "<maxiteration> " << m_maxIter << " </maxiteration>" << std::endl;
    specs << "<initialpoint> " << m_initialPoint << " </initialpoint>" << std::endl;
    specs << "<orbitsdiscarded> " << m_noIterationToExclude << " </orbitsdiscarded>" << std::endl;
    specs << "<stability> " << m_stability << " </stability>" << std::endl;
    specs << "</fractal>" << std::endl;
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
}
