#ifndef UNISIN_H
#define UNISIN_H

#include "bifurset.h"

/**
 * This class implements the algorithm for the investigation of the
 * bifurcation for the function y = c sin(x) 
*/
class UniSin: public BifurSet
{
public:
    /**
     * @brief Constzructor
     */
    UniSin();

    /**
     * @brief Destructor
     */
    virtual ~UniSin();

    /**
     * @brief setNoIterationsToExclude Setter for parameter from GUI
     * @param value
     */
    void setNoIterationsToExclude(int value);

    /**
     * @brief setInitialPoint Setter for parameter from GUI
     * @param value
     */
    void setInitialPoint(double value);

    /**
     * @brief setMaxIter Setter for parameter from GUI
     * @param value
     */
    void setMaxIter(int value);

    /**
     * @brief setStability Setter for parameter from GUI
     * @param value
     */
    void setStability(double value);

    /**
     * @brief storeImage function to store creation parameters and data for images
     * @param standardPath folder where data is stored
     */
    void storeImage(const char * standardPath);

    /**
     * @brief bifur function for the discovery of stable orbits
     * @param ix fixed value used in the iterations
     */
    virtual double bifur(long ix);

private:
    /**
     * @brief evaluateAttractors function defined in derived classes to check divergency in the specified position
     * @param value
     */
    void evaluateAttractors(long ix);

    /*
     * m_noIterationToExclude max number of iterations to exclude
     */
    int m_noIterationToExclude;

    /*
     * m_initialPoint seed for iteration
     */
    int m_initialPoint;

    /*
     * m_maxIter maximum number of iterations
     */
    int m_maxIter;

    /*
     * m_stability percentage of stable orbits to consider a point an attractor
     */
    double m_stability;

};

inline void UniSin::setNoIterationsToExclude(int value)
{
    m_noIterationToExclude = value;
}

inline void UniSin::setInitialPoint(double value)
{
    m_initialPoint = value;
}

inline void UniSin::setMaxIter(int value)
{
    m_maxIter = value;
}

inline void UniSin::setStability(double value)
{
    m_stability = value;
}

#endif // UNISIN_H
