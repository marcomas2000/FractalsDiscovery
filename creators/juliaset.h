#ifndef JULIASET_H
#define JULIASET_H

#include <vector>
#include "fractimage.h"

class JuliaSet : public FractImage
{

public:
    JuliaSet();
    virtual ~JuliaSet();
    /**
     * @brief createJulia creates the file by calling the msetlevel function defined in the
     *          derived class
     */
    virtual double createJulia();

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
     * @brief setLx sets Lx deviation
     * @param value
     */
    virtual void setLx(double value) = 0;

    /**
     * @brief setLy sets Ly deviation
     * @param value
     */
    virtual void setLy(double value) = 0;

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

inline void JuliaSet::setXmin(double value)
{
    m_xmin = value;
}

inline void JuliaSet::setYmin(double value)
{
    m_ymin = value;
}

inline void JuliaSet::setXmax(double value)
{
    m_xmax = value;
}

inline void JuliaSet::setYmax(double value)
{
    m_ymax = value;
}

#endif // JULIASET_H
