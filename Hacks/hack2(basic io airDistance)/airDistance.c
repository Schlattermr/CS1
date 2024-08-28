/**
 * Authors: Matt Schlatter and Jack Baldwin
 *
 * Date: 2022/09/01
 *
 * Program that computes the distance between the
 * latitude and longitude of two locations
 *
 * latitude inputs will be in degrees and in the range [−90, 90]
 * longitude will be in degrees in the range [−180, 180]
 *
 * Original test Cases - Origin - (-45.000000, 45.000000), Destination - (-30.000000, 30.000000), airDistance = 2121.664172
 *                       Origin - (-40.000000, -40.000000), Destination - (40.000000, 40.000000), airDistance = 12024.183857
 *                       Origin - (89.000000, 100.000000), Destination - (-89.000000, -100.000000), airDistance = 19976.471105
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

    double latitudeADeg, longitudeADeg, latitudeBDeg, longitudeBDeg, longitudeChange, airDistance;
    const int earthRadius = 6371;

    printf("Enter the origin latitude: ");
    scanf("%lf", &latitudeADeg);
    if((latitudeADeg < -90) || (latitudeADeg > 90)) {
        printf("ERROR: Must enter value between -90 and 90\n");
        exit(1);
    }

    printf("\nEnter the origin longitude: ");
    scanf("%lf", &longitudeADeg);
    if((longitudeADeg < -180) || (longitudeADeg > 180)) {
        printf("ERROR: Must enter value between -180 and 180\n");
        exit(1);
    }

    printf("\nEnter the destination latitude: ");
    scanf("%lf", &latitudeBDeg);
    if((latitudeBDeg < -90) || (latitudeBDeg > 90)) {
        printf("ERROR: Must enter value between -90 and 90\n");
        exit(1);
    }

    printf("\nEnter the destination longitude: ");
    scanf("%lf", &longitudeBDeg);
    if((longitudeBDeg < -180) || (longitudeBDeg > 180)) {
        printf("ERROR: Must enter value between -180 and 180\n");
        exit(1);
    }

    double latitudeARad, longitudeARad, latitudeBRad, longitudeBRad;

    //converts degrees to radians for all inputs
    latitudeARad = (latitudeADeg / 180) * M_PI;
    longitudeARad = (longitudeADeg / 180) * M_PI;
    latitudeBRad = (latitudeBDeg / 180) * M_PI;
    longitudeBRad = (longitudeBDeg / 180) * M_PI;

    longitudeChange = longitudeBRad - longitudeARad;

    //equation used to calculate kilometers traveled in air from latitudes and longitudes
    airDistance = (acos((sin(latitudeARad) * sin(latitudeBRad)) + (cos(latitudeARad) * cos(latitudeBRad) * cos(longitudeChange)))) * earthRadius;

    printf("\nLocation Distance\n");
    printf("========================\n");
    printf("Origin:      (%f, %f)\n", latitudeADeg, longitudeADeg);
    printf("Destination: (%f, %f)\n", latitudeBDeg, longitudeBDeg);
    printf("Air distance is %f kms\n", airDistance);

    return 0;
}