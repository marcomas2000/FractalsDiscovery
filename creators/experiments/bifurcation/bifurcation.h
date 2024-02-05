#ifndef BIFURCATION_H
#define BIFURCATION_H

#include "bifurset.h"

/**
 * This class implements the algorithm for the investigation of the
 * bifurcation for the function y = pow(x,2) + c 
*/
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
     * @brief bifur function for the discovery of stable orbits
     * @param ix fixed value used in the iterations
     */
    virtual double bifur(long ix);

    /**
     * @brief storeImage function to store creation parameters and data for images
     * @param standardPath folder where data is stored
     */
    void storeImage(const char * standardPath);

};


#endif // BIFURCATION_H
