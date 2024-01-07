#ifndef JULIAEXP_H
#define JULIAEXP_H

#include "juliaset.h"

class JuliaExp : public JuliaSet
{
public:
    JuliaExp();
    virtual ~JuliaExp();
    virtual double checkDivergency(double x_pos, double y_pos);

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
     * @brief m_mod divergence factor
     */
    void storeImage(const char * standardPath);

private:
    /**
     * @brief maxiter max number of iterations for function msetlevel
     */
    int    m_maxiter;

    /**
     * @brief variations for msetlevel
     */

    double m_lx, m_ly;

    /**
     * @brief m_mod divergency factor
     */
    double m_divergencyFactor;

};


inline void JuliaExp::setMaxiter(int value)
{
    m_maxiter = value;
}

inline void JuliaExp::setLx(double value)
{
    m_lx = value;
}

inline void JuliaExp::setLy(double value)
{
    m_ly = value;
}

inline void JuliaExp::setDivergencyFactor(double value)
{
    m_divergencyFactor = value;
}


#endif // JULIAEXP_H
