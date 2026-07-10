#include <stdio.h>
/*Exercise 2-7. Write a function invert(x,p,n)
that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0
and vice versa), leaving the others unchanged.*/
unsigned int invert(unsigned int x, int p, int n);
void bit_printer(unsigned int x);
int main(){
    unsigned int x = 53;
    int p = 4;
    int n = 3;
    
    invert(x,p,n);
    return 0;
}
unsigned int invert(unsigned int x, int p, int n){
    printf("INITIAL X: \t");
    bit_printer(x);
    
    //gerekli yer icin maske
    unsigned int mask = (((1U << n) - 1U) << (p - n + 1U));
    printf("MASK: \t\t");
    bit_printer(mask);  
    
    x = x ^ mask;
    printf("FINAL X: \t");
    bit_printer(x);
    
    return x;
}
void bit_printer(unsigned int x){
    int i;
    for (i = 31; i>=0; --i){
        if (x & (1U << i)){
            printf("1");
        }else{
            printf("0");
        }
    }
    printf(" | %u\n",x);
}