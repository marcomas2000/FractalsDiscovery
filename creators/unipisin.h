#ifndef UNIPISIN_H
#define UNIPISIN_H

#include "bifurset.h"

/**
 * This class implements the algorithm for the investigation of the
 * bifurcation for the function y = sin( PI x) + c
*/
class UniPiSin: public BifurSet
{
public:
    /**
     * @brief Constzructor
     */
    UniPiSin();

    /**
     * @brief Destructor
     */
    virtual ~UniPiSin();

    /**
     * @brief storeImage function to store creation parameters and data for images
     * @param standardPath folder where data is stored
     */
    virtual void storeImage(const char * standardPath);

    /**
     * @brief bifur function for the discovery of stable orbits
     * @param ix fixed value used in the iterations
     */
    virtual double bifur(long ix);

};

#endif // UNIPISIN_H
