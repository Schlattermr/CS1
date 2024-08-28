/**
 * Converts degree to radians using the equation
 * (degrees * pi) / 180
 */
double degreesToRadians(double degree);

/**
 * Computes air distance between two locations identified by
 * their latitude and longitude by using the Spherical Law of Cosines
 *
 * distance = arccos(sin(originalLatitude) * sin(destinationLatitude) + cos(originalLatitude) * cos(destinationLatitude) * cos(difference of longitutdes)) * radius of earth
 *
 * Where the radius of the earth is 6371km
 *
 * Degree inputs will be converted to radians using the degreesToRadians function
 * Latitude will be between [-90,90] and longitude will be between [-180,180]
 * Negative values correspond to southern and western hemispheres
 */
double getAirDistance(double originLatitude, double originLongitude, double destinationLatitude, double destinationLongitude);

/**
 * Calculates time dilation that occurs for a fast traveling object
 * using the Lorentz equation
 *
 * T = t / sqrt(1 - ((v * v) / (c * c))
 *
 * Where
 * T = dilated time elapsed
 * t = normal time elapsed
 * v = velocity
 * c = percentage of the speed of light [0,1]
 * percentC = c / v
 */
double lorentzTimeDilation(double t, double percentC);