#ifndef BIFURCATION_H
#define BIFURCATION_H

#include "bifurset.h"

class Bifurcation: public BifurSet
{
public:
    Bifurcation();
    virtual ~Bifurcation();

    /**
     * @brief setNoIterationsToExclude
     * @param value
     */
    void setNoIterationsToExclude(int value);

    /**
     * @brief setInitialPoint
     * @param value
     */
    void setInitialPoint(double value);

    /**
     * @brief store data
     */
    void storeImage(const char * standardPath);

    /**
     * @brief bifur function defined in derived classes to check divergency in the specified position
     * @param value
     */
    virtual double bifur(double c_pos);

private:
    /**
     * @brief evaluateAttractors function defined in derived classes to check divergency in the specified position
     * @param value
     */
    void evaluateAttractors();

    /**
     * @brief m_noIterationToExclude max number of iterations to exclude
     */
    int    m_noIterationToExclude;

    /**
     * @brief m_initialPoint seed for iteration
     */
    int    m_initialPoint;

};

inline void Bifurcation::setNoIterationsToExclude(int value)
{
    m_noIterationToExclude = value;
}

inline void Bifurcation::setInitialPoint(double value)
{
    m_initialPoint = value;
}

#endif // BIFURCATION_H
