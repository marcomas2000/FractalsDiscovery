#include "attractors.h"

Attractors::Attractors(): m_xmin(0.0), m_ymin(0.0), m_xmax(0.0), m_ymax(0.0), m_image(0)
{
}

Attractors::~Attractors()
{
    if (m_image != 0)
    {
        delete m_image;
        m_image = 0;
    }
}

void Attractors::createAttractor()
{
    int ix, iy, ris;
    double cx, cy;
    QRgb value;

    m_image = new QImage(m_xres, m_yres, QImage::Format_RGB32);

    QProgressDialog progress("Creating image...", "Cancel creation", 0, m_yres);
    progress.setMinimumDuration(500);
    progress.setWindowModality(Qt::WindowModal);
    for(iy=0;((iy<m_yres) && (progress.wasCanceled() == false));iy++)
    {
        progress.setValue(iy);
        cy=m_ymin+iy*(m_ymax-m_ymin)/(m_yres-1);
        for(ix=0;ix<m_xres;ix++)
        {
            cx=m_xmin+ix*(m_xmax-m_xmin)/(m_xres-1);
            ris = msetlevel(cx, cy);
            value = setColour(ris);
            m_image->setPixel(ix, iy, value);
        }
    }
    progress.setValue(m_xres);
}

QImage * Attractors::getImage()
{
    return m_image;
}

QRgb Attractors::setColour(int ris)
{
    QRgb value;

    int level=ris%2;
    if(level==1)
    {
        value = qRgb(255, 255, 255);
    }
    else
    {
        value = qRgb(0, 0, 0);
    }
    return value;
}
