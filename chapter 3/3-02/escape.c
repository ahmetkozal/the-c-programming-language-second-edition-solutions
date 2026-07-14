#include <stdio.h>
/*Exercise 3-2. Write a function escape(s,t) that converts
characters like newline and tab into visible escape
sequences like \n and \t as it copies the string t to s.
Use a switch. Write a function for the other direction as
well, converting escape sequences into the real characters.*/
#define MAXLINE 1000
void escape(char s[], char t[]);
int main(){
    char s[] = "a\ta\tb\na";
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
            case '\a':
                t[j++] = '\\';
                t[j++] = 'a';
                ++i;
                break;
            case '\b':
                t[j++] = '\\';
                t[j++] = 'b';
                ++i;
                break;
			case '\e':
                t[j++] = '\\';
                t[j++] = 'e';
                ++i;
                break;
			case '\f':
                t[j++] = '\\';
                t[j++] = 'f';
                ++i;
                break;
			case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                ++i;
                break;
			case '\r':
                t[j++] = '\\';
                t[j++] = 'r';
                ++i;
                break;
			case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                ++i;
                break;
			case '\v':
                t[j++] = '\\';
                t[j++] = 'v';
                ++i;
                break;
			case '\\':
                t[j++] = '\\';
                t[j++] = '\\';
                ++i;
                break;
			case '\'':
                t[j++] = '\\';
                t[j++] = '\'';
                ++i;
                break;
			case '\"':
                t[j++] = '\\';
                t[j++] = '\"';
                ++i;
                break;
			case '\?':
                t[j++] = '\\';
                t[j++] = '?';
                ++i;
                break;
			
            default:
                t[j++] = s[i++];
        }
    }
    t[j] = '\0';
}