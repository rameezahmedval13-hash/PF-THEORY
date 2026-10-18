/*
 * ============================================================================
 * File Name    : Q6.c
 * Author       : Rameez Ahmed
 * Date Created : 10/18/2026
 * Course       : Programming Fundamentals Theory (CS1002)
 * Lab / Task   : Assignment 1 Part B
 * ============================================================================
 */


#include <stdio.h>
#include <string.h>

int main() {
    char vehicle_type, is_member, is_disabled, station_avail;
    int soc, req_level, duration, time;
    
    float req_charging = 0.0, rate = 0.0, base_charging_cost = 0.0, charging_disc = 0.0;
    float base_parking_cost = 0.0, parking_disc = 0.0, final_payable = 0.0;
    
    char priority[50] = "Normal Charging";
    char time_status[20] = "Off-Peak";
    char warning[100] = "Standard parking duration.";
    
    printf("Enter vehicle type (E for Electric, H for Hybrid): ");
    scanf(" %c", &vehicle_type);
    
    printf("Enter Current Battery Level (SOC (%%)): ");
    scanf("%d", &soc);
    
    printf("Enter required charging level (%%): ");
    scanf("%d", &req_level);
    
    printf("Enter Expected parking duration (hours): ");
    scanf("%d", &duration);
    
    printf("Enter Current Time (24 hour format): ");
    scanf("%d", &time);
    
    printf("Is customer a Member (Y/N): ");
    scanf(" %c", &is_member);
    
    printf("Has Disabled-Person Priority? (Y/N): ");
    scanf(" %c", &is_disabled);
    
    printf("Is Charging Station Available? (Y/N): ");
    scanf(" %c", &station_avail);
    
    //Parking Cost Calculation based on duration
    if (duration <= 2) {
        base_parking_cost = 200.0;
    } else if (duration > 2 && duration <= 5) {
        base_parking_cost = 400.0;
    } else {
        base_parking_cost = 700.0;
    }
    
    //Station Availability & Qualification Check
    if (station_avail == 'N') {
        if (vehicle_type == 'H') {
            printf("\nCharging unavailable - Parking only\n");
        } else {
            printf("\nNo charging slot available\n");
        }
    } 
    else if (vehicle_type == 'H' && soc >= 40) {
        printf("\nVehicle does not qualify for EV charging\n");
    } 
    else {
        req_charging = req_level - soc;
        
        if (req_charging <= 0) {
            printf("\nNo charging required\n");
        } 
        else {
            //Priority determination
            if (soc <= 15 && req_level >= 80) {
                strcpy(priority, "Emergency Charging Priority");
            } 
            else if ((is_disabled == 'Y' || is_member == 'Y') && soc <= 30) {
                strcpy(priority, "Priority Charging");
            } 
            else {
                strcpy(priority, "Normal Charging");
            }
            
            //Time status and rate determination
            if (time >= 17 && time <= 22) {
                strcpy(time_status, "Peak");
                rate = 50.0;
            } else {
                strcpy(time_status, "Off-Peak");
                rate = 35.0;
            }
            
            base_charging_cost = req_charging * rate;
            
            //Charging Discount Rules
            if (strcmp(priority, "Emergency Charging Priority") == 0) {
                charging_disc = 0.0;
            } 
            else if (is_member == 'Y') {
                if (strcmp(time_status, "Off-Peak") == 0) {
                    charging_disc = base_charging_cost * 0.20;
                } else {
                    charging_disc = base_charging_cost * 0.10;
                }
            }
        }
    }
    
    //Parking Discount Rules
    if (is_disabled == 'Y') {
        parking_disc = base_parking_cost; // Free parking for disabled-person priority
    } 
    else if (is_member == 'Y') {
        parking_disc = base_parking_cost * 0.20;
    } 
    else {
        parking_disc = 0.0;
    }
    
    final_payable = (base_charging_cost - charging_disc) + (base_parking_cost - parking_disc);
    
    //Long-stay warning 
    if (duration > 8) {
        strcpy(warning, "Long stay warning: Please relocate your vehicle after charging");
    } else {
        strcpy(warning, "Standard parking duration");
    }
    
    //Final Summary Bill Document
    printf("\n========================================\n");
    printf("     -- SMART EV SYSTEM BILL SUMMARY -- \n");
    printf("========================================\n");
    printf("Vehicle Type: %c\n", vehicle_type);
    printf("Current SOC: %d%% | Required: %d%%\n", soc, req_level);
    printf("Priority: %s\n", priority);
    printf("Time Status: %s\n", time_status);
    printf("Charging Cost: Rs. %.2f\n", (base_charging_cost - charging_disc));
    printf("Parking Cost: Rs. %.2f\n", (base_parking_cost - parking_disc));
    printf("Total Discount: Rs. %.2f\n", (charging_disc + parking_disc));
    printf("Final Payable Amount: Rs. %.2f\n", final_payable);
    printf("Message: %s\n", warning);
    printf("========================================\n");
    
    return 0;
}
