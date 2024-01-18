#ifndef BIFURSET_H
#define BIFURSET_H

#include <vector>
#include "fractimage.h"

class BifurSet : public FractImage
{

public:
    BifurSet();
    virtual ~BifurSet();
    /**
     * @brief createJulia creates the file by calling the bifur function defined in the
     *          derived class
     */
    virtual double createBifur();

    /**
     * @brief setXmin set min x of the fractal window
     * @param value
     */
    virtual void setCmin(double value);
    /**
     * @brief setXmax set max x of the fractal window
     * @param value
     */
    virtual void setCmax(double value);
    /**
     * @brief setDivergencyFactor
     * @param value
     */
    virtual void setNoIterationsToExclude(int value) = 0;

protected:
    /**
     * @brief resizeDivergencyMatrix adapts matrix size to required size.
     * @param xres, yres 
     */
    void resizeDivergencyMatrix(long xres, long yres);

    /**
     * @brief coordinates of the "interval of investigation" in the function
     */
    double m_cmin, m_cmax;

    /**
     * @brief dynamic array to contain calculated divergency values
     */
    std::vector<std::vector<double> > m_divergency_matrix;

};

inline void BifurSet::setCmin(double value)
{
    m_cmin = value;
}

inline void BifurSet::setCmax(double value)
{
    m_cmax = value;
}

#endif // BIFURSET_H
