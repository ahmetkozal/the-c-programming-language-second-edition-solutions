#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>/* atof() */
#include <string.h>
#include <math.h>
/*
Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in Appendix B, Section 4.
*/
#define BUFSIZE 100
#define NUMBER '0' /*Signal that number was found*/
#define COMMAND '1' /*Signal that command was found*/

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
            case COMMAND:
                    if (strcmp(s, "sin") == 0) {
                        printf("COMMAND: %s\n", s);
                        push(sin(pop()));
                    }
                    else if (strcmp(s, "exp") == 0) {
                        printf("COMMAND: %s\n", s);
                        push(exp(pop()));
                    } else if (strcmp(s, "pow") == 0) {
                        if (sp>=2){
                            op2 = pop();
                            printf("COMMAND: %s\n", s);
                            push(pow(pop(), op2));
                        } else {
                            printf("pow needs 2 elements\n");
                        }
                    } else {
                        printf("unknown command\n");
                    }
                break;
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
                if (modul_op2 != 0)
                    push((int)pop() %  modul_op2);
                else
                    printf("error: divisor is zero\n");
                break;
            case 't':
                if (sp>=1){
                    printf("top is: %g\n", val[sp - 1]);
                } else {
                    printf("stack is empty.\n");

                }
                break;
            case 'd':
                if (sp>=1){
                val[sp] = val[sp - 1];
                sp++;
                } else {
                    printf("stack is empty.\n");
                }
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
                printf("error: unkown command %s\n", s);

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
    i=0;
    if (!isdigit(c) && c != '.' && c != '-' && c != '+') {
        if (isalpha(c)) {
            while (isalpha(s[++i] = c = getch()))
                ;
            s[i] = '\0';
            if (c != EOF)
                ungetch(c);
            return COMMAND;
        } else {
            return c; /*Not a number and not - or +*/
        }
    }

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
