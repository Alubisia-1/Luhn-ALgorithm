#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void luhn_pointers(char *cardNumber) {
  char *start = cardNumber;
  char *p = cardNumber;
  int digit;
  int sum = 0;
  int double_flag = 0;
  int result;

  while (*p != 0) {
    if (*p < '0' || *p > '9') {
      printf("Invalid Card Number!");
      return;
    }
    p++;
  }

  p = start;

  if (*p == '4') {
    printf("Visa Card!\n");
  }
  else if (*p == '5' && *(p + 1) != '\0' && *(p + 1) >= '1' && *(p + 1) <= '5'){
    printf("MasterCard\n");
  }

while (*p != '\0') {
  p++;
}
p--;

  while (p >= start)  {
    digit = *p - '0';
    if(double_flag) {
     result = digit * 2;
     if(result > 9) {
        result = result - 9;
     }
     sum = sum + result;
    } else {
      sum = sum + digit;
    }
    double_flag = !double_flag;
    p--;
  }

  if (sum % 10 == 0) {
    printf("Valid Card Number!\n");
  } else {
    printf("Invalid Card Number\n");
  }
}

int main() {
  char cardNumber[32];
  printf("Enter Card Number: ");
  scanf("%31s", cardNumber);

  luhn_pointers(cardNumber);


 return 0;
}
