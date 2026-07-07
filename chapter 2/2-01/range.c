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
    printf("SIGNED:%d -> %d\n",CHAR_MIN, CHAR_MAX);
    printf("UNSIGNED:%d -> %d\n\n",0, UCHAR_MAX);

    printf("SIGNED:%d -> %d\n",SHRT_MIN, SHRT_MAX);
    printf("UNSIGNED:%d -> %d\n\n",0, USHRT_MAX);

    printf("SIGNED:%d -> %d\n",INT_MIN, INT_MAX);
    printf("UNSIGNED:%d -> %d\n",0, UINT_MAX);

    printf("SIGNED:%ld -> %ld\n",LONG_MIN, LONG_MAX);
    printf("UNSIGNED:%d -> %ld\n",0, ULONG_MAX);
    return 0;
}
