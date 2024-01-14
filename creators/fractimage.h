#ifndef FRACTIMAGE_H
#define FRACTIMAGE_H

class FractImage
{
public:
    FractImage();
    virtual ~FractImage();
    /**
     * @brief setXres set horizontal resolution
     * @param value
     */
    void setXres(int value);
    /**
     * @brief setYres set horizontal resolution
     * @param value
     */
    void setYres(int value);
    /**
     * @brief setXmin set min x of the fractal window
     * @param value
     */
protected:
    /**
     * @brief m_xres image x resolution
     */
    int m_xres;
    /**
     * @brief m_yres image y resolution
     */
    int m_yres;

};

inline void FractImage::setXres(int value)
{
    m_xres = value;
}

inline void FractImage::setYres(int value)
{
    m_yres = value;
}

#endif // FRACTIMAGE_H
