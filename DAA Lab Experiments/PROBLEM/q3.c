//3) Convert Uppercase String to Lowercase
#include <stdio.h>
#include <ctype.h>

void toLowercase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) // Check if character is uppercase
            str[i] = tolower(str[i]); // Convert to lowercase
    }
}

int main() {
    char str[] = "HeLLo WoRLd!";
    printf("Original string: %s\n", str);

    toLowercase(str);
    printf("Lowercase string: %s\n", str);

    return 0;
}
