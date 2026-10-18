/*
 * ============================================================================
 * File Name    : Q4.c
 * Author       : Rameez Ahmed
 * Date Created : 10/17/2026
 * Course       : Programming Fundamentals Theory (CS1002)
 * Lab / Task   : Assignment 1 Part A
 * ============================================================================
 */
 
 #include <stdio.h>

int main() {
	int i,j;
	
    for (i = 1; i <= 10; i++) {
        if (i % 3 == 0) {
            continue; // Skip tables of numbers that are multiples of 3
        }
        printf("--- Multiplication Table of %d ---\n", i);
        for (j = 1; j <= 10; j++) {
            printf("%d x %d = %d\n", i, j, i * j);
        }
        printf("\n");
    }
    return 0;
}

