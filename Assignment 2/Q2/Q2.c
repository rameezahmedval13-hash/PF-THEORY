/*=============================================================================
 * 
 * COURSE: Programming Fundamentals
 * SECTION: BDS-1A
 * Author: Rameez Ahmed , ROLL #: 26k-2527
 * 
 * FILE: Q2.c
 * DATE: 10/24/2026
 * DESCRIPTION:  
 *    Identifies and prints all amicable pairs up to a user-defined limit.
 *    Utilizes a dedicated function to calculate the sum of proper divisors
 *    and filters out perfect numbers while ensuring the smaller number 
 *    in the pair is always displayed first.
 * 
 *=============================================================================*/

#include <stdio.h>

// Function to calculate the sum of proper divisors
int sumOfDivisors(int num) {
    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int n;
    int count = 0;

    printf("Enter upper limit (n): ");
    scanf("%d", &n);

    printf("Amicable pairs up to %d:\n", n);

    for (int a = 1; a <= n; a++) {
        int b = sumOfDivisors(a);

        /* 
         * b > a: Ensures we print smaller number first, avoids printing duplicates, 
         *        and inherently prevents perfect numbers (like 6 and 28) from triggering.
         * b <= n: Ensures both numbers in the pair are less than or equal to n.
         */
        if (b > a && b <= n) {
            if (sumOfDivisors(b) == a) {
                printf("(%d, %d)\n", a, b);
                count++;
            }
        }
    }

    //Display total pairs or a suitable message if none found
    if (count == 0) {
        printf("No amicable pairs found.\n");
    } else {
        printf("Total pairs: %d\n", count);
    }

    return 0;
}
