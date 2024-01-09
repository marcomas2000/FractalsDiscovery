#ifndef LYAPSET_H
#define LYAPSET_H

#include <QImage>
#include <QProgressDialog>
#include "fractimage.h"

const int MAXCOLORS = 4;
class LyapSet  : public FractImage
{
public:
    LyapSet();
    virtual ~LyapSet();
    /**
     * @brief createJulia creates the file by calling the msetlevel function defined in the
     *          derived class
     */
    virtual void createLyap();

    /**
     * @brief msetlevel checks the convergence at the given point. it
     *                  is implemented in the derived classes
     * @param x_pos
     * @param y_pos
     * @return
     */
    virtual double lyap(double a, double b, double x) = 0;
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
     * @brief setMaxiter
     * @param value
     */
    virtual void setMaxiter(int value) = 0;

    void setInitialPoint(double value);

    void setLyapSuccession(QString value);

protected:
    int m_suc[30];
    int m_suclen;

private:
    int cerca(double num);
    /**
     * @brief coordinates of the "square of investigation" in the function
     */
    double m_xmin, m_ymin, m_xmax, m_ymax;

    /**
     * @brief m_image variable containing created image
     */
    QImage * m_image;

    double m_x;

};

inline void LyapSet::setXmin(double value)
{
    m_xmin = value;
}

inline void LyapSet::setYmin(double value)
{
    m_ymin = value;
}

inline void LyapSet::setXmax(double value)
{
    m_xmax = value;
}

inline void LyapSet::setYmax(double value)
{
    m_ymax = value;
}

#endif // LYAPSET_H
