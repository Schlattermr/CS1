/**
 * Authors: Jack Baldwin and Matt Schlatter
 * Date: 2022/15/09
 *
 * Calculates 401k balance from inputs from starting balance, monthly contribution,
 * annual return rate, annual inflation rate, and the number of years until retirement.
 *
 * */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

    double startBalance = atof(argv[1]);
    double monthlyContribute = atof(argv[2]);
    double annualReturnRate = atof(argv[3]);
    double annualInflationRate = atof(argv[4]);
    int yearsTilRetire = atoi(argv[5]);

    if(startBalance < 0) {
        printf("ERROR: Starting Balance must be positive\n");
        exit (0);
    }
    if(monthlyContribute < 0 || monthlyContribute * 12 > 18500) {
        printf("ERROR: monthly contributions exceed $18,500 annual limit\n");
        exit(0);
    }
    if(annualReturnRate < 0 || annualReturnRate > 1) {
        printf("ERROR: Annual Return Rate must be between 0 and 1 please\n");
        exit(0);
    }
     if(annualInflationRate < 0 || annualInflationRate > 1) {
        printf("ERROR: Annual Inflation Rate must be between 0 and 1 please\n");
        exit(0);
    }
     if(yearsTilRetire < 0) {
        printf("ERROR: Years Until Retirement must be positive\n");
        exit (0);
    }

    startBalance = round(startBalance * 100) / 100;
    monthlyContribute =  round(monthlyContribute * 100) / 100;
    int monthsTilRetire = yearsTilRetire * 12;
    //Equation for inflation adjusted rate of return
    double adjustedReturnRate = ((1 + annualReturnRate) / (1 + annualInflationRate)) - 1;
    double adjustedMonthlyRate = adjustedReturnRate / 12;
    double interest = 0;
    double totalInterest = 0;

    printf("Month  Interest  Balance\n");
    int i = 1;
    while(i <= monthsTilRetire) {
        interest = startBalance * adjustedMonthlyRate;
        interest = round(interest * 100) / 100;
        startBalance = startBalance + interest + monthlyContribute;
        startBalance = round(startBalance * 100) / 100;
        printf("%4d $ %6.2f $ %9.2f\n", i, interest, startBalance);
        totalInterest = totalInterest + interest;
        totalInterest = round(totalInterest * 100) / 100;
        i++;
    }

    printf("Total Interest Earned: $ %6.2f\n", totalInterest);
    printf("Total Nest Egg: $ %6.2f\n", startBalance);

    return 0;
}