/*
 * ============================================================================
 * File Name    : Q5.c
 * Author       : Rameez Ahmed
 * Date Created : 10/17/2026
 * Course       : Programming Fundamentals Theory (CS1002)
 * Lab / Task   : Assignment 1 Part A
 * ============================================================================
 */
 
 #include <stdio.h>

int main() {
    int num, sum;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    printf("Initial number: %d\n", num);
    
    while (num >= 10) {
        sum = 0;
        int temp = num;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        printf("Intermediate sum: %d\n", sum);
        num = sum;
    }
    
    printf("Final single-digit result: %d\n", num);
    return 0;
}
