#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void card_type(char cardNumber[]) {
  if (cardNumber[0] == '4') {
    printf("Visa Card\n");
  } else if (cardNumber[0] == '5' && cardNumber[1] >= '1' && cardNumber[1] <= '5') {
    printf("Mastercard\n");
  }
}


void luhn_check(char cardNumber[]) {    
    for (int i = 0; cardNumber[i] != '\0'; i++) {
        if (cardNumber[i] < '0' || cardNumber[i] > '9') {
            printf("Invalid Card Number");
            return;
        }
    }
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
        printf("Valid Card Number\n");
    }
    else {
        printf("Invalid Card Number\n");
    }     
}

int main() {
  char cardNumber[32];
  printf("Enter Card Number: ");
  scanf("%31s", cardNumber);

    
    card_type(cardNumber); 
    luhn_check(cardNumber);
    
    return 0;
}
