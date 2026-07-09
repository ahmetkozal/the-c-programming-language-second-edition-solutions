#include <stdio.h>
#include <ctype.h>
/*Exercise 2-3. Write a function htoi(s), which converts a string of 
hexadecimal digits (including an optional 0x or 0X) into 
its equivalent integer value. The allowable digits are 
0 through 9, a through f, and A through F. */
//hexadecimal sayı sistemi 16 tabanlıdır.
int htoi(char s[]);
int main(){
    char s[] = "b2e";
    printf("INPUT: %s\n",s);
    printf("%i\n",htoi(s));
    return 0;
}
int htoi(char s[]){
    int c, i, x;
    x = c = 0;
    for (i = 0; s[i] != '\0';++i){
        c = s[i];
        if (isdigit(c)){
            x = 16 * x + (c - '0');
            //printf("%i\n",x);
        }else{
            if ('A'<=c && c<='F'){
                x = 16 * x + (c - 'A' + 10);
                //printf("%i\n",x);
            }else if('a'<=c && c<='f'){
                x = 16 * x + (c - 'a' + 10);
                //printf("%i\n",x);
            }
        }
    }
    return x;
}