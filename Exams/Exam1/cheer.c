/**
 * Author: Matt Schlatter
 * Date: 2022/09/23
 *
 * program that outputs integers 1 through n but
 * if the current integer is divisible by a, "Go Huskers!"
 * is output instead and if the current integer is divisible
 * by b, "Go Mavs!" is output instead.
 *
 * if the integer is divisible by both a and b, "Go Nebraska!"
 * is output
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    if(argc != 4) {
        printf("ERROR: please enter three values\n");
        exit(0);
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int n = atoi(argv[3]);

    int i = 1;
    while(i <= n) {
        if(i % (a * b) == 0) {
            printf("Go Nebraska!\n");
        } else if(i % a == 0) {
            printf("Go Huskers!\n");
        } else if(i % b == 0) {
            printf("Go Mavs!\n");
        } else {
            printf("%d\n", i);
        }
        i++;
    }
    return 0;
}
