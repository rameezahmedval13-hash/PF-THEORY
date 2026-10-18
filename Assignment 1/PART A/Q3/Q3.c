/*
 * ============================================================================
 * File Name    : Q3.c
 * Author       : Rameez Ahmed
 * Date Created : 10/17/2026
 * Course       : Programming Fundamentals Theory (CS1002)
 * Lab / Task   : Assignment 1 Part A
 * ============================================================================
 */

#include <stdio.h>

int main() {
    long long num;
    int count = 0;
    
    printf("Enter a number: ");
    scanf("%lld", &num);
    
    long long temp = num;
    if (temp == 0) {
        count = 1;
    } else {
        if (temp < 0) temp = -temp; // Handle negative numbers
        while (temp > 0) {
            count++;
            temp /= 10;
        }
    }
    
    printf("Number of digits: %d\n", count);
    if (count == 1) {
        printf("It is a single-digit number.\n");
    } else if (count == 2) {
        printf("It is a double-digit number.\n");
    } else {
        printf("It is a triple-digit (or more) number.\n");
    }
    return 0;
}
