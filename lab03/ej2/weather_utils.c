#include <limits.h>
#include <stdlib.h>

#include "weather.h"
#include "weather_utils.h"

char* parse_month(int month) {
  char* months[MONTHS] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

  return months[month];
}

int find_historic_min_temp(WeatherTable array) {
  int min_temp = INT_MAX;

  for (int i = 0; i < YEARS; i++) {
    for (int j = 0; j < MONTHS; j++) {
      for (int k = 0; k < DAYS; k++) {
        if (array[i][j][k]._min_temp < min_temp) {
          min_temp = array[i][j][k]._min_temp;
        }
      }
    }
  }

  return min_temp;
}

void register_yearly_max_temp(WeatherTable array, int results[]) {
  for (int i = 0; i < YEARS; i++) {
    int max_temp = INT_MIN;

    for (int j = 0; j < MONTHS; j++) {
      for (int k = 0; k < DAYS; k++) {
        if (array[i][j][k]._max_temp > max_temp) {
          max_temp = array[i][j][k]._max_temp;
        }
      }
    }

    results[i] = max_temp;
  }
}

void register_yearly_max_rainfall_month(WeatherTable array, int results[]) {
  for (int i = 0; i < YEARS; i++) {
    int max_rainfall_month = 0;
    unsigned int max_rainfall_of_year = 0u;

    for (int j = 0; j < MONTHS; j++) {
      for (int k = 0; k < DAYS; k++) {
        if (array[i][j][k]._rainfall > max_rainfall_of_year) {
          max_rainfall_of_year = array[i][j][k]._rainfall;
          max_rainfall_month = j;
        }
      }
    }

    results[i] = max_rainfall_month;
  }
}

void print_analyzed_data(WeatherTable array) {
  int historic_min_temp;
  int yearly_max_temps[YEARS];
  int yearly_max_rainfall_months[YEARS];

  historic_min_temp = find_historic_min_temp(array);
  register_yearly_max_temp(array, yearly_max_temps);
  register_yearly_max_rainfall_month(array, yearly_max_rainfall_months);

  fprintf(stdout, "\n\n----- ANALYSIS OF GIVEN DATA -----\n\n");
  fprintf(stdout, "The lowest temperature registered was: %i,%iºC\n", historic_min_temp / 10, abs(historic_min_temp % 10));
  
  for (int i = 0; i < YEARS; i++) {
      fprintf(stdout, "The highest temperature in %i was: %i,%iºC\n", FST_YEAR + i, yearly_max_temps[i] / 10, abs(yearly_max_temps[i] % 10));
      fprintf(stdout, "The highest rainfall probability in %i was in %s\n", FST_YEAR + i, parse_month(yearly_max_rainfall_months[i]));
  }
}