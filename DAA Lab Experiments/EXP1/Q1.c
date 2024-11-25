//1) Find the sum of all the multiples of 3 or 5 below 1000.
#include <stdio.h>

int main() {
    int sum = 0;

    for (int i = 1; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    printf("The sum of all multiples of 3 or 5 below 1000 is: %d\n", sum);
    return 0;
}

/*first we initilize the sum to store total sum
here we are using for loop to iterate each number from 1 to 999
and then for each number we will check if the number is divisible by 3 or 5 using modulus operator (%)
if the number is divisible then we will add it to the sum
after running the entire loop it will print the sum of numbers
*/