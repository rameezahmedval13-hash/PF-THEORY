/*
 * ============================================================================
 * File Name    : Q3.c
 * Author       : Rameez Ahmed
 * Date Created : 10/18/2026
 * Course       : Programming Fundamentals Theory (CS1002)
 * Lab / Task   : Assignment 1 Part B
 * ============================================================================
 */

#include <stdio.h>

int main() {
    int n,i;
    printf("Enter total number of students (N): ");
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++) {
        int m1, m2, m3, m4, m5;
        int sum = 0;
        float avg = 0.0;
        
        printf("\n--- Student %d Details ---\n", i);
        printf("Enter marks for 5 subjects (out of 100): ");
        scanf("%d %d %d %d %d", &m1, &m2, &m3, &m4, &m5);
        
        sum = m1 + m2 + m3 + m4 + m5;
        avg = sum / 5.0;
        
        // Decision-making matching your pseudocode structure
        if (m1 < 33 || m2 < 33 || m3 < 33 || m4 < 33 || m5 < 33) {
            printf("Average: %.2f\n", avg);
            printf("Result: Fail - Subject Deficiency\n");
        } 
        else if (avg >= 80.0) {
            printf("Average: %.2f\n", avg);
            printf("Result: Distinction\n");
        } 
        else if (avg >= 60.0) {
            printf("Average: %.2f\n", avg);
            printf("Result: Pass\n");
        } 
        else {
            printf("Average: %.2f\n", avg);
            printf("Result: Fail\n");
        }
    }
    
    return 0;
}
