/*
 * ============================================================================
 * File Name    : Q1.c
 * Author       : Rameez Ahmed
 * Date Created : 10/17/2026
 * Course       : Programming Fundamentals Theory (CS1002)
 * Lab / Task   : Assignment 1 Part B
 * ============================================================================
 */

#include <stdio.h>

int main() {
    int n,i;
    printf("Enter total number of guests (N): ");
    scanf("%d", &n);
    
    float total_revenue = 0.0;
    
    for (i = 1; i <= n; i++) {
        int season, room_type, nights;
        float rate = 0.0, base_total = 0.0, discount = 0.0, final_price = 0.0;
        
        printf("\n--- Guest %d Details ---\n", i);
        printf("Enter season (1 for Peak, 2 for Off-Peak): ");
        scanf("%d", &season);
        
        printf("Enter Room Type (1 for Standard, 2 for Deluxe, 3 for Suite): ");
        scanf("%d", &room_type);
        
        printf("Enter number of nights: ");
        scanf("%d", &nights);
        
        // Nested decision-making matching your pseudocode structure
        if (season == 1) {
            if (room_type == 1) {
                rate = 5000.0;
            } else if (room_type == 2) {
                rate = 8000.0;
            } else if (room_type == 3) {
                rate = 12000.0;
            }
        } else if (season == 2) {
            if (room_type == 1) {
                rate = 3000.0;
            } else if (room_type == 2) {
                rate = 5000.0;
            } else if (room_type == 3) {
                rate = 8000.0;
            }
        }
        
        base_total = rate * nights;
        
        // Long-stay discount check (> 7 nights gets 15% discount)
        if (nights > 7) {
            discount = base_total * 0.15;
        } else {
            discount = 0.0;
        }
        
        final_price = base_total - discount;
        printf("Guest Final Price: Rs. %.2f\n", final_price);
        
        // Accumulate total revenue
        total_revenue += final_price;
    }
    
    printf("\n========================================\n");
    printf("Hotel's Total Revenue: Rs. %.2f\n", total_revenue);
    printf("========================================\n");
    
    return 0;
}
