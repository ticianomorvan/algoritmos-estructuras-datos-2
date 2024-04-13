#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include "weather.h"
#include "array_helpers.h"

/**
 * @brief return the name of the given month, based on its index
 * @param[in] month Month index, from 0 to 11
*/
char* parse_month(int month);

/**
 * @brief return the lowest minimum temperature of the entire time period.
 * @param [in] array An array of weather reports
*/
int find_historic_min_temp(WeatherTable array);

/**
 * @brief returns an array of the highest maximum temperatures for each year
 * @param [in] array An array of weather reports
 * @param [out] results An array of maximum temperatures 
*/
void register_yearly_max_temp(WeatherTable array, int results[]);

/**
 * @brief returns an array containing the index of the month with more rainfall probability of each year.
 * @param [in] array An array of weather reports
 * @param [out] results An array of month indexes
*/
void register_yearly_max_rainfall_month(WeatherTable array, int results[]);

/**
 * @brief executes different analysis and prints their results.
 * @param [in] array An array of weather reports.
*/
void print_analyzed_data(WeatherTable array);

#endif