#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "airport.h"

int main(int argc, char **argv) {

    Airport *dia = createAirport("gpsId1", "big", "DIA", 39.856100, -104.673700, 5430, "Denver", "US");
    Airport *lax = createAirport("gpsId2", "big", "LAX", 33.941600, -118.408500, 128, "Los Angeles", "US");
    Airport *cpt = createAirport("gpsId3", "big", "CPT", -33.971500, 18.602100, 151, "Cape Town", "ZAF");
    Airport *jfk = createAirport("gpsId4", "big", "JFK", 40.641300, -73.778100, 13, "New York", "US");
    Airport *inc = createAirport("gpsId5", "big", "INC", 38.322600, 106.388600, 3743, "Yichuan", "CN");

    printAirport(dia);
    printAirport(lax);
    printAirport(cpt);
    printAirport(jfk);
    printAirport(inc);

    return 0;
}