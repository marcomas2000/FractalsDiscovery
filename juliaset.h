#ifndef JULIASET_H
#define JULIASET_H

#include <QImage>
#include <QProgressDialog>
#include "fractimage.h"

class JuliaSet : public FractImage
{

public:
    JuliaSet();
    virtual ~JuliaSet();
    /**
     * @brief createJulia creates the file by calling the msetlevel function defined in the
     *          derived class
     */
    virtual void createJulia();

    /**
     * @brief msetlevel checks the convergence at the given point. it
     *                  is implemented in the derived classes
     * @param x_pos
     * @param y_pos
     * @return
     */
    virtual int msetlevel(double x_pos, double y_pos) = 0;
    /**
     * @brief setColour
     * @param level
     * @return
     */
    virtual QRgb setColour(int ris);
    /**
     * @brief setXmin set min x of the fractal window
     * @param value
     */
    virtual void setXmin(double value);
    /**
     * @brief setYmin set min y of the fractal window
     * @param value
     */
    virtual void setYmin(double value);
    /**
     * @brief setXmax set max x of the fractal window
     * @param value
     */
    virtual void setXmax(double value);
    /**
     * @brief setYmax set max y of the fractal window
     * @param value
     */
    virtual void setYmax(double value);

    /**
     * @brief getImage returns a pointer to the created image
     * @return
     */
    virtual QImage * getImage();

    /**
     * @brief setLx sets Lx deviation
     * @param value
     */
    virtual void setLx(double value) = 0;

    /**
     * @brief setLy sets Ly deviation
     * @param value
     */
    virtual void setLy(double value) = 0;

    /**
     * @brief setDivergencyFactor
     * @param value
     */
    virtual void setDivergencyFactor(double value) = 0;

    /**
     * @brief setDivergencyFactor
     * @param value
     */
    virtual void setMaxiter(int value) = 0;

private:
    /**
     * @brief coordinates of the "square of investigation" in the function
     */
    double m_xmin, m_ymin, m_xmax, m_ymax;

    /**
     * @brief m_image variable containing created image
     */
    QImage * m_image;
};

inline void JuliaSet::setXmin(double value)
{
    m_xmin = value;
}

inline void JuliaSet::setYmin(double value)
{
    m_ymin = value;
}

inline void JuliaSet::setXmax(double value)
{
    m_xmax = value;
}

inline void JuliaSet::setYmax(double value)
{
    m_ymax = value;
}

#endif // JULIASET_H
