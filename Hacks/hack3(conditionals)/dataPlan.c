/**
 * Authors: Matt Schlatter and Jack Baldwin
 *
 * Date: 2022/09/08
 *
 * Program used to calculate GBs remaining of a call phone plan for users
 *
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

double totalGb = atof(argv[1]);
int daysIntoPeriod = atoi(argv[2]);
double gbUsed = atof(argv[3]);

if(totalGb <= 0) {
    printf("ERROR: total gigabytes must be positive and non-zero\n");
    exit(1);
}

if((daysIntoPeriod < 1) || (daysIntoPeriod > 30)) {
    printf("ERROR: current day in period must be between 1 and 30\n");
    exit(1);
}

if(gbUsed < 0) {
    printf("ERROR: gigabytes used must be positive\n");
    exit(1);
}

printf("%d days used, %d days remaining\n", daysIntoPeriod, 30 - daysIntoPeriod);
printf("Average daily use: %.2f GB/day\n\n", gbUsed / daysIntoPeriod);

if((gbUsed / daysIntoPeriod) > (totalGb / 30)) {
    if(gbUsed > totalGb) {
        printf("You have already met your limit for this month.  Looks like you're gettin some overage charges...\n");
        exit(0);
    }
    printf("You are EXCEEDING your average daily use (%.2f GB/day)\n", totalGb / 30);
    printf("Continuing this high usage, you'll exceed your data plan by %.2f GB.\n", (((gbUsed / daysIntoPeriod) * 30) - totalGb));
    printf("To stay below your data plan, use no more than %.2f GB/day.\n", (totalGb - gbUsed) / (30 - daysIntoPeriod));
} else if((gbUsed / daysIntoPeriod) == (totalGb / 30)) {
    printf("You are ON TRACK WITH your average daily use (%.2f GB/day)\n", totalGb / 30);
    printf("Continuing this usage, you will not exceed your data plan.\n");
} else if((gbUsed / daysIntoPeriod) < (totalGb / 30)) {
    printf("You are BELOW your average daily use (%.2f GB/day).\n", totalGb / 30);
    printf("To stay below your data plan, you can use no more than %.2f GB/day.\n", (totalGb - gbUsed) / (30 - daysIntoPeriod));
}

    return 0;
}