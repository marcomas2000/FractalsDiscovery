#ifndef MANDELBROT_H
#define MANDELBROT_H

#include "mandelbrotset.h"

class Mandelbrot : public MandelbrotSet
{
public:
    Mandelbrot();
    virtual ~Mandelbrot();
    virtual double checkDivergency(double x_pos, double y_pos);

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

    /**
     * @brief storeImage
     */
    void storeImage(const char * standardPath);

private:
    /**
     * @brief maxiter max number of iterations for function msetlevel
     */
    int    m_maxiter;

    /**
     * @brief m_mod divergence factor
     */
    double m_divergencyFactor;
};

inline void Mandelbrot::setMaxiter(int value)
{
    m_maxiter = value;
}

inline void Mandelbrot::setDivergencyFactor(double value)
{
    m_divergencyFactor = value;
}


#endif // MANDELBROT_H
