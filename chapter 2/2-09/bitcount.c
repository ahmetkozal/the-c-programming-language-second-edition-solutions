#include <stdio.h>
#include <limits.h>
/*Exercise 2-9. In a two's complement number system,
x &= (x-1) deletes the rightmost 1-bit in x.
Explain why. Use this observation to write a faster
version of bitcount. */
#define SIZE_OF_UNSIGNED_INT (sizeof(unsigned int) * CHAR_BIT)
int bitcount(unsigned x);
int new_bitcount(unsigned x);
void print_bit(unsigned x);

int main(){
    unsigned int x = 67;
    print_bit(x);
    
    printf("OLD:\t%i\n",bitcount(x));
    printf("NEW:\t%i\n",new_bitcount(x));
    
    
    return 0;
}
int new_bitcount(unsigned x){
    int bit = 0;
    while(x!=0){
        x &= (x-1);
        ++bit;
    }
    return bit;
}

int bitcount(unsigned x){
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}
void print_bit(unsigned x){
    for (int i = SIZE_OF_UNSIGNED_INT - 1U;i>=0;--i){
        if(x & (1U << i))
            printf("1");
        else
            printf("0");
    }
    printf(" | %u\n",x);
}