#include "lyapset.h"

LyapSet::LyapSet(): m_xmin(0.0), m_xmax(0.0),
    m_ymin(0.0), m_ymax(0.0), m_x(0.0), m_suclen(0)
{
    m_suc[0] = 0;
}

LyapSet::~LyapSet()
{
}

void LyapSet::resizeDivergencyMatrix(long xres, long yres)
{
    m_divergency_matrix.resize(yres);
    for(int i = 0 ; i < yres ; ++i)
    {
        m_divergency_matrix[i].resize(xres);
    }
}

double LyapSet::createLyap()
{
    long divergent = 0, non_divergent = 0;
    int ix, iy;
    double cx, cy, ris;
    resizeDivergencyMatrix(m_xres, m_yres);
    for(iy = 0; iy < m_yres; iy++)
    {
        cy=m_ymin+iy*(m_ymax-m_ymin)/(m_yres-1);
        for(ix=0;ix<m_xres;ix++)
        {
            cx=m_xmin+ix*(m_xmax-m_xmin)/(m_xres-1);
            ris = lyap(cy, cx, m_x);
            if(ris > 0.0)
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

void LyapSet::setInitialPoint(double value)
{
   m_x = value;
}

void LyapSet::setLyapSuccession(const char * strvalue)
{
    int i = 0;
    for(i = 0; strvalue[i] != 0; i++)
    {
        m_suc[i] = strvalue[i] - 48; // ASCII code for 0
    }
    m_suclen = i;
}

