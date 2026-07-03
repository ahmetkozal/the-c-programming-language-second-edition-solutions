#include <stdio.h>
/*Exercise 1-24. Write a program to check a C program
for rudimentary syntax errors like unmatched parentheses
and braces. Don't forget about quotes, both single and 
double, escape sequences, and comments. (This program is hard
if you do it in full generality.)*/
/*( { [ " '*/
#define MAXLINE 1000
#define IN 1
#define OUT 0

int get_text(char s[], int limit);

void check_for_errors(char s[]);

int main(){
	char s[MAXLINE];
	get_text(s,MAXLINE);
	printf("I:%s",s);
	check_for_errors(s);
	return 0;
}

int get_text(char s[], int limit)
{
	int c,i;
	i=0;
	while (i<limit-1 && (c=getchar())!=EOF)
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void check_for_errors(char s[])
{
	int i = 0;
	while(s[i]!='\0')
	{
		
	}
}