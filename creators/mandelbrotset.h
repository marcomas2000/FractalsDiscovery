#ifndef MANDELBROTSET_H
#define MANDELBROTSET_H

#include <vector>
#include "fractimage.h"

class MandelbrotSet : public FractImage
{

public:
    MandelbrotSet();
    virtual ~MandelbrotSet();
    /**
     * @brief createJulia creates the file by calling the msetlevel function defined in the
     *          derived class
     */
    virtual double createMandelbrot();

    /**
     * @brief setXmin set min x of the fractal window
     * @param value
     */
    virtual void setXmin(double value);
    /**
     * @brief setYmin set min y of the fractal window
     * @param value
     */
    virtual void setYmin(double value);
    /**
     * @brief setXmax set max x of the fractal window
     * @param value
     */
    virtual void setXmax(double value);
    /**
     * @brief setYmax set max y of the fractal window
     * @param value
     */
    virtual void setYmax(double value);

    /**
     * @brief setDivergencyFactor
     * @param value
     */
    virtual void setDivergencyFactor(double value) = 0;

    /**
     * @brief setDivergencyFactor
     * @param value
     */
    virtual void setMaxiter(int value) = 0;

    /**
     * @brief checkDivergency function defined in derived classes to check divergency in the specified position
     * @param value
     */
    virtual double checkDivergency(double x_pos, double y_pos) = 0;

protected:
    /**
     * @brief resizeDivergencyMatrix adapts matrix size to required size.
     * @param xsize, ysite 
     */
    void resizeDivergencyMatrix(long xres, long yres);

    /**
     * @brief coordinates of the "square of investigation" in the function
     */
    double m_xmin, m_ymin, m_xmax, m_ymax;

    /**
     * @brief dynamic array to contain calculated divergency values
     */
    std::vector<std::vector<double> > m_divergency_matrix;

};

inline void MandelbrotSet::setXmin(double value)
{
    m_xmin = value;
}

inline void MandelbrotSet::setYmin(double value)
{
    m_ymin = value;
}

inline void MandelbrotSet::setXmax(double value)
{
    m_xmax = value;
}

inline void MandelbrotSet::setYmax(double value)
{
    m_ymax = value;
}

#endif // MANDELBROTSET_H
