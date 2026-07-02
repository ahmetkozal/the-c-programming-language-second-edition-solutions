#include <stdio.h>

#define MAXLINE 100

#define IN 1
#define OUT 0

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
			str = IN;
		}
		else if (from[i_index] == '"' && str == IN)
		{
			str = OUT;
		}
		if(from[i_index] == '/' && from[i_index+1] == '*' 
		&& str == OUT)
		{
			state = OUT;
			++i_index;
		}
		else if(from[i_index] == '*' && from[i_index+1] == '/' 
		&& state == OUT)
		{
			state = IN;
			++i_index;
		}
		if (state == IN)
		{
			to[z_index] = from[i_index];
			++i_index;
			++z_index;
		}
		else{
			++i_index;
		}
		
	}
	to[z_index] = '\0';
}