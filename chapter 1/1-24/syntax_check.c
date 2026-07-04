#include <stdio.h>
/*Exercise 1-24. Write a program to check a C program
for rudimentary syntax errors like unmatched parentheses
and braces. Don't forget about quotes, both single and 
double, escape sequences, and comments. (This program is hard
if you do it in full generality.)*/
/*(())[""]"{}"{*/
#define MAXLINE 1000
#define IN      1
#define OUT     0


int get_text(char s[], int limit);
int create_symbol_arr(char s[],char symbols[]);

int get_escape_count(int index, char sp[]);

void check_for_errors(char s[], int symbols_len);

void check_str_state(int index, char s[], int *state_to_change);
void check_comment_state(int index, char[], int *state_to_change);



int main(){
    char    s[MAXLINE];
    char    symbols[MAXLINE];
    int     symbols_len;
    
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
    int str         = OUT;
    int single_str  = OUT;
    int cmt         = OUT;
    
    char symbol_list[] = {"\n(){}[]"};
    
    int i, new_i, escape_count;
    i = new_i = 0;
    
    while(s[i]!='\0')
    {
        /////////////////////////////////////
        //STR DURUM KONTROLU
        if (s[i] == '"')
        {
            check_str_state(i, s, &str);
            ++i;
        }
        else if (s[i] == '\'')
        {
            check_str_state(i, s, &single_str);
            ++i;
        }
        /////////////////////////////////////
        //COMMENT KONTROLU
        
        
        //sadece kontrol edecegimiz sembollerden olusan bir dizi olustur.
        if(str == OUT && single_str == OUT && cmt == OUT)
        {
            for (int j = 0;symbol_list[j]!='\0';++j)
            {
                if (s[i] == symbol_list[j])
                {
                    symbols[new_i] = s[i];
                    ++new_i;
                    break;
                }
            }
        }
        ++i;
    }
    symbols[new_i] = '\0';
    return new_i;
}

void check_for_errors(char s[],int arr_len)
{
    int i = 0;
    while (s[i]!='\0')
    {
        
        
        ++i;
    }
}

//To checking str states
void check_str_state(int index, char s[], int *state_to_change)
{
    //Eger " gelirse, str OUT ise, oncesi ESCAPE degil ise str=IN
    //Eger " oncesi \->escape ise escape_count saymaya basla. escape_count % 2 == 0 ise str = IN olacak
    int escape_count = 0;
    
    if (get_escape_count(index,s)%2 == 0)
    {
        if (*state_to_change == OUT)
        {
            *state_to_change = IN;
        }
        else
        {
            *state_to_change = OUT;
        }
    }
}

//To count escapes
int get_escape_count(int i, char s[])
{
    int count = 0;
    for (int z = i-1;z>=0 && s[z] == '\\';--z)
    {
        ++count;
    }
    return count;
}