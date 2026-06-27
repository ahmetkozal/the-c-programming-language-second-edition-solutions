#include <stdio.h>
/*Exercise 1-19. Write a function reverse(s) that reverses
the character string s. Use it to write a program that
reverses its input a line at a time. */
#define MAXLINE 1000

int getline(char line[],int maxline);
void reverse_line(char line[], int maxline);

int main(){
	char line[MAXLINE];
	int len, total_len;
	while ((len = getline(line,MAXLINE))>0){
		total_len = len;
		printf("%s",line);
		reverse_line(line,total_len);
		printf("%s",line);
		total_len = 0;
	}
	
}
int getline(char s[], int limit){
	int c,i;
	for (i = 0; (c=getchar())!=EOF && c!= '\n';++i){
		s[i] = c;
	}
	if (c == '\n'){
		s[i] = '\n';
		++i;
	}
	s[i] = '\0';
	return i;
}

void reverse_line(char line[], int limit){
	int i,current;
	int z = limit - 2; //to count from last to 0, exclude \n
	for(i = 0; i<z ;++i){
		current = line[i];
		line[i] = line[z];
		line[z] = current;
		--z;
	}
}