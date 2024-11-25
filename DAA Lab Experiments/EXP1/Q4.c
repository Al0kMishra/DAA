//4) Determine and Output Whether Number N is Even or Odd
#include <stdio.h>

int main() {
    int num;

    printf("Enter a num: ");
    scanf("%d", &num);

    if (num % 2 == 0) {
        printf("The num %d is even.\n", num);
    } else {
        printf("The num %d is odd.\n", num);
    }

    return 0;
}
/*
start
input a number n by user 
check if num is divisible by 2 by modulus operator (%)
if true then n is even
else  is odd */
