#include <stdio.h>
/*Exercise 1-24. Write a program to check a C program
for rudimentary syntax errors like unmatched parentheses
and braces. Don't forget about quotes, both single and 
double, escape sequences, and comments. (This program is hard
if you do it in full generality.)*/
/*() {} [] "" ''*/
#define MAXLINE 1000

#define IN = 1
#define OUT = 0

int get_text(char s[], int limit);

void create_symbol_arr(char s[],char symbols[]);

int main(){
	char s[MAXLINE];
	char symbols[MAXLINE];
	get_text(s,MAXLINE);
	printf("I:%s\n",s);
	create_symbol_arr(s,symbols);
	printf("O:%s",symbols);
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

void create_symbol_arr(char s[], char symbols[])
{
	char symbol_list[] = {"\n(){}[]\"\'\0"};
	int i, z;
	i = z = 0;
	while(s[i]!='\0')
	{
		for (int j = 0;symbol_list[j]!='\0';++j)
		{
			if (s[i] == symbol_list[j]){
				symbols[z] = s[i];
				++z;
				
				break;
			}
		}
		++i;
	}
	symbols[z] = '\0';
}