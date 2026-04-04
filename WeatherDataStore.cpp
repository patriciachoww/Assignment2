#include "WeatherDataStore.h"
#include <fstream>
#include <sstream>
#include <iostream>

// ===== Static variables =====
int WeatherDataStore::s_targetMonth = 0;
int WeatherDataStore::s_targetYear = 0;
Vector<double>* WeatherDataStore::s_result = nullptr;

/**
 * @brief Constructor.
 */
WeatherDataStore::WeatherDataStore()
    : records(), loaded(false), monthCounts()
{
}

/**
 * @brief Insert record into BST + Map
 */
void WeatherDataStore::InsertRecord(const WeatherRecord& record)
{
    records.Insert(record);

    int month = record.GetDate().GetMonth();

    if (monthCounts.HasKey(month))
    {
        monthCounts.Set(month, monthCounts.Get(month) + 1);
    }
    else
    {
        monthCounts.Set(month, 1);
    }
}

/**
 * 🔥 REAL FILE LOADER (IMPORTANT)
 */
bool WeatherDataStore::LoadDataFiles(const std::string& sourceFile)
{
    records.Clear();
    monthCounts.Clear();
    loaded = false;

    std::ifstream listFile(sourceFile.c_str());

    if (!listFile.is_open())
    {
        std::cout << "Cannot open source file: " << sourceFile << std::endl;
        return false;
    }

    std::cout << "Opened source file: " << sourceFile << std::endl;

    std::string fileName;
    bool insertedAny = false;

    while (std::getline(listFile, fileName))
    {
        if (fileName.empty())
        {
            continue;
        }

        std::string path = "data/" + fileName;
        std::ifstream dataFile(path.c_str());

        if (!dataFile.is_open())
        {
            std::cout << "Cannot open data file: " << path << std::endl;
            continue;
        }

        std::cout << "Opened data file: " << path << std::endl;

        std::string line;

        // skip header
        std::getline(dataFile, line);

        int count = 0;

        while (std::getline(dataFile, line))
        {
            if (line.empty())
            {
                continue;
            }

            std::stringstream ss(line);

            std::string dateStr, timeStr;
            std::string speedStr, tempStr, solarStr;

            std::getline(ss, dateStr, ',');
            std::getline(ss, timeStr, ',');
            std::getline(ss, speedStr, ',');
            std::getline(ss, tempStr, ',');
            std::getline(ss, solarStr, ',');

            if (dateStr.empty())
            {
                continue;
            }

            int day = 0, month = 0, year = 0;
            char slash1 = '/', slash2 = '/';

            std::stringstream dateSS(dateStr);
            dateSS >> day >> slash1 >> month >> slash2 >> year;

            if (dateSS.fail())
            {
                continue;
            }

            double speed = atof(speedStr.c_str());
            double temp  = atof(tempStr.c_str());
            double solar = atof(solarStr.c_str());

            WeatherRecord record(Date(day, month, year), speed, temp, solar);
            InsertRecord(record);

            insertedAny = true;
            count++;
        }

        std::cout << "Inserted records from file: " << count << std::endl;

        dataFile.close();
    }

    listFile.close();

    loaded = insertedAny;

    if (loaded)
    {
        std::cout << "Data loaded successfully." << std::endl;
    }
    else
    {
        std::cout << "No records were loaded." << std::endl;
    }

    return loaded;
}

/**
 * ===== FILTER FUNCTIONS =====
 */

Vector<double> WeatherDataStore::GetSpeedsForMonthYear(int month, int year) const
{
    Vector<double> result;

    s_targetMonth = month;
    s_targetYear = year;
    s_result = &result;

    records.InOrder(CollectSpeedsMonthYear);

    s_result = nullptr;
    return result;
}

Vector<double> WeatherDataStore::GetTempsForMonthYear(int month, int year) const
{
    Vector<double> result;

    s_targetMonth = month;
    s_targetYear = year;
    s_result = &result;

    records.InOrder(CollectTempsMonthYear);

    s_result = nullptr;
    return result;
}

Vector<double> WeatherDataStore::GetSolarForMonthYear(int month, int year) const
{
    Vector<double> result;

    s_targetMonth = month;
    s_targetYear = year;
    s_result = &result;

    records.InOrder(CollectSolarMonthYear);

    s_result = nullptr;
    return result;
}

Vector<double> WeatherDataStore::GetSpeedsForMonthAllYears(int month) const
{
    Vector<double> result;

    s_targetMonth = month;
    s_result = &result;

    records.InOrder(CollectSpeedsMonthAllYears);

    s_result = nullptr;
    return result;
}

Vector<double> WeatherDataStore::GetTempsForMonthAllYears(int month) const
{
    Vector<double> result;

    s_targetMonth = month;
    s_result = &result;

    records.InOrder(CollectTempsMonthAllYears);

    s_result = nullptr;
    return result;
}

Vector<double> WeatherDataStore::GetSolarForMonthAllYears(int month) const
{
    Vector<double> result;

    s_targetMonth = month;
    s_result = &result;

    records.InOrder(CollectSolarMonthAllYears);

    s_result = nullptr;
    return result;
}

/**
 * ===== CALLBACKS =====
 */

/**
 * @brief Collect wind speeds for month/year.
 * @param r Current weather record
 */
void WeatherDataStore::CollectSpeedsMonthYear(const WeatherRecord& r)
{
    int month = static_cast<int>(r.GetDate().GetMonth());
    int year = static_cast<int>(r.GetDate().GetYear());

    if (month == s_targetMonth && year == s_targetYear)
    {
        s_result->push_back(r.GetSpeed());
    }
}

/**
 * @brief Collect temperatures for month/year.
 * @param r Current weather record
 */
void WeatherDataStore::CollectTempsMonthYear(const WeatherRecord& r)
{
    int month = static_cast<int>(r.GetDate().GetMonth());
    int year = static_cast<int>(r.GetDate().GetYear());

    if (month == s_targetMonth && year == s_targetYear)
    {
        s_result->push_back(r.GetTemperature());
    }
}

/**
 * @brief Collect solar values for month/year.
 * @param r Current weather record
 */
void WeatherDataStore::CollectSolarMonthYear(const WeatherRecord& r)
{
    int month = static_cast<int>(r.GetDate().GetMonth());
    int year = static_cast<int>(r.GetDate().GetYear());

    if (month == s_targetMonth && year == s_targetYear)
    {
        s_result->push_back(r.GetSolar());
    }
}

/**
 * @brief Collect wind speeds for all years by month.
 * @param r Current weather record
 */
void WeatherDataStore::CollectSpeedsMonthAllYears(const WeatherRecord& r)
{
    int month = static_cast<int>(r.GetDate().GetMonth());

    if (month == s_targetMonth)
    {
        s_result->push_back(r.GetSpeed());
    }
}

/**
 * @brief Collect temperatures for all years by month.
 * @param r Current weather record
 */
void WeatherDataStore::CollectTempsMonthAllYears(const WeatherRecord& r)
{
    int month = static_cast<int>(r.GetDate().GetMonth());

    if (month == s_targetMonth)
    {
        s_result->push_back(r.GetTemperature());
    }
}

/**
 * @brief Collect solar values for all years by month.
 * @param r Current weather record
 */
void WeatherDataStore::CollectSolarMonthAllYears(const WeatherRecord& r)
{
    int month = static_cast<int>(r.GetDate().GetMonth());

    if (month == s_targetMonth)
    {
        s_result->push_back(r.GetSolar());
    }
}
