#include <stdio.h>
/*Exercise 4-3. Given the basic framework, it's straightforward to extend
the calculator. Add the modulus (%) operator and provisions for negative
numbers*/
#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf*/
int main() { return 0; }
int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungect: too many character");
    else
        buf[bufp++] = c;
}
