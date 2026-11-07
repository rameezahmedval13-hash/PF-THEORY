/*=============================================================================
 * 
 * COURSE: Programming Fundamentals
 * SECTION: BDS-1A
 * Author: Rameez Ahmed , ROLL #: 26k-2527
 * 
 * FILE: Q4.c
 * DATE: 10/24/2026
 * DESCRIPTION:  
 *    Bakery Festival Sales Management System using arrays and custom functions.
 *    It validates festival days, processes daily order amounts, calculates 
 *    totals/averages, identifies the most profitable day, and outputs a 
 *    visual bar chart of the sales data.
 * 
 *=============================================================================*/

#include <stdio.h>

// Validates and returns the number of festival days (1-7)
int getValidDays() {
    int days;
    printf("Number of days: ");
    scanf("%d", &days);
    
    while (days < 1 || days > 7) {
        printf("Invalid input. Please enter a value between 1 and 7: ");
        scanf("%d", &days);
    }
    return days;
}

// Processes daily orders, prints stats, and returns the day's total sales
float calculateDailySales(int dayNumber) {
    int orders;
    float amount, total = 0.0, highest = 0.0;
    int i;
    
    printf("\nDay %d - Number of orders: ", dayNumber);
    scanf("%d", &orders);
    
    printf("Order amounts: ");
    for (i = 0; i < orders; i++) {
        scanf("%f", &amount);
        
        //Validate amount is greater than zero
        while (amount <= 0) {
            printf("Invalid amount entered. Please enter an amount greater than zero: ");
            scanf("%f", &amount);
        }
        
        total += amount;
        if (amount > highest) {
            highest = amount;
        }
    }
    
    float avg = total / orders;
    printf("\nTotal Sales: Rs. %.2f\n", total);
    printf("Average order: Rs. %.2f\n", avg);
    printf("Highest order: Rs. %.2f\n", highest);
    
    return total;
}

//Finds and returns the 1-based day number with the highest sales
int findHighestSalesDay(float dailySales[], int numberOfDays) {
    float max_sales = dailySales[0];
    int best_day_index = 0;
    int i;
    
    for (i = 1; i < numberOfDays; i++) {
        //Strict greater-than ensures the earliest day is kept if there's a tie
        if (dailySales[i] > max_sales) {
            max_sales = dailySales[i];
            best_day_index = i;
        }
    }
    
    return best_day_index + 1; // Return day number starting from 1
}

//Displays a bar chart using asterisks (1 asterisk per Rs. 100)
void displayBarChart(float dailySales[], int numberOfDays) {
	int i,j;
    printf("\n===== DAILY SALES BAR CHART =====\n");
    for (i = 0; i < numberOfDays; i++) {
        printf("Day %d: ", i + 1);
        
        //Integer division truncates the remainder automatically
        int asterisks = (int)(dailySales[i] / 100); 
        
        for (j = 0; j < asterisks; j++) {
            printf("*");
        }
        printf(" (Rs. %.2f)\n", dailySales[i]);
    }
}

//Additional requirements: Orchestrate in main()
int main() {
    int days = getValidDays();
    int i;
    
    //Use a 1D VLA to store total sales for each festival day
    float dailySales[days];
    float totalFestivalSales = 0.0;
    
    //Call calculation function for each day and populate the array
    for (i = 0; i < days; i++) {
        dailySales[i] = calculateDailySales(i + 1);
        totalFestivalSales += dailySales[i];
    }
    
    //Display Festival Summary
    int bestDay = findHighestSalesDay(dailySales, days);
    
    printf("\n===== FESTIVAL SUMMARY =====\n");
    printf("Total Festival Sales: Rs. %.2f\n", totalFestivalSales);
    printf("Day with highest sales: Day %d\n", bestDay);
    printf("Highest daily sales: Rs. %.2f\n", dailySales[bestDay - 1]);
    
    //Display Bar Chart
    displayBarChart(dailySales, days);
    
    return 0;
}
