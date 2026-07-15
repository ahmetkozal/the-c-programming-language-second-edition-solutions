#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXLINE 1000
/*Exercise 3-5. Write the function itob(n,s,b) that converts the 
integer n into a base b character representation in the string 
s. In particular, itob(n,s,16) formats s as a hexadecimal 
integer in s. */
void itob(int n, char s[], int b);
void reverse(char s[]);
int main(){
    char s[MAXLINE];
    itob(123, s, 10);
    printf("123: %s\n", s);
    itob(123, s, 16);
    printf("123: %s\n", s);
    itob(123, s, 2);
    printf("123: %s\n", s);

    itob(-123, s, 10);
    printf("-123: %s\n", s);
    itob(-123, s, 16);
    printf("-123: %s\n", s);
    itob(-123, s, 2);
    printf("-123: %s\n", s);

    itob(INT_MIN, s, 10);
    printf("INT_MIN: %s\n", s);
    itob(INT_MIN, s, 16);
    printf("INT_MIN: %s\n", s);
    itob(INT_MIN, s, 2);
    printf("INT_MIN: %s\n", s);

    itob(INT_MAX, s, 10);
    printf("INT_MAX: %s\n", s);
    itob(INT_MAX, s, 16);
    printf("INT_MAX: %s\n", s);
    itob(INT_MAX, s, 2);
    printf("INT_MAX: %s\n", s);
    
    return 0;
}

void itob(int n, char s[], int b){
    char digits[] = "0123456789ABCDEF";
    int i, sign, digit;
    long long long_n;
    if (b<2 || b >16){
        s[0] = '\0';
        return;
    }
    else{
        long_n = ((sign=n) < 0) ? -((long long)n) : (long long)n;
        i = 0;
        do {
            digit = long_n % b;
            s[i++] = digits[digit];
        } while ((long_n /= b) > 0);   
        if (sign < 0)
            s[i++] = '-';
        s[i] = '\0';
        reverse(s);
    }
}
void reverse(char s[]){
    int c, i, j;
    
    for (i = 0, j = strlen(s)-1;i<j;i++,j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}