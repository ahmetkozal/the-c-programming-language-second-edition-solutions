#include <stdio.h>
/*Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function
for conversion.*/

float f_to_c(float f);

int main(){
    float fahr,celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    printf("F       C\n");
    while (fahr<=upper){
		printf("%2.0f	%2.0f\n",fahr,f_to_c(fahr));
        fahr = fahr+step;
    }
}
float f_to_c(float f){
	float c;
	c = (5.0/9.0) * (f - 32.0);
	return c;
}