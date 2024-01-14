#include "juliaset.h"

JuliaSet::JuliaSet(): m_xmin(0.0), m_xmax(0.0), m_ymin(0.0), m_ymax(0.0)
{
}

JuliaSet::~JuliaSet()
{
}

void JuliaSet::resizeDivergencyMatrix(long xres, long yres)
{
    m_divergency_matrix.resize(yres);
    for(int i = 0 ; i < yres ; ++i)
    {
        m_divergency_matrix[i].resize(xres);
    }
}

double JuliaSet::createJulia()
{
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
    return(static_cast<double>(non_divergent)/static_cast<double>(divergent));
}
