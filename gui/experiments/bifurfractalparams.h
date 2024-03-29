#ifndef BIFURFRACTALPARAMS_H
#define BIFURFRACTALPARAMS_H

#include <QDialog>

namespace Ui {
class BifurFractalParams;
}

class BifurFractalParams : public QDialog
{
    Q_OBJECT

public:
    
    /**
     * @brief Constzructor
     */
    explicit BifurFractalParams(QWidget *parent = 0);

    /**
     * @brief Destructor
     */
    virtual ~BifurFractalParams();

    /**
     * @brief setWindowFunction Setter for window title
     */
    void setWindowFunction(std::string value);

    /**
     * @brief getWindowFunction Getter for window title
     */
    std::string getWindowFunction();

    /**
     * @brief getXres Getter for parameter from GUI
     * @return Horizontal resolution
     */
    int getXres();
    /**
     * @brief getYres Getter for parameter from GUI
     * @return Vertical resolution
     */
    int getYres();
    /**
     * @brief getXmin Getter for parameter from GUI
     * @return Minimum value orbits interval
     */
    double getXmin();
    /**
     * @brief getXmax Getter for parameter from GUI
     * @return Maximum value orbits interval
     */
    double getXmax();
    /**
     * @brief getCmin Getter for parameter from GUI
     * @return Minimum value c parameter
     */
    double getCmin();
    /**
     * @brief getCmax Getter for parameter from GUI
     * @return Maximum value c parameter
     */
    double getCmax();
    /**
     * @brief getNoIterationsToExclude Getter for parameter from GUI
     * @return Number of initial iteration to exclude to have stable orbits
     */
    int getNoIterationsToExclude();
    /**
     * @brief getInitialPoint Getter for parameter from GUI
     * @return Initial x point from which to start the iterations 
     */
    double getInitialPoint();
    /**
     * @brief getMaxIter Getter for parameter from GUI
     * @return Number of iterations to be performed (after the excluded ones)
     */
    int getMaxIter();
    /**
     * @brief getStability Getter for parameter from GUI
     * @return Percentage of orbits on a point to be considered an attractor
     */
    double getStability();

protected:
    /**
     * @brief m_windowTitle string to be shown on the Window title
     */
    std::string m_windowFunction;

private:
    Ui::BifurFractalParams *ui;
};

inline void BifurFractalParams::setWindowFunction(std::string value)
{
    m_windowFunction = value;
}

inline std::string BifurFractalParams::getWindowFunction()
{
    return m_windowFunction;
}

#endif // BIFURFRACTALPARAMS_H
