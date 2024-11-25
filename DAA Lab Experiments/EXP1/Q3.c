//3) Find the largest among three different numbers entered by user.


#include <stdio.h>

int main() {
    int num1, num2, num3;

    printf("Enter three different numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 >= num2 && num1 >= num3) {
        printf("The largest number is: %d\n", num1);
    }
    else if (num2 >= num1 && num2 >= num3) {
        printf("The largest number is: %d\n", num2);
    }
    else {
        printf("The largest number is: %d\n", num3);
    }

    return 0;
}
/*input three number by user 
compare the numbers
  if num1>num2&num3 then num 1 is greatest
  if num2>num1&num3 then num 2 is greatest
  else num 3 is greatest
output the greatest number  
  */