#include <stdio.h>
/*Exercise 1-11. How would you test the word count program? What kinds of input are most
likely to uncover bugs if there are any?*/
#define IN 1
#define OUT 0

int main(){
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF){
        ++nc;
        if (c == ' ' || c == '\n' || c == '\t'){
            if (c == '\n'){
                    ++nl;}
            state = OUT;
        }
        else if(state == OUT){
            state = IN;
            ++nw;
        }

    }
    printf("WORDS: %d | CHARS: %d | NEW LINES: %d",nw,nc,nl);
}
