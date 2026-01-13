#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void luhn_check() {
    char cardNumber[32];
    printf("Enter card Number: ");
    scanf("%31s", cardNumber);
    printf("Card Number: %s\n", cardNumber);

    int lastIndex = strlen(cardNumber) - 1;

    int sum = 0;
    int doubleNext = 0;
    int digit;
    int result;

    for (int i = lastIndex; i >= 0; i--) {
        digit = cardNumber[i] - '0';
        if (doubleNext == 1) {
            result = digit * 2;
            if (result > 9) {
                result = result - 9;
            } 
            sum = sum + result;
        }
        else {
            sum = sum + digit;
        }
         doubleNext = !doubleNext;
    }
    if (sum % 10 == 0) {
        printf("Valid Card Number;\n");
    }
    else {
        printf("Invalid Card Number;");
    }     
}

int main() {
    luhn_check();
}
