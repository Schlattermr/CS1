/**
 * Author: Matt Schlatter
 *
 * This program prompts users for a USD value
 * and converts the given value to British Pounds
 * (GBP) and Japanese (JPY) with the exchange rate
 * 1 USD = 0.79 GBP and 1 USD = 127.65 JPY and a
 * 10% USD exchange fee
 *
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

    double usDollars, britishPounds, japanese, exchangeFee;

    printf("Please input the total number of US Dollars: ");
    scanf("%lf", &usDollars);

    exchangeFee = usDollars * 0.1;
    usDollars = usDollars - exchangeFee;

    printf("\nFee (10%%): $%.2f\n", exchangeFee);

    printf("You get: \n");

    britishPounds = (usDollars / 2) * 0.79;
    japanese = (usDollars / 2) * 127.65;

    printf("%.2f GBP\n", britishPounds);
    printf("%.0f JPY\n", japanese);

    return 0;
}
