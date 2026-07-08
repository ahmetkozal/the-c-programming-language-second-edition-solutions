#include <stdio.h>
/*Exercise 2-4. Write an alternative version of squeeze(s1,s2)
that deletes each character in s1 that matches any character
in the string s2.*/
#define MAXLINE 1000

void squeeze(char s1[],char s2[]);
int main(){
    char s1[] = "ilk dizi";
    char s2[] = "iz";
    printf("INITIAL:\t%s\n",s1);
    squeeze(s1,s2);
    printf("SQUEEZED:\t%s\n",s1);
    return 0;
}
void squeeze(char s1[], char s2[]){
    int s1_i,s2_i;
    s1_i = 0;
    while (s1[s1_i]!='\0'){
        int count;
        s2_i = count = 0;
        while (s2[s2_i]!='\0'){
            if (s1[s1_i] == s2[s2_i]){
                ++count;
                break;
            }
            ++s2_i;
        }
        if (count == 0){
            s1[s1_i] = s1[s1_i];
            ++s1_i;
        }else{
            s1[s1_i] = s1[s1_i+1];
            ++s1_i;
        }
    }
    s1[s1_i] = '\0';
}
