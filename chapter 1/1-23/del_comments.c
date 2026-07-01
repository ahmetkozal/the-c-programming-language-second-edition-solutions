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
	int i_index,z_index;
	i_index = z_index = 0;
	state = IN;
	while(from[i_index]!=EOF){
		if (state == IN){
			if (from[i_index] == 'o' && from[i_index+1] == '*'){
				state = OUT;
				++i_index;
				while (state == OUT){
					if (from[i_index] == '*' && from[i_index+1] == 'i'){
						state = IN;
						++i_index;
					}
					++i_index;
				
					
				}
			}
			to[z_index] = from[i_index];
			++z_index;
			++i_index;
	}
	}
}
