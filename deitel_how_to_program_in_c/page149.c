/* #include <stdio.h>
int main() {
    float score;
    char grade;
    // Prompt the user to enter the numeric score
    printf("Enter the numeric grade: ");
    scanf("%f", &score);
    // Determine letter grade based on the score
    if (score >= 90.0) {
        grade = 'A';
    } else if (score >= 80.0) {
        grade = 'B';
    } else if (score >= 70.0) {
        grade = 'C';
    } else if (score >= 60.0) {
        grade = 'D';
    } else {
        grade = 'F';
    }
    // Display the letter grade
    printf("The letter grade is %c\n", grade);
    return 0;
} */
#include <stdio.h>
int main() {
    float score;
    char grade;
    // Prompt the user to enter the numeric grade
    printf("Enter the numeric grade: ");
    scanf("%f", &score);
    // Using switch on integer division of score by 10.
    switch ((int)score / 10) {
        case 10:  // Handles 100 (and any values above 100, if allowed)
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        default:
            grade = 'F';
    }
    // Display the letter grade
    printf("The letter grade is %c\n", grade);
    return 0;
}