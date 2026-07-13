#include <stdio.h>
#include <time.h>
/*Exercise 3-1. Our binary search makes two tests inside the loop, 
when one would suffice (at the price of more tests outside.) 
Write a version with only one test inside the loop and measure 
the difference in run-time. */
#define MAXLINE 10000
int binsearch(int x, int v[], int n);
int new_binsearch(int x, int v[], int n);
int new_binsearch(int x, int v[], int n);
int main(){
    int x = 5000;
    int v[MAXLINE];
	int n = MAXLINE;
	for (int i = 0; i < n; i++) {
		v[i] = i + 1;  // 1'den 10000'e kadar
	}
	
	clock_t start = clock();
	for (int i = 0; i<=100000000;++i){
		binsearch(x,v,n);
	}
	clock_t end = clock();
	double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
	printf("OLD Zaman: %f saniye\n", elapsed);
	
	clock_t start_new = clock();
	for (int i = 0; i<=100000000;++i){
		new_binsearch(x,v,n);
	}
    clock_t end_new = clock();
	double new_elapsed = (double)(end_new - start_new) / CLOCKS_PER_SEC;
    printf("NEW Zaman: %f saniye\n", new_elapsed);
    return 0;
}
int new_binsearch(int x, int v[], int n){
    int low, mid, high;
    low = 0;
    high = n-1;
    mid = (low + high) /2 ;
	if (v[mid] == x){
		return mid;
	}
	else{
		while (low <= high){
			if(x < v[mid]) high = mid - 1;
			else low = mid + 1;
			mid = (low + high) /2 ;
		}
		return (v[mid] == x) ? mid : -1;
	}
}

int binsearch(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high)/2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}