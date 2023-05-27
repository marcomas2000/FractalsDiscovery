#include <math.h>
#include "lyapunov.h"

Lyapunov::Lyapunov()
{
}

Lyapunov::~Lyapunov()
{
}

double Lyapunov::lyap(double a, double b, double x)
{
int i,j;
double c=log(2.0);
double tot=0.0;
double r,y;
long cont=0;

    i=0;
    //m_maxiter = 4000/len_suc;
    //m_maxiter = 4000;
    for(i=0;i<m_maxiter;i++)
    {
        for(j=0;j < m_suclen;j++)
        {
            if(m_suc[j]==0)
            {
                r=a;
            }
            else
            {
                r=b;
            }
            x=r*x*(1-x);
            y=r-2.0*r*x;
            if(y<0)
            {
                y=-y;
            }
            tot=tot+(log(y))/c;
            cont++;
        }
    }
    return(tot/cont);
}
