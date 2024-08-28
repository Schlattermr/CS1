/**
 * Authors: Jack Baldwin and Matt Schlatter
 * Date: 2022/29/09
 *
 * Function definitions to convert degrees to radians,
 * calculate the air distance between two latitudes and
 * longitudes, and calculate the time dilation an object
 * traveling at very fast velocities experiences
 *
 * */
#include <stdlib.h>
#include <math.h>
#include "utils.h"

double degreesToRadians(double degree) {
    double radian = (degree * M_PI) / 180;
    return radian;
}

double getAirDistance(double originLatitude, double originLongitude, double destinationLatitude, double destinationLongitude) {
    originLatitude = degreesToRadians(originLatitude);
    originLongitude = degreesToRadians(originLongitude);
    destinationLatitude = degreesToRadians(destinationLatitude);
    destinationLongitude = degreesToRadians(destinationLongitude);
    const int earthRadius = 6371;

    double airDistance = acos(sin(originLatitude) * sin(destinationLatitude) + cos(originLatitude) * cos(destinationLatitude) * cos(destinationLongitude - originLongitude)) * earthRadius;
    return airDistance;
}

double lorentzTimeDilation(double t, double percentC) {
    double timeDilation = t / (sqrt(1-pow(percentC, 2)));
    return timeDilation;
}