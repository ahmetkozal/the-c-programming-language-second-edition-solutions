#include <stdio.h>

#define MAXLINE 100

#define IN 1
#define OUT 0

/*Exercise 1-23. Write a program to remove all
comments from a C program.
Don't forget to handle quoted strings and
character constants properly. C comments
do not nest.*/

int state;
int str;

int get_input(char s[],int limit);
void del_comments(char from[],char to[]);

int main()
{
	char s[MAXLINE];
	int len = get_input(s,MAXLINE);
	printf("I:%s",s);
	char new_s[len];
	del_comments(s,new_s);
	printf("O:%s",new_s);
}

int get_input(char s[],int limit)
{
	int c, i;
	i = 0;
	while(i<limit - 1 && (c=getchar())!=EOF)
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void del_comments(char from[], char to[])
{
	state = IN;
	str = OUT;
	int i_index, z_index;
	i_index = z_index = 0;
	while(from[i_index]!='\0')
	{
		if (from[i_index] == '"' && str == OUT && state == IN)
		{
			to[z_index] = from[i_index];
			++z_index;
			str = IN;
			++i_index;
		}
		else if (from[i_index] == '"' && str == IN)
		{
			to[z_index] = from[i_index];
			++z_index;
			str = OUT;
			++i_index;
		}
		if (from[i_index] == '/' && from[i_index+1] == '/'
		&& str == OUT)
		{
			state = OUT;
			++i_index;
			++i_index;
		}
		else if (from[i_index] == '\n' && state ==OUT)
		{
			state = IN;
		}
		if(from[i_index] == '/' && from[i_index+1] == '*' 
		&& str == OUT && state == IN)
		{
			printf("i=%d, char=%c, state=%d\n", i_index, from[i_index], state);
			state = OUT;
			++i_index;
			++i_index;

		}
		else if(from[i_index] == '*' && from[i_index+1] == '/' 
		&& state == OUT)
		{
			
			state = IN;
			++i_index;
			++i_index;
		}
		if (state == IN)
		{
			if (from[i_index] == '/' && from[i_index+1] == '*' && str == OUT)
			{
				state = OUT;
				++i_index;
				++i_index;
			}
			else
			{
				printf("i=%d, char=%c, state=%d\n", i_index, from[i_index], state);
				to[z_index] = from[i_index];
				++i_index;
				++z_index;
			}
			
		}
		else{
			printf("i=%d, char=%c, state=%d\n", i_index, from[i_index], state);
			++i_index;
		}
		
	}
	to[z_index] = '\0';
}