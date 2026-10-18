/*
 * ============================================================================
 * File Name    : Q4.c
 * Author       : Rameez Ahmed
 * Date Created : 10/18/2026
 * Course       : Programming Fundamentals Theory (CS1002)
 * Lab / Task   : Assignment 1 Part B
 * ============================================================================
 */
 
 #include <stdio.h>

int main(){
    int q;
    float p, d, t;
    float s = 0.0, a = 0.0, f = 0.0;
    
    printf("Enter quantity, price per item, discount %%, tax %%: ");
    scanf("%d %f %f %f", &q, &p, &d, &t);
    
    //Input validation
    if (q <= 0 || p < 0 || d < 0 || t < 0) {
        printf("Error: Invalid Input\n");
    } else {
       
        s = q * p;
        a = s - (s * d / 100.0);
        f = a + (a * t / 100.0);
        
        //Bill document generation
        printf("\n--- Bill Document ---\n");
        printf("Subtotal: %.2f\n", s);
        printf("Discounted Amount: %.2f\n", a);
        printf("Final Bill: %.2f\n", f);
    }
    
    return 0;
}
