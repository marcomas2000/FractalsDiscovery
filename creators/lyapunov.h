#ifndef LYAPUNOV_H
#define LYAPUNOV_H

#include "lyapset.h"

class Lyapunov: public LyapSet
{
public:
    Lyapunov();
    virtual ~Lyapunov();

    /**
     * @brief setDivergencyFactor
     * @param value
     */
    void setMaxiter(int value);

    /**
     * @brief msetlevel checks the convergence at the given point. it
     *                  is implemented in the derived classes
     * @param x_pos
     * @param y_pos
     * @return
     */
    double lyap(double a, double b, double x);

    /**
     * @brief m_mod divergence factor
     */
    void storeImage(const char * standardPath);

private:
    /**
     * @brief maxiter max number of iterations for function msetlevel
     */
    int    m_maxiter;

};

inline void Lyapunov::setMaxiter(int value)
{
    m_maxiter = value;
}

#endif // LYAPUNOV_H
