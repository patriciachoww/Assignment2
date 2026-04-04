/**
 * @file WeatherDataStore.h
 * @brief Stores and manages weather records.
 *
 * Uses a BST to store records and provides
 * filtering functions for Assignment 2.
 *
 * @author Patricia
 * @date 31/03/2026
 */

#ifndef WEATHER_DATA_STORE_H
#define WEATHER_DATA_STORE_H

#include "../dateTreeLab8/Vector.H"
#include "../dateTreeLab8/Map.h"
#include "../Bst.H"
#include "WeatherRecord.h"
#include <string>

/**
 * @class WeatherDataStore
 * @brief Container for weather records.
 *
 * Stores records in a BST and provides
 * filtering functions for menu options.
 */
class WeatherDataStore
{
public:
    /**
     * @brief Construct an empty data store.
     */
    WeatherDataStore();

    /**
     * @brief Load weather data from multiple files listed in a source file.
     * @param sourceFile File containing the list of data file names
     * @return True if at least one record is loaded
     */
    bool LoadDataFiles(const std::string& sourceFile);

    /**
     * @brief Check whether data is loaded.
     * @return True if data is loaded
     */
    bool IsLoaded() const;

    /**
     * @brief Get wind speeds for a month and year.
     * @param month Month number
     * @param year Year number
     * @return Matching wind speeds
     */
    Vector<double> GetSpeedsForMonthYear(int month, int year) const;

    /**
     * @brief Get temperatures for a month and year.
     * @param month Month number
     * @param year Year number
     * @return Matching temperatures
     */
    Vector<double> GetTempsForMonthYear(int month, int year) const;

    /**
     * @brief Get solar values for a month and year.
     * @param month Month number
     * @param year Year number
     * @return Matching solar values
     */
    Vector<double> GetSolarForMonthYear(int month, int year) const;

    /**
     * @brief Get wind speeds for a month across all years.
     * @param month Month number
     * @return Matching wind speeds
     */
    Vector<double> GetSpeedsForMonthAllYears(int month) const;

    /**
     * @brief Get temperatures for a month across all years.
     * @param month Month number
     * @return Matching temperatures
     */
    Vector<double> GetTempsForMonthAllYears(int month) const;

    /**
     * @brief Get solar values for a month across all years.
     * @param month Month number
     * @return Matching solar values
     */
    Vector<double> GetSolarForMonthAllYears(int month) const;

private:
    Bst<WeatherRecord> records;   ///< BST storage
    bool loaded;                  ///< Load flag
    Map<int, int> monthCounts;    ///< Example Map usage

    static int s_targetMonth;
    static int s_targetYear;
    static Vector<double>* s_result;

    /**
     * @brief Insert one weather record.
     * @param record Weather record to insert
     */
    void InsertRecord(const WeatherRecord& record);

    /**
     * @brief Collect wind speeds for month/year.
     * @param record Current record
     */
    static void CollectSpeedsMonthYear(const WeatherRecord& record);

    /**
     * @brief Collect temperatures for month/year.
     * @param record Current record
     */
    static void CollectTempsMonthYear(const WeatherRecord& record);

    /**
     * @brief Collect solar values for month/year.
     * @param record Current record
     */
    static void CollectSolarMonthYear(const WeatherRecord& record);

    /**
     * @brief Collect wind speeds for month across all years.
     * @param record Current record
     */
    static void CollectSpeedsMonthAllYears(const WeatherRecord& record);

    /**
     * @brief Collect temperatures for month across all years.
     * @param record Current record
     */
    static void CollectTempsMonthAllYears(const WeatherRecord& record);

    /**
     * @brief Collect solar values for month across all years.
     * @param record Current record
     */
    static void CollectSolarMonthAllYears(const WeatherRecord& record);
};

#endif
