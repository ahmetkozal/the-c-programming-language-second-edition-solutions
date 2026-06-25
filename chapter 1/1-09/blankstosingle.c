#include <stdio.h>
/*Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank. */
int main()
{
    int c,bl,tb;
    bl = tb = 0;
    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\t'){
            c = ' ';
            ++bl;
            if (bl==1){
            putchar(c);
            }
        }
        else{
            bl = tb = 0;
            putchar(c);
        }

    }
}
