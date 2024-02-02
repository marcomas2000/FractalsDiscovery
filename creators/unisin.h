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

#endif // UNISIN_H
