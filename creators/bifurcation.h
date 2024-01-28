#ifndef BIFURCATION_H
#define BIFURCATION_H

#include "bifurset.h"

class Bifurcation: public BifurSet
{
public:
    /**
     * @brief Constzructor
     */
    Bifurcation();

    /**
     * @brief Destructor
     */
    virtual ~Bifurcation();

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
     * @param c_pos fixed value used in the iterations
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

inline void Bifurcation::setNoIterationsToExclude(int value)
{
    m_noIterationToExclude = value;
}

inline void Bifurcation::setInitialPoint(double value)
{
    m_initialPoint = value;
}

inline void Bifurcation::setMaxIter(int value)
{
    m_maxIter = value;
}

inline void Bifurcation::setStability(double value)
{
    m_stability = value;
}

#endif // BIFURCATION_H
