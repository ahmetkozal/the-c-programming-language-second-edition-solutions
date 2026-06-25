#include <stdio.h>
/*Exercise 1-12. Write a program that prints its input one word per line. */
int main(){
    int c,bl;
    bl = 0;
    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\t'){
            ++bl;
            if(bl==1){
                printf("\n");
            }
        }
        else{
            bl = 0;
            putchar(c);
        }
    }
}
