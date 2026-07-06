#include <stdio.h>

#define MAXLINE 1000
#define IN      1
#define OUT     0


int get_text(char s[], int limit);
int create_symbol_arr(char s[],char symbols[]);

int get_escape_count(int index, char sp[]);

void check_for_errors(char s[]);

void check_str_state(int index, char s[], int *state_to_change);
void check_comment_state(int index, char s[]);

char pop(void);
void push(char c);

int str;
int single_str;
int cmt;
int single_cmt;
int stack_pos = 0;

char stack[MAXLINE];

int main(){
    char    s[MAXLINE];
    char    symbols[MAXLINE];

    int symbol_len;

    get_text(s,MAXLINE); //Get input
    printf("I:\n%s\n",s); //Print input
                          //
    symbol_len = create_symbol_arr(s,symbols); //Sadece gerekli sembolleri al, bu sirada leni de al
    printf("O:\n%s\n",symbols ); //print kontrol edilecek semboller
                               //
    check_for_errors(symbols); //hata icin kontrol

    printf("\n"); //son print icin.
    return 0;
}

void check_for_errors(char s[])
{
    int i = 0;
    printf("STACK:%s\n",stack);
    while(s[i]!='\0')
    {
        if (s[i] == ('(') || s[i] == ('{') || s[i] == ('['))
        {
            push(s[i]);
        }
        else if (s[i] == (')') || s[i] == ('}') || s[i] == (']'))
        {
            char c = pop();
            printf("%d: CHAR:%c\n",i, c);
            printf("S:%c\n",s[i]);
            if (c == '(' && s[i]!=')')
            {
                printf("ERROR, NO CLOSING ()\n");
            }
            else if (c == '{' && s[i]!='}')
            {
                printf("ERROR, NO CLOSING {}\n");
            }
            else if (c == '[' && s[i]!=']')
            {
                printf("ERROR, NO CLOSING []\n");
            }
            else
            {
                printf("NO ERROR\n");
            }
        }
        printf("%d: STACK-->%s\n",i, stack);
        ++i;
    }
}
char pop(void)
{
    if (stack_pos > 0)
    {
        --stack_pos;
        return stack[stack_pos];
    }
    else
    {
        printf("ERROR-Stack is empty\n");
        return stack[stack_pos];
    }
}
void push(char c)
{
    if (stack_pos>MAXLINE)
    {
        printf("ERROR\n");
    }
    else
    {
        stack[stack_pos] = c;
        ++stack_pos;
    }
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

int create_symbol_arr(char s[],char symbols[]) //Sadece kontrol edecegim sembollerden olusan bir dizi olustur.
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
        check_comment_state(i,s);
        if(str == OUT && single_str == OUT && cmt == OUT && single_cmt == OUT)//sadece kontrol edecegimiz sembollerden olusan bir dizi olustur.
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

int get_escape_count(int i, char s[])//To count escapes
{
    int count = 0;
    for (int z = i-1;z>=0 && s[z] == '\\';--z)
    {
        ++count;
    }
    return count;
}

void check_str_state(int index, char s[], int *state_to_change) //To check str states
{//Eger " gelirse, str OUT ise, oncesi ESCAPE degil ise str=IN
    if (get_escape_count(index,s) %2 == 0) //Eger " oncesi \->escape ise escape_count saymaya basla. escape_count % 2 == 0 ise str = IN olacak
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

void check_comment_state(int i, char s[]) //To check comment states
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
