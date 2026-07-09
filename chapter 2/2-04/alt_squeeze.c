#include <stdio.h>
/*Exercise 2-4. Write an alternative version of squeeze(s1,s2)
that deletes each character in s1 that matches any character
in the string s2.*/
void squeeze(char s1[],char s2[]);
int main(){
    char s1[] = "abcabc";
    char s2[] = "ac";
    printf("INITIAL:\t%s\n",s1);
    squeeze(s1,s2);
    printf("SQUEEZED:\t%s\n",s1);
    return 0;
}
void squeeze(char s1[], char s2[]){
    int read_i, write_i, z, count;
    read_i = write_i = 0;
    while(s1[read_i]!='\0'){
        z = count =0;
        while(s2[z]!='\0'){
            if (s1[read_i] == s2[z]){
                count = 1;
                break;
            }
            ++z;
        }
        if (count == 0){
            s1[write_i] = s1[read_i];
            ++write_i;
        }
        ++read_i;
    }
    s1[write_i] = '\0';
}
