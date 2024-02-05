#ifndef UNI1MINUSSQUARE_H
#define UNI1MINUSSQUARE_H

#include "bifurset.h"

/**
 * This class implements the algorithm for the investigation of the
 * bifurcation for the function y = c sin(x) 
*/
class Uni1MinusSquare: public BifurSet
{
public:
    /**
     * @brief Constzructor
     */
    Uni1MinusSquare();

    /**
     * @brief Destructor
     */
    virtual ~Uni1MinusSquare();

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

#endif // UNI1MINUSSQUARE_H
