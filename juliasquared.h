#ifndef JULIASQUARED_H
#define JULIASQUARED_H

#include "juliaset.h"

class JuliaSquared : public JuliaSet
{
public:
    JuliaSquared();
    virtual ~JuliaSquared();
    virtual int msetlevel(double x_pos, double y_pos);
    virtual QRgb setColour(int level);

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
     * @brief m_mod divergence factor
     */
    double m_divergenceFactor;
};


inline void JuliaSquared::setMaxiter(int value)
{
    m_maxiter = value;
}

inline void JuliaSquared::setLx(double value)
{
    m_lx = value;
}

inline void JuliaSquared::setLy(double value)
{
    m_ly = value;
}

inline void JuliaSquared::setDivergencyFactor(double value)
{
    m_divergenceFactor = value;
}


#endif // JULIASQUARED_H
