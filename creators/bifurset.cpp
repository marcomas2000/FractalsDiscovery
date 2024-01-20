#include "bifurset.h"

BifurSet::BifurSet(): m_cmin(0.0), m_cmax(0.0)
{
}

BifurSet::~BifurSet()
{
}

void BifurSet::resizeDivergencyMatrix(long xres, long yres)
{
    m_divergency_matrix.resize(yres);
    for(int i = 0 ; i < yres ; ++i)
    {
        m_divergency_matrix[i].resize(xres);
    }
}

void BifurSet::resizeAttractorVectors(long yres)
{
    m_attractorsVector.resize(yres);
    m_attractorsVectorIndex.resize(yres);
}

double BifurSet::createBifur()
{
    long divergent = 0, non_divergent = 0;
    int ix;
    double cy, ris;
 
    resizeDivergencyMatrix(m_xres, m_yres);
    resizeAttractorVectors(m_yres);
    for(ix=0; ix<m_xres; ix++)
    {
        cy=m_cmin+ix*(m_cmax-m_cmin)/(m_xres-1);
        ris = bifur(cy);
        if (ris == 0.0)
        {
            //m_divergency_matrix[iy][ix] = 0.0;
            non_divergent++;
        }
        else
        {
            //m_divergency_matrix[iy][ix] = ris;
            divergent++;
        }
    }
    return(static_cast<double>(non_divergent)/static_cast<double>(m_xres * m_yres));
}
