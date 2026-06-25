#include <stdio.h>
/*Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.*/
int main(){
    int c, len, max;
    int words[20];
    len = max = 0;
    for (int i = 0; i < 20;++i){
        words[i] = 0;
    }
    while ((c = getchar()) != EOF){

        if (c!=' ' && c!= '\t' && c!= '\n'){
            ++len;
        }
        else{
            ++words[len];

            len = 0;
        }
    }
    for(int i =0;i<20;++i){
        if (words[i]>max){
            max = words[i];
        }
    }
    for (int i = max; i > 0;--i){
        for (int z = 0; z<20;++z){
            if (words[z] >= i){
                printf("| * |");
            }
            else{
                printf("|   |");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < 20;++i){
        if (i<10){
            printf("| %d |",i);
        }
        else{
            printf("| %d|",i);
        }
    }
}
