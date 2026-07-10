#include <stdio.h>
/*Exercise 2-6. Write a function setbits(x,p,n,y) that returns x 
with the n bits that begin at position p set to the rightmost 
n bits of y, leaving the other bits unchanged. */
unsigned int set_bits(unsigned int x, int p, int n,unsigned int y);
void print_bits(unsigned int x);
int main(){
    unsigned int x,y;
    int p , n;
    x = 63;
    y = 2;
    p = 5;
    n = 3;
    
    set_bits(x,p,n,y);
    return 0;
}
unsigned int set_bits(unsigned int x, int p,int n,unsigned int y){
    printf("INITIAL X: \t");
    print_bits(x);
    
    printf("INITIAL Y: \t");
    print_bits(y);
    
    // 000001 --> 000001 << n=2 --> 000100 --> 000100 - 1 -->>
    // 000011 << p=3 --> 001100 ~ 001100 --> !!110011!!
    
    printf("p = %i | n = %i\n",p,n);
    int del_from_x = ~(((1U << n) - 1U) << (p - n + 1U));
    printf("DEL FROM X: \t");
    print_bits(del_from_x);
    
    int mask = (1U << n) - 1U; // 00<-100... | -1 00<-111...
    printf("MASK FOR Y: \t");
    print_bits(mask);
    
    int to_x_from_y = (y & mask) << (p - n + 1U);
    printf("TO X FROM Y: \t");
    print_bits(to_x_from_y);
    
    x = x & del_from_x;
    printf("PRE FINAL X: \t");
    print_bits(x);
    
    x = to_x_from_y | x;
    printf("FINAL X: \t");
    print_bits(x);
    
    return x;
}
void print_bits(unsigned int x){
    int i;
    for (i = 31; i>=0;--i){
        if(x & (1U << i))
            printf("1");
        else
            printf("0");
    }
    printf(" | %u\n",x);
}