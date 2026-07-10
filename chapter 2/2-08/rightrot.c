#include <stdio.h>
#include <limits.h>
/*Exercise 2-8. Write a function rightrot(x,n) that returns 
the value of the integer x rotated to the right by n positions. */
#define SIZE_OF_UNSIGNED_INT (sizeof(unsigned int) * CHAR_BIT)
unsigned int rightrot(unsigned int x, int n);
void print_bits(unsigned int x);
int main(){
    unsigned int x = 78;
    int n = 4;
    rightrot(x,n);
    
    return 0;
}
unsigned int rightrot(unsigned int x, int n){
    n %= SIZE_OF_UNSIGNED_INT; //eger n>x olursa da calissin diye
    
    if (n > 0){
        printf("INIT X:\t");
        print_bits(x);
        
        unsigned int mask = ((1U << n) - 1U);
        printf("MASK:\t");
        print_bits(mask);
        
        unsigned int to_copy = (x & mask) << (SIZE_OF_UNSIGNED_INT - n);
        printf("COPIED:\t");
        print_bits(to_copy);
        
        x = (x >> n);
        x = x | to_copy;
        printf("FIN X:\t");
        print_bits(x);
        return x;
    }else{
        return x;   
    }
}
void print_bits(unsigned int x){
    for (int i = SIZE_OF_UNSIGNED_INT -1U ; i>=0; -- i){
        if (x & (1U << i)){
            printf("1");
        }else{
            printf("0");
        }
    }
    printf(" | %u\n",x);
}