#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXLINE 1000
/*Exercise 3-6. Write a version of itoa that accepts three arguments 
instead of two. The third argument is a minimum field width; the 
converted number must be padded with blanks on the left if necessary 
to make it wide enough. */
void itoa(int n, char s[],int pad);
void reverse(char s[]);
int main(){
    char s[MAXLINE];
    itoa(123, s,5);
    printf("123:%s\n", s);
    itoa(-123, s,5);
    printf("-123:%s\n", s);
    itoa(INT_MIN, s,30);
    printf("INT_MIN:%s\n", s);
    itoa(INT_MAX, s,30);
    printf("INT_MAX:%s\n", s);
    return 0;
}

void itoa(int n, char s[],int pad){
    int i, sign;
    long long long_n;
    char padded_s[MAXLINE];
    long_n = ((sign=n) < 0) ? -((long long)n) : (long long)n;
    i = 0;
    do {
        s[i++] = long_n % 10 + '0';
    } while ((long_n /= 10) > 0);   
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
    if (pad>strlen(s)){
        int to_put = pad - strlen(s);
        int s_i, with_space_i;
        s_i = strlen(s);
        with_space_i = to_put + s_i;
        while(with_space_i>=0){
            if (s_i>=0)
                s[with_space_i--] = s[s_i];
            else{
                s[with_space_i--] = ' ';
            }
            --s_i;
        }
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