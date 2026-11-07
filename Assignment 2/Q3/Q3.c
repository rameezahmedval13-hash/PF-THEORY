/*=============================================================================
 * 
 * COURSE: Programming Fundamentals
 * SECTION: BDS-1A
 * Author: Rameez Ahmed , ROLL #: 26k-2527
 * 
 * FILE: Q3.c
 * DATE: 10/24/2026
 * DESCRIPTION:  
 *    A Greenhouse Temperature Monitoring System that uses a 2D array and 
 *    modular user-defined functions to input data, analyze temperature 
 *    thresholds per sensor, and determine the sensor with the highest overall 
 *    average reading.
 * 
 *=============================================================================*/

#include <stdio.h>

// Input Function: Inputs readings into the 2D array
void inputReadings(int sensors, int readings, int matrix[sensors][readings]) {
	int i,j;
    for (i = 0; i < sensors; i++) {
        printf("Sensor %d: ", i + 1);
        for (j = 0; j < readings; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Sensor Analysis Function: Receives a 1D array representing one sensor
void analyzeSensor(int sensorNum, int readingsCount, int sensorRow[]) {
    int total = 0;
    int max = sensorRow[0];
    int min = sensorRow[0];
    int critical = 0;
    int warning = 0;
    int current_streak = 0;
    int max_streak = 0;
    int j;

    for (j = 0; j < readingsCount; j++) {
        int temp = sensorRow[j];
        total += temp;

        if (temp > max) max = temp;
        if (temp < min) min = temp;

        if (temp >= 40) {
            critical++;
        }
        if (temp >= 35 && temp <= 39) {
            warning++;
        }

        // Calculate consecutive streak of 35C or above
        if (temp >= 35) {
            current_streak++;
            if (current_streak > max_streak) {
                max_streak = current_streak;
            }
        } else {
            current_streak = 0; // Reset streak if below 35
        }
    }

    float avg = (float)total / readingsCount;

    // Individual Reports: Display formatting matches the sample output exactly
    printf("Sensor %d: Total=%d  Avg=%.2f  Max=%d  Min=%d\n", sensorNum, total, avg, max, min);
    printf("           Critical=%d  Warning=%d  Longest hot streak=%d\n", critical, warning, max_streak);
}

// Highest Average Function: Determines and returns the sensor number with highest avg
int findHighestAverage(int sensors, int readings, int matrix[sensors][readings]) {
    float highest_avg = -1.0;
    int best_sensor = 1;
    int i,j;

    for (i = 0; i < sensors; i++) {
        int total = 0;
        for (j = 0; j < readings; j++) {
            total += matrix[i][j];
        }
        float avg = (float)total / readings;

        if (avg > highest_avg) {
            highest_avg = avg;
            best_sensor = i + 1; // 1-based indexing for display
        }
    }
    
    return best_sensor;
}

int main() {
    int sensors, readings;
	int i,j;
    // Input Data (Dimensions)
    printf("Enter number of sensors: ");
    scanf("%d", &sensors);
    printf("Enter number of hourly readings per sensor: ");
    scanf("%d", &readings);

    // VLA 2D Array declaration based on user input
    int matrix[sensors][readings];

    printf("\nEnter readings (space separated):\n");
    inputReadings(sensors, readings, matrix);

    printf("\nSample output:\n");
    
    // Process and print individual reports
    for (i = 0; i < sensors; i++) {
        // Passing matrix[i] passes a 1D array (the specific row) to the function
        analyzeSensor(i + 1, readings, matrix[i]);
    }

    // Final Report
    int best_sensor = findHighestAverage(sensors, readings, matrix);

    // Calculate the exact average of the winning sensor to display in the final report
    int best_total = 0;
    for (j = 0; j < readings; j++) {
        best_total += matrix[best_sensor - 1][j];
    }
    float best_avg = (float)best_total / readings;

    printf("\nHighest average: Sensor %d (%.2f)\n", best_sensor, best_avg);

    return 0;
}
