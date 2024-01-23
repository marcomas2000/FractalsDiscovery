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
     * @brief createBifur creates the file by calling the bifur function defined in the
     *          derived class
     */
    virtual double createBifur();

    /**
     * @brief setCmin set min c of the fractal window
     * @param value
     */
    virtual void setCmin(double value);

    /**
     * @brief setCmax set max c of the fractal window
     * @param value
     */
    virtual void setCmax(double value);

    /**
     * @brief setXmin Setter for the parameter from the GUI
     * @param value
     */
    virtual void setXmin(double value);

    /**
     * @brief setXmax Setter for the parameter from the GUI
     * @param value
     */
    virtual void setXmax(double value);

    /**
     * @brief setNoIterationsToExclude number of iteration to exclude before reaching a stable orbit
     * @param value
     */
    virtual void setNoIterationsToExclude(int value) = 0;

    /**
     * @brief bifur function defined in derived classes to check divergency in the specified position
     * @param value
     */
    virtual double bifur(long ix) = 0;

protected:
    /**
     * @brief resizeDivergencyMatrix adapts matrix size to required size.
     * @param xres, yres 
     */
    void resizeDivergencyMatrix(long xres, long yres);

    /**
     * @brief resizeAttractorVectors adapts investigation structures to required size.
     * @param yres 
     */
    void resizeAttractorVectors(long yres);

    /**
     * @brief coordinates of the "interval of investigation" in the function
     */
    double m_cmin, m_cmax;

    /**
     * @brief coordinates of the interval of investigation for attractors
     */
    double m_xmin, m_xmax;

    /**
     * @brief dynamic array to contain attractor points
     */
    std::vector<std::vector<double> > m_divergency_matrix;

    /**
     * @brief dynamic array to contain calculated divergency values
     */
    std::vector<double> m_attractorsVector;

    /**
     * @brief dynamic array to contain calculated divergency values
     */
    std::vector<long> m_attractorsVectorIndex;


};

inline void BifurSet::setCmin(double value)
{
    m_cmin = value;
}

inline void BifurSet::setCmax(double value)
{
    m_cmax = value;
}

inline void BifurSet::setXmin(double value)
{
    m_xmin = value;
}

inline void BifurSet::setXmax(double value)
{
    m_xmax = value;
}

#endif // BIFURSET_H
