#include <stdio.h>
/*Exercise 2-5. Write the function any(s1,s2), which returns the first location in a 
string s1 where any character from the string s2 occurs, or -1 if s1 contains no 
characters from s2. (The standard library function strpbrk does the same job but 
returns a pointer to the location.) */
#define MAXLINE 1000
int found_index(char s1[], char s2[]);
int get_text(char s[], int limit);
int main(){
    int limit = MAXLINE;
    char s1[MAXLINE];
    char s2[MAXLINE];
    printf("First string: ");
    get_text(s1,limit);
    printf("Second string: ");
    get_text(s2,limit);
    printf("%d\n",found_index(s1,s2));
    return 0;
}
int found_index(char s1[], char s2[]){
    int c, i;
    i = 0;
    while(s1[i]!='\0'){
        int z = 0;
        while(s2[z]!='\0'){
            if (s1[i] == s2[z])
                return i;
            ++z;
        }
        ++i;
    }
    return -1;
}
int get_text(char s[], int limit){
    int c, i;
    i = 0;
    while((c=getchar())!=EOF && c!='\n' && i < limit-1)
        s[i++] = c
        ;
    s[i] = '\0';
    return i;
}