#include <stdio.h>
#include <string.h>
/*Exercise 4-1. Write the function strindex(s,t) which returns
the position of the rightmost occurrence of t in s, or -1 if
there is none. */
#define MAXLINE 1000
int strindex(char s[], char t[]);
int main() {
    char s[] = "This is the test st yeah";
    char t[] = "est";
    printf("%i\n",strindex(s,t));
    return 0;
}

int strindex(char s[], char t[]) {
    int i,j,k,len_s,len_t;
    len_s = strlen(s);
    len_t = strlen(t);
    
    for (i = len_s-1;i>=len_t-1;--i){
        for (j=i, k=len_t-1;k>=0 && s[j]==t[k] ;--k,--j)
            ;
        if (k == -1)
            return i - len_t +1;
    }
    return -1;
}
