#include <stdio.h>
/*Exercise 3-2. Write a function escape(s,t) that converts
characters like newline and tab into visible escape
sequences like \n and \t as it copies the string t to s.
Use a switch. Write a function for the other direction as
well, converting escape sequences into the real characters.*/
#define MAXLINE 1000
void escape(char s[], char t[]);
int main(){
    char s[] = "a\ta";
    char t[MAXLINE];
    
    printf("INITAL: %s\n",s);
    escape(s,t);
    printf("FINAL: %s\n",t);
    
    return 0;
}
void escape(char s[], char t[]){
    int i, j, c;
    i = j = 0;
    while (s[i]!='\0'){
        c = s[i];
        switch(c){
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                ++i;
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                ++i;
            default:
                t[j++] = s[i];
        }
        ++i;
    }
    t[j] = '\0';
}