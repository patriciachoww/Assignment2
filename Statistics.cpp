/**
 * @file Statistics.cpp
 * @brief Implementation of statistical functions.
 *
 * Provides functions to compute mean, standard deviation,
 * mean absolute deviation, total, and Pearson correlation.
 *
 * @author Patricia
 * @date 31/03/2026
 */

#include "Statistics.h"
#include <cmath>

/**
 * @brief Calculate arithmetic mean.
 * @param values Input data
 * @return Mean value
 */
double Total(const Vector<double>& values)
{
    double sum = 0.0;

    for (int i = 0; i < values.Size(); i++)
    {
        sum += values[i];
    }

    return sum;
}

/**
 * @brief Calculate arithmetic mean.
 * @param values Input data
 * @return Mean value
 */
double Mean(const Vector<double>& values)
{
    if (values.Size() == 0)
    {
        return 0.0;
    }

    return Total(values) / values.Size();
}

/**
 * @brief Calculate sample standard deviation.
 * @param values Input data
 * @return Sample standard deviation
 */
double SampleStdev(const Vector<double>& values)
{
    if (values.Size() < 2)
    {
        return 0.0;
    }

    double mean = Mean(values);
    double sum = 0.0;

    for (int i = 0; i < values.Size(); i++)
    {
        double diff = values[i] - mean;
        sum += diff * diff;
    }

    return std::sqrt(sum / (values.Size() - 1));
}

/**
 * @brief Calculate mean absolute deviation.
 * @param values Input data
 * @return MAD value
 */
double MAD(const Vector<double>& values)
{
    if (values.Size() == 0)
    {
        return 0.0;
    }

    double mean = Mean(values);
    double sum = 0.0;

    for (int i = 0; i < values.Size(); i++)
    {
        double diff = values[i] - mean;

        if (diff < 0.0)
        {
            diff = -diff;
        }

        sum += diff;
    }

    return sum / values.Size();
}

/**
 * @brief Calculate sample Pearson Correlation Coefficient.
 * @param x First series
 * @param y Second series
 * @return sPCC value
 */
double SPCC(const Vector<double>& x, const Vector<double>& y)
{
    if (x.Size() != y.Size() || x.Size() < 2)
    {
        return 0.0;
    }

    double meanX = Mean(x);
    double meanY = Mean(y);

    double numerator = 0.0;
    double sumX = 0.0;
    double sumY = 0.0;

    for (int i = 0; i < x.Size(); i++)
    {
        double dx = x[i] - meanX;
        double dy = y[i] - meanY;

        numerator += dx * dy;
        sumX += dx * dx;
        sumY += dy * dy;
    }

    if (std::fabs(sumX) < 1e-9 || std::fabs(sumY) < 1e-9)
    {
        return 0.0;
    }

    return numerator / std::sqrt(sumX * sumY);
}
