#include <stdio.h>

int main(){
    int c, bl, nl;
    nl = bl = 0;
    while ((c = getchar()) != EOF)
    {
        if (c != ' ' && c != '\t' && c != '\n')
        {
            putchar(c);
            bl = 0;
        }
        else if (c == ' ' || c == '\t' || c == '\n'){
            if (bl == 0){
                printf("\n");
                ++bl;
            }
        }  
    }
}