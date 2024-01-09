#ifndef LYAPUNOV_H
#define LYAPUNOV_H

#include "lyapset.h"

class Lyapunov: public LyapSet
{
public:
    Lyapunov();
    virtual ~Lyapunov();

    /**
     * @brief setLx sets Lx deviation
     * @param value
     */
    void setLx(double value);

    /**
     * @brief setLy sets Ly deviation
     * @param value
     */
    void setLy(double value);

    /**
     * @brief setDivergencyFactor
     * @param value
     */
    void setDivergencyFactor(double value);

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

private:
    /**
     * @brief maxiter max number of iterations for function msetlevel
     */
    int    m_maxiter;

    /**
     * @brief m_mod divergence factor
     */
    double m_divergenceFactor;
};

inline void Lyapunov::setMaxiter(int value)
{
    m_maxiter = value;
}

#endif // LYAPUNOV_H
