#include <stdio.h>
/*Exercise 1-21. Write a program entab that replaces strings
 of blanks by the minimum number of tabs and blanks to achieve
 the same spacing. Use the same tab stops as for detab. When
 either a tab or a single blank would suffice to reach a tab
 stop, which should be given preference?*/
#define MAXLINE 1000
#define TAB 8
int tab_stops;
int getlinelen(char line[],int maxline);
void entab(char line[]);
int main(){
	int c;	
	char line[MAXLINE];
	char new_line[MAXLINE];	
	tab_stops = TAB;	
	while((c = getlinelen(line,MAXLINE)) > 0){
		entab(line);	
	}	
	return 0;	
	}
int getlinelen(char line[], int maxline){
	int c,i;
	i=0;
	while(i < maxline-1 && (c=getchar())!=EOF && c != '\n'){
		line[i] = c;
		++i;
	}
	if (c == '\n'){
		line[i] = '\n';
		++i;
	}
	line[i] = '\0';
	return i;
}
void entab(char line[]){
	int i,blank_count,temp_index;
	i = blank_count = 0;
	while (line[i] != '\n'){
		if (line[i] == ' '){
			temp_index =i;
			while(line[temp_index] == ' '){
				++blank_count;
				++temp_index;
			}
			while(blank_count>0){
				if ((i + blank_count) / tab_stops - i / tab_stops >= 1){
					printf("\t");
					i =((i / tab_stops + 1) * tab_stops);
					blank_count -= tab_stops;				
				}else{
					printf(" ");
					--blank_count;
					++i;
				}
			}
		}else{
			printf("%c",line[i]);
			++i;
		}
	}
	printf("\n");
}
