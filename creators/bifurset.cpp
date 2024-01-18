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

double BifurSet::createBifur()
{
    /***
    long divergent = 0, non_divergent = 0;
    int ix, iy;
    double cx, cy, ris;
 
    resizeDivergencyMatrix(m_xres, m_yres);
    for(iy=0; iy<m_yres; iy++)
    {
        cy=m_ymin+iy*(m_ymax-m_ymin)/(m_yres-1);
        for(ix=0;ix<m_xres;ix++)
        {
            cx=m_xmin+ix*(m_xmax-m_xmin)/(m_xres-1);
            ris = checkDivergency(cx, cy);
            if (ris == 0.0)
            {
                m_divergency_matrix[iy][ix] = 0.0;
                non_divergent++;
            }
            else
            {
                m_divergency_matrix[iy][ix] = ris;
                divergent++;
            }
        }
    }
    ****/
    return(0.0);
}
