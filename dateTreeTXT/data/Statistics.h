/**
 * @file Statistics.h
 * @brief Statistics helper functions for Assignment 2.
 *
 * Contains generic maths/statistics routines so they are not
 * tied to any specific data type (e.g., weather data).
 *
 * @author Patricia
 * @date 31/03/2026
 */

#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>

/**
 * @brief Calculates the mean of values.
 * @param values Vector of numeric values
 * @return Mean value, or 0.0 if empty
 */
double Mean(const std::vector<double>& values); // Average of values

/**
 * @brief Calculates sample standard deviation.
 * @param values Vector of numeric values
 * @return Standard deviation, or 0.0 if insufficient data
 */
double StandardDeviation(const std::vector<double>& values); // Spread of data (n-1)

/**
 * @brief Calculates mean absolute deviation.
 * @param values Vector of numeric values
 * @return MAD value, or 0.0 if empty
 */
double MeanAbsoluteDeviation(const std::vector<double>& values); // Avg absolute distance from mean

/**
 * @brief Calculates sample Pearson Correlation Coefficient.
 * @param x First data set
 * @param y Second data set
 * @return sPCC value, or 0.0 if invalid
 */
double SPCC(const std::vector<double>& x, const std::vector<double>& y); // Relationship strength (-1 to 1)

/**
 * @brief Writes a stub CSV file for Lab 11 option 4.
 * @param year Requested year
 */
void WriteStubWindTempSolarCSV(int year); // Outputs sample CSV file

#endif
