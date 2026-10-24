/*=============================================================================
 * 
 * COURSE: Programming Fundamentals
 * SECTION: BDS-1A
 * Author: Rameez Ahmed , ROLL #: 26k-2527
 * 
 * FILE: Q1.c
 * DATE: 10/24/2026
 * DESCRIPTION:  
 *    A cinema hall seat booking management system using a 2D array. 
 *    It displays seating, reports availability, and allocates blocks of 
 *    consecutive seats using a manual distance-based middle-out search 
 *    algorithm, without the use of external helper functions.            
 * 
 *=============================================================================*/

#include <stdio.h>

int main() {
    int rows, cols, k;
    int i,j,r_idx,c,dist;

    //Input Seating Plan
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of seats per row: ");
    scanf("%d", &cols);

    //Using user inputs for dynamic sizing of array
    int matrix[rows][cols];
    
    printf("Enter seating status (0 for available, 1 for booked):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }//NEXT j (endfor)
    }//NEXT i (endfor)

    //Display Initial Seating Arrangement
    printf("\n--- Seating Arrangement ---\n");
    printf("    ");
    for (j = 0; j < cols; j++) {
        printf("%d ", j);
    }//NEXT j (endfor)
    printf("\n");
    
    for (i = 0; i < rows; i++) {
        printf("R%d  ", i);
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                printf("_ ");
            } else {
                printf("X ");
            }//endif
        }//NEXT j (endfor)
        printf("\n");
    }//NEXT i (endfor)

    //Seat Availability Report
    int total_free = 0;
    printf("\nFree seats per row: ");
    for (i = 0; i < rows; i++) {
        int row_free = 0;
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                row_free++;
            }//endif
        }//NEXT j (endfor)
        printf("%d ", row_free);
        total_free += row_free;
    }//NEXT i (endfor)
    printf("  Total free: %d\n", total_free);

    //Group Booking with Validation
    printf("\nEnter number of customers (k): ");
    scanf("%d", &k);

//Validate that group size is greater than 0 and doesn't exceed seats in a row
    while (k <= 0 || k > cols) {
        printf("Invalid group size! Must be between 1 and %d.\n", cols);
        printf("Re-enter number of customers (k): ");
        scanf("%d", &k);
    }//endwhile

    //Seat Allocation Rules 
    int mid = rows / 2;
    int found = 0;
    int booked_row = -1;
    int start_seat = -1;

    //Iterate by distance from the middle row
    for (dist = 0; dist <= rows && !found; dist++) {
        int rows_to_check[2];
        int num_to_check = 0;
        
        if (dist == 0) {
            rows_to_check[0] = mid;
            num_to_check = 1;
        } else {
            // Check smaller row number first if equally distant
            if (mid - dist >= 0) {
                rows_to_check[num_to_check++] = mid - dist; 
            }//endif
            if (mid + dist < rows) {
                rows_to_check[num_to_check++] = mid + dist;
            }//endif
        }//endif

        // Search the rows identified for this distance
        for (r_idx = 0; r_idx < num_to_check && !found; r_idx++) {
            int r = rows_to_check[r_idx];
            int consecutive = 0;
            
            for (c = 0; c < cols; c++) {
                if (matrix[r][c] == 0) {
                    consecutive++;
                    if (consecutive == k) {
                        found = 1;
                        booked_row = r;
                        // Calculate starting seat index based on the assignment hint
                        start_seat = c - k + 1; 
                        break;
                    }//endif
                } else {
                    consecutive = 0; // Reset counter when meeting a booked seat
                }//endif
            }//NEXT c (endfor)
        }//NEXT r_idx (endfor)
    }//NEXT dist (endfor)

    //Confirm Booking & Handle Unsuccessful Bookings
    if (found) {
        //Mark seats as booked
        for (i = 0; i < k; i++) {
            matrix[booked_row][start_seat + i] = 1;
        }//NEXT i (endfor)
        
        printf("\nGroup of %d seated in Row %d, Seats %d to %d\n", k, booked_row, start_seat, start_seat + k - 1);
        
        //Display updated seating arrangement
        printf("\n--- Updated Seating Arrangement ---\n");
        printf("    ");
        for (j = 0; j < cols; j++) {
            printf("%d ", j);
        }//NEXT j (endfor)
        printf("\n");
        for (i = 0; i < rows; i++) {
            printf("R%d  ", i);
            for (j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    printf("_ ");
                } else {
                    printf("X ");
                }//endif
            }//NEXT j (endfor)
            printf("\n");
        }//NEXT i (endfor)
        
        printf("\nRemaining available seats: %d\n", total_free - k);
        
    }else {
        printf("\nSorry, we could not find %d consecutive seats in any single row.\n", k);
    }//endif

    return 0;
}//end main
