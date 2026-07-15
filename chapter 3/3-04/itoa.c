#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXLINE 1000
/*Exercise 3-4. In a two's complement number representation, our version of 
itoa does not handle the largest negative number, that is, the value of n 
equal to -(2 wordsize-1 ). Explain why not. Modify it to print that value 
correctly, regardless of the machine on which it runs.*/
void itoa(int n, char s[]);
void reverse(char s[]);
int main(){
    char s[MAXLINE];
    itoa(123, s);
    printf("123: %s\n", s);
    itoa(-123, s);
    printf("-123: %s\n", s);
    itoa(INT_MIN, s);
    printf("INT_MIN: %s\n", s);
    itoa(INT_MAX, s);
    printf("INT_MAX: %s\n", s);
    return 0;
}

void itoa(int n, char s[]){
    int i, sign;
    long long long_n;
    long_n = ((sign=n) < 0) ? -((long long)n) : (long long)n;
    i = 0;
    do {
        s[i++] = long_n % 10 + '0';
    } while ((long_n /= 10) > 0);   
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
void reverse(char s[]){
    int c, i, j;
    
    for (i = 0, j = strlen(s)-1;i<j;i++,j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}