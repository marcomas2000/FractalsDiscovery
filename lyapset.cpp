#include "lyapset.h"

LyapSet::LyapSet(): m_xmin(0.0), m_xmax(0.0),
    m_ymin(0.0), m_ymax(0.0), m_image(0), m_x(0.0), m_suclen(0)
{
    m_suc[0] = 0;
}

LyapSet::~LyapSet()
{
    if (m_image != 0)
    {
        delete m_image;
        m_image = 0;
    }
}

void LyapSet::createLyap()
{
    int ix, iy, level;
    double cx, cy, ris;

    m_image = new QImage(m_xres, m_yres, QImage::Format_RGB32);
    QRgb value;

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
            ris = lyap(cy, cx, m_x);
            if(ris>0.0)
            {
              level=0;
            }
            else
            {
              level=cerca(ris);
            }
            switch(level)
            {
            case 0:
                value = qRgb(0, 0, 0);
                m_image->setPixel(ix, iy, value);
                break;
            case 1:
                value = qRgb(255, 211, 0);
                m_image->setPixel(ix, iy, value);
                break;
            case 2:
                value = qRgb(255, 233, 0);
                m_image->setPixel(ix, iy, value);
                break;
            case 3:
                value = qRgb(255, 250, 0);
                m_image->setPixel(ix, iy, value);
                break;
            case 4:
                value = qRgb(255, 255, 255);
                m_image->setPixel(ix, iy, value);
                break;
            default:
                value = qRgb(0, 0, 0);
                m_image->setPixel(ix, iy, value);
                break;
            }
        }
    }
    progress.setValue(m_xres);
}

int LyapSet::cerca(double num)
{
/*******
    int ret = MAXCOLORS-1;

    if (num<-0.40)
    {
        ret = MAXCOLORS-1;
    }
    else if (num<-0.25)
    {
        ret = MAXCOLORS-2;
    }
    else if (num>-0.25)
    {
        ret = MAXCOLORS-3;
    }
********/
    int ret = MAXCOLORS;
    if (num == 0.0)
    {
        ret = 4;
    }
    else if (num > 0.0)
    {
        ret = 0;
    }
    else if (num < -1.85)
    {
        ret = 0;
    }
    else if (num < -0.40)
    {
        ret = 3;
    }
    else if (num < -0.25)
    {
        ret = 2;
    }
    else if ((num > -0.25) && (num < 0.0))
    {
        ret = 1;
    }
    return ret;
}

QImage * LyapSet::getImage()
{
    return m_image;
}

void LyapSet::setInitialPoint(double value)
{
   m_x = value;
}

void LyapSet::setLyapSuccession(QString value)
{
    for(int i = 0; i < value.length(); i++)
    {
        if (value.at(i).isDigit())
        {
            m_suc[i] = value.at(i).digitValue();
        }
    }
    m_suclen = value.length();
}

