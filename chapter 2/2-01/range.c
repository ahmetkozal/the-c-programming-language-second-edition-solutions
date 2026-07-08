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
// 1 byte -> 8 bit.
// binary number system is 2 based.
int m_power(int base, int up);

int main(){
    printf("NOT COMPUTED:\n");
    
    printf("SIGNED CHAR:\t%d -> %d\n",CHAR_MIN, CHAR_MAX);
    printf("UNSIGNED CHAR:\t%d -> %d\n",0, UCHAR_MAX);
    printf("\n");
    printf("SIGNED SHORT:\t%d -> %d\n",SHRT_MIN, SHRT_MAX);
    printf("UNSIGNED SHORT:\t%d -> %d\n",0, USHRT_MAX);
    printf("\n");
    printf("SIGNED INT:\t%d -> %d\n",INT_MIN, INT_MAX);
    printf("UNSIGNED INT:\t%d -> %u\n",0, UINT_MAX);
    printf("\n");
    printf("SIGNED LONG:\t%ld -> %ld\n",LONG_MIN, LONG_MAX);
    printf("UNSIGNED LONG:\t%d -> %lu\n",0, ULONG_MAX);
    printf("\n");
    int size_char   = sizeof(char);
    printf("SIZE OF CHAR:\t%d\n",size_char);
    int size_short  = sizeof(short);
    printf("SIZE OF SHORT:\t%d\n",size_short);
    int size_int    = sizeof(int);
    printf("SIZE OF INT:\t%d\n",size_int);
    int size_long   = sizeof(long);
    printf("SIZE OF LONG:\t%d\n",size_long);
    printf("\n");
    printf("COMPUTED:\n");
    printf("SIGNDED CHAR:\t%d -> %d\n",m_power(-2,(size_char*8)-1),m_power(2,(size_char*8)-1)-1);
    printf("UNSIGNDED CHAR:\t%d -> %d\n", 0, m_power(2,(size_char*8))-1);
    printf("\n");
    printf("SIGNDED SHORT:\t%d -> %d\n",m_power(-2,(size_short*8)-1),m_power(2,(size_short*8)-1)-1);
    printf("UNSIGNDED SHORT:\t%d -> %d\n", 0, m_power(2,(size_short*8))-1);
    printf("\n");
    printf("SIGNDED INT:\t%d -> %d\n",m_power(-2,(size_int*8)-1),m_power(2,(size_int*8)-1)-1);
    printf("UNSIGNDED INT:\t%d -> %u\n", 0, m_power(2,(size_int*8))-1);
    printf("\n");
    printf("SIGNDED LONG:\t%ld -> %ld\n",m_power(-2,(size_long*8)-1),m_power(2,(size_long*8)-1)-1);
    printf("UNSIGNDED LONG:\t%d -> %lu\n", 0, m_power(2,(size_long*8))-1);
    
    printf("\n");
    return 0;
}

int m_power(int base, int up){
    int i = 0;
    int x = base;
    while (i<up-1){
        x = base * x;
        ++i;
    }
    return x;
}