#include <stdio.h>
/*for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) s[i] = c; */
/*Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||. */
#define MAXLINE 1000
int main(){
    int lim = MAXLINE;
    // Classic loop
    int m_c, i;
    m_c = i = 0;
    char s[MAXLINE];
    for (i=0; i < lim-1 && (m_c=getchar()) != '\n' && m_c != EOF; ++i){
        s[i] = m_c;
    }
    s[i] = '\0';
    printf("MAIN FOR LOOP RESULT:\n%s\n",s);
    printf("\n");
    
    // loop without && or ||
    int a_c, z;
    a_c = z = 0;
    char a_s[MAXLINE];
    while (z < lim - 1){
        if ((a_c = getchar())!='\n'){
            if (a_c != EOF){
                a_s[z] = a_c;
                ++z;
            }else{
                break;
            }
        }else{
            break;
        }
    }
    a_s[z] = '\0';
    printf("ALTERNATIVE LOOP RESULT:\n%s\n",a_s);
    printf("\n");
    
    return 0;
}