#include <stdio.h>
/*Exercise 1-14. Write a program to print a histogram of the frequencies of different characters
in its input.*/
int main(){
    int c, n;
    n = 256;
    c = 0;
    int freq[n];
    for (int i = 0; i<n;++i){
        freq[i] = 0;
    }
    while((c = getchar()) != EOF){
            if (c!=' '&&c!='\t'&&c!='\n'){
                ++freq[c];
            }
    }
    for (int i=33;i<n;++i){
        printf("%c: ",i); //karakter
        for (int z = 0; z<freq[i]; ++z){//freq[i] kac tane oldugunu almak icin
            printf("*");
        }
        printf("\n");
    }
}