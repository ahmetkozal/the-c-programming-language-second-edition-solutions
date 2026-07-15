#include <stdio.h>
#include <string.h>
/*Exercise 4-1. Write the function strindex(s,t) which returns
the position of the rightmost occurrence of t in s, or -1 if
there is none. */
#define MAXLINE 1000
int strindex(char s[], int t);
int main() {
    char s[] = "This is the test input";
    printf("%i\n",strindex(s,'u'));
    return 0;
}

int strindex(char s[], int t) {
    int i;
    for (i = strlen(s) - 1; i >= 0; --i) {
        if (s[i] == t)
            return i;
    }
    return -1;
}
