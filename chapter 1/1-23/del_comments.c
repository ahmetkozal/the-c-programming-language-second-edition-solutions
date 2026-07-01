#include <stdio.h>

#define MAXLINE 1000

#define IN 1
#define OUT 0

/*Exercise 1-23. Write a program to remove all
comments from a C program.
Don't forget to handle quoted strings and
character constants properly. C comments
do not nest.*/

int getinput(char s[], int limit);
void del_comments(char from[], char to[]);

int state;

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
    int i_index, z_index;
    i_index = z_index = 0;

    state = IN;

    while (state == IN && from[i_index]!=EOF){
        //Eger c = / ve sonraki de esite *
        if (from[i_index] == '/' && from[i_index+1] == '*'){
            //i_index 2 atla. Cunku / ve * yazdirilmayacak.
            state = OUT;
            ++i_index;
            ++i_index;
            // state OUT ken IN olana kadar donsun
            while (state == OUT){
                if(from[i_index] == '*' && from[i_index+1] == '/'){
                    state = IN;
                    ++i_index;
                }else{
                    ++i_index;
                }
            }
        }else{
            to[z_index] = from[i_index];
            ++i_index;
            ++z_index;
            to[z_index] = '\0';
        }
    }

}
