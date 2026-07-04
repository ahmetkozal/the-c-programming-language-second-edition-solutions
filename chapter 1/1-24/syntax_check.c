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

void check_for_errors(char s[]);

void check_str_state(int index, char s[], int *state_to_change);
void check_comment_state(int index, char s[]);

int str;
int single_str;
int cmt;
int single_cmt;

int main(){
    char    s[MAXLINE];
    char    symbols[MAXLINE];

    get_text(s,MAXLINE);
    printf("I:\n%s\n",s);
    create_symbol_arr(s,symbols);
    printf("O:\n%s\n",symbols);
    //check_for_errors(symbols);
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
    //printf("DEBUG: str=%d, single_str=%d, cmt=%d, single_cmt=%d\n", str, single_str, cmt, single_cmt);
    str         = OUT;
    single_str  = OUT;
    cmt         = OUT;
    single_cmt  = OUT;

    char symbol_list[] = {"(){}[]"};

    int i, new_i;
    i = new_i = 0;

    while(s[i]!='\0')
    {
        //printf("DEBUG: i=%d, char='%c', str=%d, single_str=%d, cmt=%d, single_cmt=%d\n", i, s[i], str, single_str, cmt, single_cmt);
        /////////////////////////////////////
        //STR DURUM KONTROLU
        if (s[i] == '"')
        {
            check_str_state(i, s, &str);
            ++i;
            continue;
        }
        else if (s[i] == '\'')
        {
            check_str_state(i, s, &single_str);
            ++i;
            continue;
        }
        /////////////////////////////////////
        //COMMENT KONTROLU
        check_comment_state(i,s);


        //sadece kontrol edecegimiz sembollerden olusan bir dizi olustur.
        if(str == OUT && single_str == OUT && cmt == OUT && single_cmt == OUT)
        {
            for (int j = 0;symbol_list[j]!='\0';++j)
            {
                if (s[i] == symbol_list[j])
                {
                    //printf("DEBUG: adding %c\n", s[i]);
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

void check_for_errors(char s[])
{
    int i = 0;
    while (s[i]!='\0')
    {


        ++i;
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

//To check str states
void check_str_state(int index, char s[], int *state_to_change)
{
    //Eger " gelirse, str OUT ise, oncesi ESCAPE degil ise str=IN
    //Eger " oncesi \->escape ise escape_count saymaya basla. escape_count % 2 == 0 ise str = IN olacak

    if (get_escape_count(index,s) %2 == 0)
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

//To check comment states
void check_comment_state(int i, char s[])
{
    if (s[i] == '/' && s[i+1] == '*')
    {
        if (str == OUT && single_str == OUT && cmt == OUT && single_cmt == OUT)
        {
            if (get_escape_count(i,s) % 2 == 0)
            {
                cmt = IN;
            }
        }
    }
    else if(s[i] == '*' && s[i+1] == '/')
    {
        if (cmt == IN){
            if (get_escape_count(i,s) % 2 == 0)
            {
                cmt = OUT;
            }
        }
    }
    if (s[i] == '/' && s[i+1] == '/')
    {
        if (str == OUT && single_str == OUT && cmt == OUT && single_cmt == OUT)
        {
            if (get_escape_count(i,s) % 2 == 0)
            {
                single_cmt = IN;
            }
        }
    }
    else if(s[i] == '\n' && single_cmt == IN)
    {
        single_cmt = OUT;
    }
}
