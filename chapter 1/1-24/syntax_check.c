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
    
    int i, z, escape_count;
    i = z = 0;
    
    while(s[i]!='\0')
    {
        //Eger " gelirse, str OUT ise, oncesi ESCAPE degil ise str=IN
        //Eger " oncesi \->escape ise escape_count saymaya basla. escape_count % 2 != 0 ise str = IN olacak
        if (s[i] == '"' && s[i+1] != '"' && str == OUT)
        {
            if ((i!=0 && s[i-1] == '\\') || i == 0 && s[i] == '\\')
            {
                for(int e = i;s[e] != '\\' || e == 0;--e)
                {
                    if(s[e] == '\\')
                    {
                        ++escape_count;
                    }
                }
                if (escape_count%2!=0)
                {
                    str = IN;
                    ++i;
                    
                }
            }
            else if ((i!=0 && s[i-1] != '\\') || (s[i] == 0 && s[i] != '\\'))
            {
                str = IN;
                ++i;
            }
        }
        else if(s[i] == '"' && str == IN)
        {
            str = OUT;
            ++i;
        }
        
        
        
        //sadece kontrol edecegimiz sembollerden olusan bir dizi olustur.
        if(str == OUT && cmt == OUT)
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