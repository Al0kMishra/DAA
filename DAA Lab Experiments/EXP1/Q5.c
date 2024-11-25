//5) Calculate the remainder, and the quotient of two given numbers.
#include <stdio.h>

int main() {
    int dividend, divisor, quotient, remainder;

    printf("Enter dividend: ");
    scanf("%d", &dividend);
    printf("Enter divisor: ");
    scanf("%d", &divisor);

    quotient = dividend / divisor;
    remainder = dividend % divisor;

    printf("Quotient is  %d\n", quotient);
    printf("Remainder is %d\n", remainder);

    return 0;
}
/*first we will declare int functions (divident,divisor,quotientand reminder)
then we will ask user to inser divident and then divisor
calculate the quotient= divident/divisor
calculte the reminder divident%divisor
output the values of quotient and reminder*/
