/*
 * ============================================================================
 * File Name    : Q2.c
 * Author       : Rameez Ahmed
 * Date Created : 10/18/2026
 * Course       : Programming Fundamentals Theory (CS1002)
 * Lab / Task   : Assignment 1 Part B
 * ============================================================================
 */
 
#include <stdio.h>

int main() {
    int n,i;
    
    printf("Enter total number of floor requests (N): ");
    scanf("%d", &n);
    
    int current_floor = 0; // Elevator starts at the ground floor (Floor 0)
    printf("Elevator starts at Floor 0.\n\n");
    
    for (i = 1; i <= n; i++) {
        int requested_floor;
        printf("Enter requested floor for request %d: ", i);
        scanf("%d", &requested_floor);
        
        
        if (requested_floor > current_floor) {
            printf("Moving Up\n");
        } else if (requested_floor < current_floor) {
            printf("Moving Down\n");
        } else {
            printf("Doors Opening\n");
        }
        
        
        current_floor = requested_floor;
        printf("Elevator is now at floor: %d\n\n", current_floor);
    }
    
    printf("All requests processed. Final elevator position: Floor %d\n", current_floor);
    
    return 0;
}
