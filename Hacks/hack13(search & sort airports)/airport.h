/**
 * This is a collection of utility functions involving
 * an airport structure.
 */
typedef struct {
    char *gpsId;
    char *type;
    char *name;
    double latitude;
    double longitude;
    int elevationFeet;
    char *city;
    char *countryAbbrv;
} Airport;

/**
 * Returns a deep copy of the given string
 */
char *deepStringCopy(const char *source);

/**
 * Converts degrees to radians using this equation:
 * Radians = (degrees / 180) * M_PI
*/
double degreesToRadians(double degrees);

/**
 * A function that prints the given Airport structure
 * to the standard output.
*/
void printAirport(const Airport *a);

/**
 * A factory function to create a new Airport with the given
 * attributes.  This function should make *deep* copies of each
 * of the relevant fields and return a pointer to the newly
 * created Airport structure.
 */
Airport* createAirport(const char* gpsId,
                       const char* type,
                       const char* name,
                       double latitude,
                       double longitude,
                       int elevationFeet,
                       const char* city,
                       const char* countryAbbrv);

/**
 * This function initializes an existing allocated
 * Airport structure with the given attributes.
 */
void initAirport(Airport* airport,
                 const char* gpsId,
                 const char* type,
                 const char* name,
                 double latitude,
                 double longitude,
                 int elevationFeet,
                 const char* city,
                 const char* countryAbbrv);

/**
 * Computes the air distance, in kilometers, between
 * the two Airports using their latitude/longitude
 */
double getAirDistance(const Airport* origin, const Airport* destination);

/**
 * A comparator function that orders the two Airport structures by
 * their GPS IDs in lexicographic order.
 */
int cmpByGPSId(const void* a, const void* b);

/**
 * A comparator function that orders the two Airport structures by
 * their type.
 */
int cmpByType(const void* a, const void* b);

/**
 * A comparator function that orders the two Airport structures by
 * their name in lexicographic order.
 */
int cmpByName(const void* a, const void* b);

/**
 * A comparator function that orders the two Airport structures by
 * their name in reverse lexicographic order.
 */
int cmpByNameDesc(const void* a, const void* b);

/**
 * A comparator function that orders the two Airport structures first by
 * country, then by city
 */
int cmpByCountryAbbrvCity(const void* a, const void* b);

/**
 * A comparator function that orders the given Airport structures
 * by their latitudes north to south
 */
int cmpByLatitude(const void* a, const void* b);

/**
 * A comparator function that orders the given Airport structures
 * by their longitudes west to east
 */
int cmpByLongitude(const void* a, const void* b);

/**
 * A comparator function that orders the two Airport structures by
 * their relative distance from Lincoln Municipal Airport
 * (0R2, 40.846176, -96.75471)
 * in ascending order according (closest to Lincoln would come first)
 */
int cmpByLincolnDistance(const void* a, const void* b);

/**
 * A function that generates and prints several reports on the
 * given array of Airport structures.
 */
void generateReports(Airport *airports, int n);