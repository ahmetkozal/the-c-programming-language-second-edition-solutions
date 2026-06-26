#include <stdio.h>

#define MAXLINE 1000
#define MINLINE 80

/*Exercise 1-17. Write a program to printall input
lines that are longer than 80 characters.*/

int getline(char line[],int maxline);
void copy(char from[], char to[]);

int main(){
	int c,total_ren,len;
	total_ren = 0;
	
	char line[MAXLINE];
	
	
	while ((len = getline(line,MAXLINE)) > 0){
		total_ren += len;
		if (line[len-1] != '\n'){
			continue;
		}
		else{
			if (total_ren > 80){
				printf("%d: %s",total_ren, line);
			}
		}
		total_ren = 0;
	}
}
int getline(char s[],int limit){
	int c,i;
	for (i = 0; i<limit-1 && (c=getchar())!=EOF && c!='\n';++i){
		s[i] = c;
	}
	if (c == '\n'){
		s[i] = '\n';
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char from[], char to[]){
	int i;
	i = 0;
	while(from[i] = to[i] != '\0'){
		++i;
	}
}