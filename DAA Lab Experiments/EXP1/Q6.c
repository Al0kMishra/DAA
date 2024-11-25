//6) Generate even numbers between 100 and 200.
#include <stdio.h>

int main() {
    printf("Even numbers between 100 and 200 are:\n");

    for (int i = 100; i <= 200; i += 2) {
        printf("%d ", i);
    }

    printf("\n");
    return 0;
}
/*algorithm
start the loop with i=100
while i<200
print i
increment i by 2 to get to next even number 
till the loop ends 
 */
