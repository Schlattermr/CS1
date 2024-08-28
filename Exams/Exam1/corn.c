/**
 * Author: Matt Schlatter
 * Date: 2022/09/23
 *
 * program used to help farmers estimate the weight of corn stored
 * in a cylindrical silo with the equation h x pi x r^2 for the volume
 * of the cylinder then multiplying that by the percent full the silo is.
 *
 * this volume will be multiplied by the estimate of corn weight: 720.83 kg/cm^3
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv) {

    if(argc != 4) {
        printf("ERROR: Enter radius, height, and percentage full on scale 0-1 please\n");
        exit(0);
    }

    double radius = atof(argv[1]);
    double height = atof(argv[2]);
    double percentage = atof(argv[3]);
    const double cornWeight = 720.83;

    if(radius <= 0) {
        printf("ERROR: enter radius above zero\n");
        exit(0);
    }
    if(height <= 0) {
        printf("ERROR: enter height above zero\n");
        exit(0);
    }
    if(percentage < 0 || percentage > 1) {
        printf("ERROR: percentage must be between 0 and 1\n");
        exit(0);
    }

    //calculates total filled volume of corn within the silo
    double totalVolume = height * M_PI * pow(radius, 2) * percentage;
    double totalWeight = totalVolume * cornWeight;

    printf("Radius: %.3fm\n", radius);
    printf("Height: %.3fm\n", height);
    printf("Percentage: %.2f%%\n", percentage * 100);
    printf("\nTotal Volume: %10.3f m^3\n", totalVolume);
    printf("Total Weight: %10.3f kg\n", totalWeight);

    return 0;
}