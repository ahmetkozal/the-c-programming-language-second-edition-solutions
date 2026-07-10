#include <stdio.h>
/*Exercise 2-10. Rewrite the function lower, which
converts upper case letters to lower case, with a
conditional expression instead of if-else. */
void lower(char s[]);
void new_lower(char s[]);
int main(){
    char text[] = "TeST";
    new_lower(text);
    printf("%s\n",text);
    return 0;
}
void new_lower(char s[]){
    for (int i = 0; s[i]!='\0'; ++i)
        s[i] = ('A'<=s[i] && s[i]<='Z') ? s[i] + 'a' - 'A' : s[i];
}
void lower(char s[]){
    for (int i = 0; s[i]!='\0'; ++i){
        if ('A'<=s[i] && s[i]<='Z')
            s[i] = s[i] + 'a' - 'A';
        else
            s[i] = s[i];
    }
}