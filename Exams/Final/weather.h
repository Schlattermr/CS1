typedef struct {
    char dateTimeStamp[17];
    double temperature;
} WeatherData;

/**
 * Loads weather data from the data file specified by the given
 * fileName.  The number of data points loaded from the file is
 * communicated in the pass-by-reference variable numPoints.
 *
 * Returns NULL for any error conditions.
 */
WeatherData *loadDataFromFile(const char *fileName, int *numPoints);

/**
 * Finds mean temperature of dataset by adding all
 * temperatures together and dividing by the total
 * number of temperatures there are
*/
double findMeanTemp(WeatherData *a, int n);

/**
 * A comparator for WeatherData structures that orders them
 * by date (oldest to newest, lexicographically).
 */
int weatherDataByDate(const void* a, const void* b);

/**
 * A comparator for WeatherData structures that orders them
 * by temperature (lowest to highest).
 */
int weatherDataByTemperature(const void* a, const void* b);