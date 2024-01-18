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
     * @brief bifur checks the convergence at the given point. it
     *                  is implemented in the derived classes
     * @param x_pos
     * @param y_pos
     * @return
     */
    double bifur(double a, double b, double x);

    /**
     * @brief store data
     */
    void storeImage(const char * standardPath);

private:
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
