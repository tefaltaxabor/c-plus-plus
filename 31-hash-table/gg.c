#include <stdio.h>
#include <stdbool.h>

bool validate_card(long num_card);

int main() {
    long num_card;

    // Prompt user for credit card number
    printf("Enter credit card number: ");
    scanf("%ld", &num_card);

    // Validate the card using Luhn's algorithm
    if (validate_card(num_card)) {
        printf("VALID\n");
    } else {
        printf("INVALID\n");
    }

    return 0;
}

bool validate_card(long num_card) {
    int sum = 0;
    int position = 0;

    // Loop through each digit of the card number
    while (num_card > 0) {
        int digit = num_card % 10;

        // If the position is even (from the right, starting at 0), add the digit directly
        if (position % 2 == 0) {
            sum += digit;
        } else {
            // If the position is odd, multiply the digit by 2
            int product = digit * 2;
            // Add the sum of the product's digits to the sum
            sum += product / 10 + product % 10;
        }

        // Move to the next digit
        num_card /= 10;
        position++;
    }

    // The card is valid if the sum modulo 10 is 0
    return sum % 10 == 0;
}
