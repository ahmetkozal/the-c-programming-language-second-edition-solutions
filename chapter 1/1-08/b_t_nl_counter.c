#include <stdio.h>
/*Exercise 1-8. Write a program to count blanks, tabs, and newlines.*/
int main()
{
    int c,bl,tb,nl;
    c = bl = tb = nl = 0;
    while((c = getchar())!= EOF){
        if(c == ' '){
            ++bl;
        }
        else if(c == '\t'){
            ++tb;
        }
        else if(c == '\n'){
            ++nl;
        }
    }
    printf("blanks: %d , tabs: %d , nl: %d",bl,tb,nl);
}


