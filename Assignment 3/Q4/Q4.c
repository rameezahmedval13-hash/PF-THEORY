/*
 * ============================================================================
 * File Name    : Q4.c
 * Author       : Rameez Ahmed
 * Date Created : 11/24/2026
 * Course       : Programming Fundamentals Theory (CS1002)
 * Lab / Task   : Assignment 3
 * ============================================================================
 */
 
#include <stdio.h>

int main(){
	int n;
	int o;
	
	printf("Enter a number (n): \n");
	scanf("%d", &n);
	//validation 
	while(n%2 == 0){
		printf("Error: Enter a odd number (n): \n");
		scanf("%d", &n);
	}//endwhile
	
	//main loop for upper half
	int rows;
	for(rows = 1; rows <= n; rows++){
		//loop for outer spaces
		if(rows == 1){
			
			for(o = (2*n)-2; o>0; o--){
				printf(" "); //first outerspace 
			}
			printf("*"); //only one star in first row
			printf("\n"); // new line after printing the star
			o = (2*n) -2; // storing the starting number of outerspaces of upper half so that if row is not 1 it can decrement by 2 and the next time it would take the decremented value and decrement it again by 2
		}
		else{
			
			o = o-2; // decrementing no of outerspaces by 2 for every row after the starting row (1)
			int i; 
			for(i = o; i>0; i--){ 
				printf(" "); // printing outerspaces for rows > 1
			}//endfor
			printf("*"); //placing the first star of those rows after inner space
			
			// loop for inner spaces of upper half
			for(i = 1; i<=4*(rows-1) - 1;i++){
				printf(" "); // printing inner spaces
			}//endfor
		
			printf("*"); //printing the second star in the row
			printf("\n"); //sending to new line after the 2 stars are printed for every row
		}
		
	}//end of upper part 
	
	//main loop for lower half
	for(rows = 1; rows<=n-1;rows++){
		int r;
		int i, start;
		if (rows < n-1){ //checking if last row not reached
			//printing outerspaces
			for(r = 1; r<=rows;r++){
				printf(" ");
			}
			printf("*");//printing first star after outer spaces
			
			start = 4*(n-1) - 1; //the middle horizontal line's inner spaces (max inner space for lower half)
			//loop for inner spaces
			for(i = 1; i <= start - 2*(rows) ; i++){
				printf(" ");
			}
			printf("*"); //printing second star
			printf("\n");//moving to next line
		}else{ // if last row is reached
			//print the outerspaces
			for(r = 1; r<=rows;r++){
			printf(" ");
			}
			
			int stars = n; // number of stars on bottom base
			int s;
			for(s=1; s<=stars; s++){
				printf("*");
				if(s<stars){ // checking if the number of stars printed are less than 5 as we do not need to print an extra space after the 5th star.
					printf(" "); //single space b/w each star
				}
			}
			printf("\n"); // moves to next line

		}

	}//end of main for loop of lower part
	
	return 0;
}
