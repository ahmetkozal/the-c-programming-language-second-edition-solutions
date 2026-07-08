#include <stdio.h>
#include <limits.h>
#include <float.h>
/*
Exercise 2-1. Write a program to determine the ranges of
!!! char, short, int, and long !!!
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation.
??? Harder if you com pute them: determine the ranges of the various floating-point types.???
*/
int main(){
    printf("NOT COMPUTED:\n");
    
    printf("SIGNED CHAR:\t%d -> %d\n",CHAR_MIN, CHAR_MAX);
    printf("UNSIGNED CHAR:\t%d -> %d\n\n",0, UCHAR_MAX);

    printf("SIGNED SHORT:\t%d -> %d\n",SHRT_MIN, SHRT_MAX);
    printf("UNSIGNED SHORT:\t%d -> %d\n\n",0, USHRT_MAX);

    printf("SIGNED INT:\t%d -> %d\n",INT_MIN, INT_MAX);
    printf("UNSIGNED INT:\t%d -> %u\n\n",0, UINT_MAX);

    printf("SIGNED LONG:\t%ld -> %ld\n",LONG_MIN, LONG_MAX);
    printf("UNSIGNED LONG:\t%d -> %lu\n\n",0, ULONG_MAX);
    
    return 0;
}
