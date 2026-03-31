#include "Statistics.h"
#include <cmath>
#include <fstream>
#include <iomanip>

/**
 * @brief Calculates the mean of values.
 */
double Mean(const std::vector<double>& values)
{
    if (values.empty())
    {
        return 0.0; // Return 0 if no data
    }

    double sum = 0.0;

    // Sum all values
    for (std::size_t i = 0; i < values.size(); ++i)
    {
        sum += values[i];
    }

    // Compute average
    return sum / static_cast<double>(values.size());
}

/**
 * @brief Calculates sample standard deviation.
 */
double StandardDeviation(const std::vector<double>& values)
{
    if (values.size() < 2)
    {
        return 0.0; // Not enough data
    }

    double mean = Mean(values);
    double sum = 0.0;

    // Sum squared differences from mean
    for (std::size_t i = 0; i < values.size(); ++i)
    {
        double diff = values[i] - mean;
        sum += diff * diff;
    }

    // Sample standard deviation (n-1)
    return std::sqrt(sum / static_cast<double>(values.size() - 1));
}

/**
 * @brief Calculates mean absolute deviation.
 */
double MeanAbsoluteDeviation(const std::vector<double>& values)
{
    if (values.empty())
    {
        return 0.0; // Return 0 if no data
    }

    double mean = Mean(values);
    double sum = 0.0;

    // Sum absolute differences from mean
    for (std::size_t i = 0; i < values.size(); ++i)
    {
        sum += std::fabs(values[i] - mean);
    }

    // Compute average deviation
    return sum / static_cast<double>(values.size());
}

/**
 * @brief Calculates sample Pearson Correlation Coefficient.
 */
double SPCC(const std::vector<double>& x, const std::vector<double>& y)
{
    // Validate input sizes
    if (x.size() != y.size() || x.size() < 2)
    {
        return 0.0;
    }

    double meanX = Mean(x);
    double meanY = Mean(y);

    double num = 0.0;   // Covariance
    double sumX = 0.0;  // Variance of x
    double sumY = 0.0;  // Variance of y

    // Compute correlation components
    for (std::size_t i = 0; i < x.size(); ++i)
    {
        double dx = x[i] - meanX;
        double dy = y[i] - meanY;

        num += dx * dy;
        sumX += dx * dx;
        sumY += dy * dy;
    }

    const double EPSILON = 1e-10; // Tolerance for floating-point comparison

    // Avoid division by zero
    if (std::fabs(sumX) < EPSILON || std::fabs(sumY) < EPSILON)
    {
        return 0.0;
    }

    // Final Pearson correlation formula
    return num / std::sqrt(sumX * sumY);
}

/**
 * @brief Writes a stub CSV file for Lab 11 option 4.
 */
void WriteStubWindTempSolarCSV(int year)
{
    std::ofstream outFile("WindTempSolar.csv");

    // Check file opened successfully
    if (!outFile)
    {
        return;
    }

    // Write header
    outFile << year << std::endl;
    outFile << "Month,Average Wind Speed(stdev, mad),"
            << "Average Ambient Temperature(stdev, mad),"
            << "Total Solar Radiation" << std::endl;

    // Write sample data (stub)
    outFile << "January,5.5(1.2, 1.1),25.5(12.2, 11.3),196.4" << std::endl;
    outFile << "February,4.5(3.1, 2.9),27.5(10.1, 10.5),200.3" << std::endl;
}
