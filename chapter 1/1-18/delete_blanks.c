#include <stdio.h>
/*Exercise 1-18. Write a program to remove trailing blanks and tabs
from each line of input, and to delete entirely blank lines. */
#define MAXLINE 1000

#define IN 1
#define OUT 0

void delete_bl(char line[], int len);
int getline(char line[],int maxline);
int main(){
	int total_len,len;
	char line[MAXLINE];
	while ((len = getline(line,MAXLINE))>0){
		total_len = len;

		printf("|%s|\n",line);
		delete_bl(line,total_len);
		printf("|%s|\n",line);
		
		total_len = 0;
	}
}

int getline(char s[], int limit){
	int c,i;
	for (i = 0; i<limit-1 && (c=getchar())!=EOF && c!='\n';++i){
	s[i] = c;
	}
	s[i] = '\0';
	return i;
}


void delete_bl(char line[], int len){
	int i = len -1;
	while(line[i]==' ' || line[i]=='\t'){
		line[i] = '\0';
		--i;
	}
}