#include <stdio.h>
/*Exercise 1-20. Write a program detab that replaces tabs in the input
with the proper number of blanks to space to the next tab stop. Assume
a fixed set of tab stops, say every n columns. Should n be a variable
or a symbolic parameter? */
/*
|0 |-|1 |-|2 |-|3 |-|4 |-|5 |-|6 |-|7 |   8
|\t|-|  |-|  |-|  |-|  |-|  |-|  |-|  |-|X | tab = 8 ' '
|8 |-|9 |-|10|-|11|-|12|-|13|-|14|-|15|  16
|\t|-|  |-|  |-|  |-|  |-|  |-|  |-|  |-|X | tab = 8 ' '
*/
#define MAXLINE 1000
int n;

void entab(char line[]);
int getlinelen(char line[],int limit);

int main(){
	n=8;
	char line[MAXLINE];
	int c,total_len,len;
	while((c=getlinelen(line,MAXLINE))>0){
		//printf("%s",line);
		entab(line);
		//printf("%s",line);
	}
	return 0;
}
void entab(char line[]){
	int i = 0;
	printf("O:");
	while(line[i]!='\0'){
		if (line[i] == '\t'){
			while(n>0){
				printf(" ");
				--n;
			}
			n = 8;
		}
		else{
			printf("%c",line[i]);
			--n;
		}
		
		if (n < 0){
			n = 8;
		}
		++i;
	}
}

int getlinelen(char line[],int limit){
	int c,i;
	i = 0;
	while (i<limit -1 && (c=getchar())!=EOF && c!='\n'){
		
		line[i] = c;
		++i;
	}
	if (c=='\n'){
		line[i] = '\n';
		++i;
		n = 8;
	}
	line[i] = '\0';
	return i;
}