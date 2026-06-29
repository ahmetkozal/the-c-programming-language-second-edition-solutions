#include <stdio.h>
/*Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.*/

#define MAXLINE 1000
#define MAXWIDHT 10
#define TAB 8
int max_width;

int read_input(char text[],int maxline);
void fold_text(char text[]);

int main(){
	max_width = MAXWIDHT;
	int c;
	char line[MAXLINE];
	read_input(line,MAXLINE);
	printf("ORIGINAL INPUT TEXT:\n%s",line);
	fold_text(line);
	printf("%s",line);
}
int read_input(char text[],int maxline){
	int c,i;
	i = 0;
	while((c=getchar())!=EOF && i<maxline-1){
		text[i] = c;
		++i;
	}
	text[i] = '\0';
	return i;
}
void fold_text(char text[]){
	char current;
	printf("FOLDED TEXT:\n");
	int count, last_blank_index;
	count = last_blank_index = 0;
	for (int i = 0; text[i]!='\0'; ++i){
		//printf("i=%d c=%c count=%d\n", i, text[i], count);
		if (text[i] == ' ' || text[i] == '\t'){
			if (text[i] == '\t'){
				count+= TAB - (count % TAB);
			}
			last_blank_index = i;
		}
		if (text[i] == '\n'){
			count = last_blank_index = 0;
			
		}
		if (count > max_width){
			//printf("KESME OLDU i=%d\n", i);
			if (last_blank_index == 0){
					current = text[i];
					text[i] = '\n';
					++i;
					text[i] = current;
					count = 0;
				}
				else if (text[i] == ' ' || text[i] == '\t'){
					text[i] = '\n';
					count = last_blank_index = 0;
				}
				else{
					text[last_blank_index] = '\n';
					count = last_blank_index = 0;
				}
		}
		++count;
	}
}