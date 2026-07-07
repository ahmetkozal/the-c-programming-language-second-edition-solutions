#include <stdio.h>
#include <limits.h>
#include <float.h>
/*
Exercise 2-1. Write a program to determine the ranges of
!!! char, short, int, and long !!!
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation.
??? Harder if you compute them: determine the ranges of the various floating-point types.???
*/
int main(){
    printf("%d -> %d\n",CHAR_MIN, CHAR_MAX);
    printf("%u -> %u\n\n",CHAR_MIN, CHAR_MAX);

    printf("%d -> %d\n",SHRT_MIN, SHRT_MAX);
    printf("%u -> %u\n\n",SHRT_MIN, SHRT_MAX);

    printf("%d -> %d\n",INT_MIN, INT_MAX);
    printf("%u -> %u\n",INT_MIN, INT_MAX);

    printf("%ld -> %ld\n",LONG_MIN, LONG_MAX);
    printf("%lu -> %lu\n",LONG_MIN, LONG_MAX);
    return 0;
}
