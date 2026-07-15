#include <stdio.h>
/*Exercise 3-3. Write a function expand(s1,s2) that expands shorthand
notations like a-z in the string s1 into the equivalent complete list
abc...xyz in s2. Allow for letters of either case and digits, and be
prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
that a leading or trailing - is taken literally.*/
/*
-s1'i tara
-karakter - oldugunda ilk ve son karakter degilse
-onceki karakterini ve sonraki karakterini al
-for (onceki-sonraki) listeye ekle
*/
#define MAXLINE 1000
void expand(char s1[], char s2[]);
int main(){
    char s1[] = "f-z";

    
    char s2[MAXLINE];
    
    expand(s1,s2);
    printf("I:%s\n",s1);
    printf("O:%s\n",s2);
    
    return 0;
}
void expand(char s1[], char s2[]){
    int i, j, c;
    i = j = 0;
    while (s1[i] != '\0'){
        if ((s1[i+1] == '-' && s1[i+2]!='\0' && s1[i]<=s1[i+2]) &&
        ((s1[i] >= 'a' && s1[i+2] <= 'z') || (s1[i] >= 'A' && s1[i+2] <= 'Z')||(s1[i] >= '0' && s1[i+2] <= '9'))){
            for(c = s1[i];c<=s1[i+2];c++)
                s2[j++] = c;
            i+=3;
        }else{
            s2[j++] = s1[i++];
        }
    }
    s2[j] = '\0';
}