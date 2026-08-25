#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> /* atof() */
/*Exercise 4-4. Add the commands to print the top elements of the stack without
popping, to duplicate it, and to swap the top elements. Add a command to clear
stack.
*/
#define BUFSIZE 100
#define NUMBER '0' /*Signal that number was found*/

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

double val[BUFSIZE];
int sp = 0; /*next free stack position*/
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf*/

// reverse polish calculator
int main() {
    int type, modul_op2;
    double op2;
    char s[BUFSIZE];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0)
                    push(pop() / op2);
                else
                    printf("error: divisor is zero\n");
                break;
            case '%':
                modul_op2 = (int)pop();
                if (op2 != 0)
                    push((int)pop() %  modul_op2);
                else
                    printf("error: divisor is zero\n");
                break;
            case 't':
                printf("top is: %g\n", val[sp - 1]);
                break;
            case 'd':
                val[sp] = val[sp - 1];
                sp++;
                break;
            case 's': {
                if (sp >= 2) {
                    double to_hold_top = val[sp - 1];
                    val[sp - 1] = val[sp - 2];
                    val[sp - 2] = to_hold_top;
                } else {
                    printf("stack doesn't have at least 2 elements\n");
                }
                break;
            }
            case 'c': {
                sp = 0;
                printf("stack cleared.\n");
                break;
            }
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unkown command %s\n",s);
      }
    }
    return 0;
}

void push(double f) {
    if (sp < BUFSIZE)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[]) { /*Get next character numeric or operand*/
    int i, c;
    int sign = 0;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c!='-' && c!='+')
        return c;/*Not a number and not - or +*/
    i = 0;

    if (c == '-' || c == '+')
        sign = c;

    if (isdigit(c) || sign>0) /*collect integer part*/
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /*collect fraction part*/
        while (isdigit(s[++i] = c = getch()))
            ;
    if (i == 1 && sign != 0) {
        ungetch(c);
        return sign;
    }
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}



int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungect: too many character\n");
    else
        buf[bufp++] = c;
}
