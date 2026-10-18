/*
 * ============================================================================
 * File Name    : Q5.c
 * Author       : Rameez Ahmed
 * Date Created : 10/18/2026
 * Course       : Programming Fundamentals Theory (CS1002)
 * Lab / Task   : Assignment 1 Part B
 * ============================================================================
 */


#include <stdio.h>

int main() {
    int n,i;
    printf("Enter total number of vehicles to process (N): ");
    scanf("%d", &n);
    
    // Initial capacities
    int capA = 20; // Faculty zone capacity
    int capB = 40; // Student zone capacity
    int capC = 15; // Visitor zone capacity
    
    // Statistics counters
    int total_processed = 0;
    int accepted_count = 0;
    int rejected_count = 0;
    int cars_parked = 0;
    int bikes_parked = 0;
    int vans_parked = 0;
    
    for (i = 1; i <= n; i++) {
        char vehicle_type, user_cat, has_permit, is_emergency = 'N';
        
        printf("\n--- Vehicle %d Processing ---\n", i);
        printf("Enter vehicle type (C: Car, B: Bike, V: Van): ");
        scanf(" %c", &vehicle_type);
        
        printf("Enter User Category (F: Faculty, S: Student, G: Visitor): ");
        scanf(" %c", &user_cat);
        
        printf("Has Valid Permit? (Y/N): ");
        scanf(" %c", &has_permit);
        
        total_processed++;
        
        //Input validation
        if ((vehicle_type != 'C' && vehicle_type != 'B' && vehicle_type != 'V') ||
            (user_cat != 'F' && user_cat != 'S' && user_cat != 'G') ||
            (has_permit != 'Y' && has_permit != 'N')) {
            printf("Error: Invalid Input / Rejected\n");
            rejected_count++;
        } 
        else {
            if (has_permit == 'N') {
                printf("Is Emergency vehicle? (Y/N): ");
                scanf(" %c", &is_emergency);
            } else {
                is_emergency = 'N';
            }
            
            //Check access control rules
            if (has_permit == 'N' && is_emergency == 'N') {
                printf("Access Denied: No permit and not an emergency\n");
                rejected_count++;
            }
            else {
                //Faculty (F)
                if (user_cat == 'F') {
                    if (capA >= 1) {
                        capA = capA - 1;
                        printf("Access Approved: Assigned to Zone A\n");
                        accepted_count++;
                        if (vehicle_type == 'C') cars_parked++;
                        else if (vehicle_type == 'B') bikes_parked++;
                        else if (vehicle_type == 'V') vans_parked++;
                    } else {
                        printf("Access Denied: Zone A is full\n");
                        rejected_count++;
                    }
                }
                //Student (S)
                else if (user_cat == 'S') {
                    if (vehicle_type == 'V') {
                        //Student van redirected to Zone C (requires 2 spaces)
                        if (capC >= 2) {
                            capC = capC - 2;
                            printf("Access Approved: Redirected to Zone C\n");
                            accepted_count++;
                            vans_parked++;
                        } else {
                            printf("Access Denied: Zone C has insufficient space\n");
                            rejected_count++;
                        }
                    } else {
                        //Student car/bike assigned to Zone B
                        if (capB >= 1) {
                            capB = capB - 1;
                            printf("Access Approved: Assigned to Zone B\n");
                            accepted_count++;
                            if (vehicle_type == 'C') cars_parked++;
                            else if (vehicle_type == 'B') bikes_parked++;
                        } else {
                            printf("Access Denied: Zone B is full\n");
                            rejected_count++;
                        }
                    }
                }
                //Visitor (G)
                else if (user_cat == 'G') {
                    if (vehicle_type == 'V') {
                        //Visitor van requires 2 spaces in Zone C
                        if (capC >= 2) {
                            capC = capC - 2;
                            printf("Access Approved: Assigned to Zone C\n");
                            accepted_count++;
                            vans_parked++;
                        } else {
                            printf("Access Denied: Zone C has insufficient space\n");
                            rejected_count++;
                        }
                    } else {
                        //Visitor car/bike requires 1 space in Zone C
                        if (capC >= 1) {
                            capC = capC - 1;
                            printf("Access Approved: Assigned to Zone C\n");
                            accepted_count++;
                            if (vehicle_type == 'C') cars_parked++;
                            else if (vehicle_type == 'B') bikes_parked++;
                        } else {
                            printf("Access Denied: Zone C is full\n");
                            rejected_count++;
                        }
                    }
                }
            }
        }
    }
    
    
    int occupiedA = 20 - capA;
    int occupiedB = 40 - capB;
    int occupiedC = 15 - capC;
    
    //Final Summary Report
    printf("\n========================================\n");
    printf("     SMART CAMPUS PARKING SUMMARY       \n");
    printf("========================================\n");
    printf("Total vehicles processed: %d\n", total_processed);
    printf("Total accepted vehicles: %d[cite: 17]\n", accepted_count);
    printf("Total rejected vehicles: %d[cite: 17]\n", rejected_count);
    printf("Cars parked: %d[cite: 17]\n", cars_parked);
    printf("Bikes parked: %d[cite: 17]\n", bikes_parked);
    printf("Vans parked: %d[cite: 17]\n", vans_parked);
    printf("\nZone A (Faculty)  - Occupied: %d, Remaining Capacity: %d[cite: 17]\n", occupiedA, capA);
    printf("Zone B (Students) - Occupied: %d, Remaining Capacity: %d[cite: 17]\n", occupiedB, capB);
    printf("Zone C (Visitors) - Occupied: %d, Remaining Capacity: %d[cite: 17]\n", occupiedC, capC);
    
    //Highest occupancy zone determination
    printf("\nZone with highest occupancy: ");
    if (occupiedA >= occupiedB && occupiedA >= occupiedC) {
        printf("Zone A[cite: 17]\n");
    } else if (occupiedB >= occupiedA && occupiedB >= occupiedC) {
        printf("Zone B[cite: 17]\n");
    } else {
        printf("Zone C[cite: 17]\n");
    }
    
    //Campus facility full check
    if (capA == 0 && capB == 0 && capC <= 1) {
        printf("Campus Parking Facility Status: FULL[cite: 17]\n");
    } else {
        printf("Campus Parking Facility Status: NOT FULL[cite: 17]\n");
    }
    printf("========================================\n");
    
    return 0;
}
