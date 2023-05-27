#ifndef ATTRACTHENON_H
#define ATTRACTHENON_H

#include "attractors.h"

class AttractHenon : public Attractors
{
public:
    AttractHenon();
    virtual ~AttractHenon();
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

inline void AttractHenon::setMaxiter(int value)
{
    m_maxiter = value;
}

inline void AttractHenon::setLx(double value)
{
    m_lx = value;
}

inline void AttractHenon::setLy(double value)
{
    m_ly = value;
}

inline void AttractHenon::setDivergencyFactor(double value)
{
    m_divergenceFactor = value;
}


#endif // ATTRACTHENON_H
