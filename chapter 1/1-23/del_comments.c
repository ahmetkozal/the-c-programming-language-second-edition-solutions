#include <stdio.h>

#define MAXLINE 1000

int getinput(char s[], int limit);
void del_comments(char from[], char to[]);
int main(){
    char s[MAXLINE];
    char new_s[MAXLINE];
    int i, c;
    getinput(s,MAXLINE);
    del_comments(s,new_s);
    printf("%s",new_s);


    return 0;
}

int getinput(char s[], int limit){
    int c,i;
    i = 0;
    while((c=getchar())!=EOF && i < limit - 1){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
void del_comments(char from[], char to[]){
    int i = 0;
    while(from[i] != '\0'){
        to[i] = from[i];
        ++i;
    }
    to[i] = '\0';
}
