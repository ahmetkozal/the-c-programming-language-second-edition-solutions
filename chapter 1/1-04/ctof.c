#include <stdio.h>
/*Exercise 1-5. Modify the temperature conversion program to print the table in reverse order,
that is, from 300 degrees to 0. */
int main(){
    float fahr,celsius;
    float lower, upper, step;

    lower = -20;
    upper = 150;
    step = 10;

    celsius = lower;

    printf("C       F\n");
    while (celsius<=upper){
        fahr = (celsius/1.8) + 32.0;
        printf("%3.0f %6.1f\n", celsius,fahr);
        celsius = celsius+step;
    }
}