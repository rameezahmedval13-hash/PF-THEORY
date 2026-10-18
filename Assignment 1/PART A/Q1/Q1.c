/*
 * ============================================================================
 * File Name    : Q1.c
 * Author       : Rameez Ahmed
 * Date Created : 10/17/2026
 * Course       : Programming Fundamentals Theory (CS1002)
 * Lab / Task   : Assignment 1 Part A
 * ============================================================================
 */

#include <stdio.h>

int main() {
    int n;
    int i;
    
    printf("Enter a number N: \n");
    scanf("%d", &n);
    
    printf("Numbers from %d down to 1:\n", n);
    for (i = n; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
