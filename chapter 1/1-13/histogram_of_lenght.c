#include <stdio.h>
/*Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.*/
int main(){
    int c, len;
    int words[20];
    len = 0;
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
    for (int i = 0; i < 20;++i){
        printf("%d: ",i);
        for (int z = 0;z<words[i];z++){
            printf("*");
        }
        printf("\n");
    }
}
