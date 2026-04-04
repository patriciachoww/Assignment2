/**
 * @file Statistics.h
 * @brief Generic statistics helper functions.
 *
 * Contains statistical routines that are not coupled
 * to the weather data type.
 *
 * @author Patricia
 * @date 31/03/2026
 */

#ifndef STATISTICS_H
#define STATISTICS_H

#include "../dateTreeLab8/Vector.H"

/**
 * @brief Calculate arithmetic mean.
 * @param values Input values
 * @return Mean, or 0.0 if empty
 */
double Mean(const Vector<double>& values);

/**
 * @brief Calculate sample standard deviation.
 * @param values Input values
 * @return Sample standard deviation, or 0.0 if insufficient data
 */
double SampleStdev(const Vector<double>& values);

/**
 * @brief Calculate mean absolute deviation.
 * @param values Input values
 * @return MAD, or 0.0 if empty
 */
double MAD(const Vector<double>& values);

/**
 * @brief Calculate total.
 * @param values Input values
 * @return Sum of values
 */
double Total(const Vector<double>& values);

/**
 * @brief Calculate sample Pearson Correlation Coefficient.
 * @param x First data series
 * @param y Second data series
 * @return sPCC, or 0.0 if invalid
 */
double SPCC(const Vector<double>& x, const Vector<double>& y);

#endif
