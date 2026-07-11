#include <stdio.h>
/*Exercise 3-1. Our binary search makes two tests inside the loop, 
when one would suffice (at the price of more tests outside.) 
Write a version with only one test inside the loop and measure 
the difference in run-time. */
#define MAXLINE 1000
int binsearch(int x, int v[], int n);
int new_binsearch(int x, int v[], int n);
int main(){
    int x, n;
    x = 5;
    n = 9;
    int v[MAXLINE] = {1,2,3,4,5,6,7,8,9};
    printf("%i\n",binsearch(x,v,n));
    return 0;
}
int binsearch(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high)/2;
        if (x < v[mid])
            high = mid + 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}