/* Below is an example of a C program that calculates compound interest using the formula:

  A = P × (1 + r/n)^(n × t)

Where:  
• P is the principal amount  
• r is the annual interest rate (as a decimal)  
• n is the number of times interest is compounded per year  
• t is the time in years  
• A is the final amount after t years

### C Code Example
 */
#include <stdio.h>
#include <math.h>

int main() {
    double principal, rate, time, amount;
    int compounded;

    // Prompt the user to enter the principal amount
    printf("Enter the principal amount: ");
    scanf("%lf", &principal);

    // Prompt the user to enter the annual interest rate (in %)
    printf("Enter the annual interest rate (in %%): ");
    scanf("%lf", &rate);

    // Prompt the user to enter the time period in years
    printf("Enter the time in years: ");
    scanf("%lf", &time);

    // Prompt for the number of compounding periods per year
    printf("r: ");
    scanf("%d", &compounded);

    // Convert annual interest rate from a percentage to a decimal
    rate = rate / 100.0;

    // Calculate the final amount using the compound interest formula:
    // A = P * (1 + r/n)^(n*t)
    amount = principal * pow((1 + rate / compounded), compounded * time);

    // Display the results
    printf("\nFinal amount after %.2f years: %.2lf\n", time, amount);
    printf("Compound interest earned: %.2lf\n", amount - principal);

    return 0;
}
/* 
### Explanation

- The program starts by including the necessary header files:  
  • stdio.h for input and output functions  
  • math.h for the pow function used in the compound interest calculation

- The user is prompted for the following inputs:  
  • Principal amount  
  • Annual interest rate (as a percentage)  
  • Time period in years  
  • Number of compounding periods per year

- The annual interest rate is converted to a decimal by dividing by 100.

- The compound interest formula is used to calculate the final amount.

- The program then outputs the final amount after the specified period and the compound interest earned.

Compile this code with a C compiler such as gcc (e.g., gcc compound_interest.c -lm) ensuring that the math library is linked using the -lm flag. */