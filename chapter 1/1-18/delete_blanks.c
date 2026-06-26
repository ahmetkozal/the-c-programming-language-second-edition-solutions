#include <stdio.h>
/*Exercise 1-18. Write a program to remove trailing blanks and tabs
from each line of input, and to delete entirely blank lines. */
#define MAXLINE 1000


void delete_bl(char line[], char new_line[]);

int main(){
	int c;
	while((c=getchar())!=EOF){
		
	}
}

void delete_bl(char line[], char new_line[]){
	int i = 0;
	while((line[i] = new_line[i]) != '\0' && (line[i] = new_line[i]) != ' '){
		++i;
	}
}