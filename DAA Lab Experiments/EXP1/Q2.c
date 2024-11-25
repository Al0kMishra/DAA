//2) Find all the roots of a quadratic equation ax2+bx+c=0
#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, disc, root1, root2, realPart, imaginaryPart;
//disc= dicriminant
    printf("Enter coefficients a, b, and c: ");
    scanf("%f %f %f", &a, &b, &c);
//discriminant = b^2-4ac
    disc = b * b - 4 * a * c;
//real and different roots
    if (disc > 0) {
        root1 = (-b + sqrt(disc)) / (2 * a);
        root2 = (-b - sqrt(disc)) / (2 * a);
        printf("Roots are real and different.\nRoot 1 = %.2f\nRoot 2 = %.2f\n", root1, root2);
    }
    //real and same roots 
    else if (disc == 0) {
        root1 = root2 = -b / (2 * a);
        printf("Roots are real and the same.\nRoot 1 = Root 2 = %.2f\n", root1);
    }
    //complex roots with real and imaginary part
    else {
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-disc) / (2 * a);
        printf("Roots are complex and different.\n");
        printf("Root 1 = %.2f + %.2fi\n", realPart, imaginaryPart);
        printf("Root 2 = %.2f - %.2fi\n", realPart, imaginaryPart);
    }

    return 0;
}

