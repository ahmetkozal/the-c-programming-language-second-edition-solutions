#include <stdio.h>
/*Exercise 2-6. Write a function setbits(x,p,n,y) that returns x 
with the n bits that begin at position p set to the rightmost 
n bits of y, leaving the other bits unchanged. */
int set_bits(int x, int p, int n, int y);
int main(){
    
    return 0;
}
int set_bits(int x, int p,int n, int y){

    
    int mask = (1 << n) - 1; // 00<-100... | -1 00<-111...
    int to_x_from_y = y & mask;
	int to_x = p - to_x_from_y;
    
    return x;
}