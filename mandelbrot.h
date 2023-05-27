#ifndef MANDELBROT_H
#define MANDELBROT_H

#include "juliaset.h"

class Mandelbrot : public JuliaSet
{
public:
    Mandelbrot();
    virtual ~Mandelbrot();
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
     * @brief setMaxiter;
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

inline void Mandelbrot::setMaxiter(int value)
{
    m_maxiter = value;
}

inline void Mandelbrot::setLx(double value)
{
    m_lx = value;
}

inline void Mandelbrot::setLy(double value)
{
    m_ly = value;
}

inline void Mandelbrot::setDivergencyFactor(double value)
{
    m_divergenceFactor = value;
}


#endif // MANDELBROT_H
