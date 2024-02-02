#ifndef BIFURSET_H
#define BIFURSET_H

#include <vector>
#include "fractimage.h"
/**
 * This is an abstract class declaring part of the interface implemented in the
 * derived classes
*/
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
    virtual void setNoIterationsToExclude(int value);

    /**
     * @brief setInitialPoint Setter for parameter from GUI
     * @param value
     */
    virtual void setInitialPoint(double value);

    /**
     * @brief setMaxIter Setter for parameter from GUI
     * @param value
     */
    virtual void setMaxIter(int value);

    /**
     * @brief setStability Setter for parameter from GUI
     * @param value
     */
    virtual void setStability(double value);

    /**
     * @brief storeImage function to store creation parameters and data for images
     * @param standardPath folder where data is stored
     */
    virtual void storeImage(const char * standardPath) = 0;

    /**
     * @brief bifur function defined in derived classes to check divergency in the specified position
     * @param ix fixed value used in the iterations
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
     * @brief lower end of the "interval of investigation" in the function
     */
    double m_cmin; 

    /**
     * @brief upper end of the "interval of investigation" in the function
     */
    double m_cmax;

    /**
     * @brief lower end of the interval of investigation for attractors
     */
    double m_xmin;
    
    /**
     * @brief upper end of the interval of investigation for attractors
     */
    double m_xmax;

    /**
     * m_noIterationToExclude max number of iterations to exclude
     */
    int m_noIterationToExclude;

    /**
     * m_initialPoint seed for iteration
     */
    double m_initialPoint;

    /**
     * m_maxIter maximum number of iterations
     */
    int m_maxIter;

    /**
     * m_stability percentage of stable orbits to consider a point an attractor
     */
    double m_stability;

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

    /**
     * @brief dynamic array to check for potential attractors
     */
    std::vector<long> m_attractorsOrbits;


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

inline void BifurSet::setNoIterationsToExclude(int value)
{
    m_noIterationToExclude = value;
}

inline void BifurSet::setInitialPoint(double value)
{
    m_initialPoint = value;
}

inline void BifurSet::setMaxIter(int value)
{
    m_maxIter = value;
}

inline void BifurSet::setStability(double value)
{
    m_stability = value;
}

#endif // BIFURSET_H
