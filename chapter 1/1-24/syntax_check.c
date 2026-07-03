#include <stdio.h>
/*Exercise 1-24. Write a program to check a C program
for rudimentary syntax errors like unmatched parentheses
and braces. Don't forget about quotes, both single and 
double, escape sequences, and comments. (This program is hard
if you do it in full generality.)*/
/*(())[""]"{}"{*/
#define MAXLINE 1000
#define IN 1
#define OUT 0


int get_text(char s[], int limit);
int create_symbol_arr(char s[],char symbols[]);
void check_for_errors(char s[], int symbols_len);

int main(){
	char s[MAXLINE];
	char symbols[MAXLINE];
	int symbols_len;
	
	get_text(s,MAXLINE);
	printf("I:\n%s\n",s);
	symbols_len = create_symbol_arr(s,symbols);
	printf("O:\n%s",symbols);
	check_for_errors(symbols,symbols_len);
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

//Sadece kontrol edecegim sembollerden olusan bir dizi olustur.
//Yani string ve comment aralarini dahil etme. (){}[] olacak sadece.
int create_symbol_arr(char s[], char symbols[])
{
	int str = OUT;
	int cmt = OUT;
	
	char symbol_list[] = {"\n(){}[]"};
	
	int i, z;
	i = z = 0;
	
	int cancel_count;
	cancel_count = 0;
	
	while(s[i]!='\0')
	{
		if (s[i] == '\\')
		{
			++cancel_count;
		}
		if (str == OUT && s[i] == '\"')
		{
			if (s[i-1] == '\\')
			{
				if (cancel_count%2==0)
				{
					str = IN;
				}
			}
			
		}
		else if (str == IN && s[i] == '\"' )
		{
			str = OUT;
		}
		/*Detect comments
		if()
		{
			
		}
		else if()
		{
			
		}
		*/
		if(str == OUT)
		{
			for (int j = 0;symbol_list[j]!='\0';++j)
			{
				if (s[i] == symbol_list[j])
				{
					symbols[z] = s[i];
					++z;
					break;
				}
			}
		}
		++i;
	}
	symbols[z] = '\0';
	return z;
}

void check_for_errors(char s[],int arr_len)
{
	int i = 0;
	while (s[i]!='\0')
	{
		
		
		++i;
	}
}