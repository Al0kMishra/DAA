// Q 1) Write function to calculate the Sum of n natural numbers using recursion

#include <stdio.h>
int sum_of_natural_numbers(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sum_of_natural_numbers(n - 1);
}

int main() {
    int n;

    printf("Enter a natural number: ");
    scanf("%d", &n);

    int sum = sum_of_natural_numbers(n);

    printf("Sum of first %d natural numbers is: %d\n", n, sum);
    return 0;
}
/*
we will create a function called sum_of_natural_number 
base case would be if n =0
recursive case -- sum of n is n plus sum of previous numbers
ask the user for input of number n 
then we will print the sum of natural number upto n
*/