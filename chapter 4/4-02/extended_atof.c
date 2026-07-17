#include <stdio.h>
#include <ctype.h>
/*Exercise 4-2. Extend atof to handle scientific notation of
the form */
#define MAXLINE 1000  
double atof(char s[]);
double my_pow(double base, int pow_val);
int main() {
	char s8[] = "123e10";
    char s[] = "123.45";
    char s2[] = "123.45e-2";
    char s3[] = "123.45e2";
    char s4[] = "1e3";
    char s5[] = "1e-3";
    char s6[] = "-1.5e2";
    char s7[] = "+2.5e-2";
	printf("%s -> %f\n",s8,atof(s8));
    printf("%s -> %f\n",s,atof(s));
    printf("%s -> %f\n",s2,atof(s2));
    printf("%s -> %f\n",s3,atof(s3));
	printf("%s -> %f\n",s4,atof(s4));
	printf("%s -> %f\n",s5,atof(s5));
	printf("%s -> %f\n",s6,atof(s6));
	printf("%s -> %f\n",s7,atof(s7));
    return 0;
}
double atof(char s[]){
    double val, power;
    int i, sign, pow_sign, pow_val;
    for (i = 0; isspace(s[i]);i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]);i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]);i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E'){
        ++i;
        pow_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (pow_val = 0; isdigit(s[i]);i++)
            pow_val = 10 * pow_val + (s[i] - '0');
        pow_val *= pow_sign;
        return (sign * val / power) * my_pow(10,pow_val);
    }
    return sign * val / power;
}
double my_pow(double base, int pow_val){
    double result = 1;
    if (pow_val < 0){
        for (int i = pow_val; i<0;++i){
            result /= base;
        }
    }else{
        for (int i = 0; i<pow_val;++i){
            result *= base;
        }
    } 
    return result;
}