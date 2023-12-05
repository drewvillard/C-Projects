// Assignment #2 - Starter Files
/*
* Created by drew on 2022-10-19.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/leapyear.h"

int main() {
    // YOUR CODE HERE - DO NOT FORGET TO CREATE SOURCE AND HEADER FILES FOR LEAP YEAR FUNCTION
    //array to handle user input
    char input[64];

    //variable for entered year
    int  year=0;

    //isdigit object verifies if char is a digit
    int isdigit(int value);

    //double used to verify an integer was entered (by casting to int and comparing)
    double asDouble;

    //while loop/leapyear operation variable
    int num=1;

    //counter variable used to iterate through entirety of boolTable
    int counter=1;

    //constant for number of years in each century
    const int YEARS_PER_CENTURY=100;

    //number of current centuries
    const int NUM_OF_CENTURIES=20;

    //number of current years
    const int NUM_OF_YEARS= YEARS_PER_CENTURY*NUM_OF_CENTURIES+22;

    //boolean table for leap years
    int boolTable [NUM_OF_YEARS];

    //program header
    printf("Leap Checker!");

    /*do-while loop takes user input and uses strcmp to return true or false.
     * If the user inputs 'N' the leap year input loop ends. */
        do{
            printf("\n\nPlease enter the year to check ('N' to quit):");
            scanf(" %s",input);
            int num = strcmp(input,"N");
            asDouble = atof(input);

    /*else if checks is asDouble = itself as an int, for instance (1.1 = 1)
    * and if asDouble is greater than 0 and less than 9999*/
            if (num==0) {
                printf("Quitting..\n");
                break;
            }else if (asDouble == (int) asDouble && asDouble > 0 && asDouble < 9999) {
                year = (int) asDouble;
                if(leapYearChecker(year)==0){
                    printf("%i IS a leap year!",year);
                }else if(leapYearChecker(year)==1){
                    printf("%i IS NOT a leap year!",year);
                }
            } else {
                printf(" Sorry that input is invalid..");
            }
        }while(num!=0);

    printf("\nTHE LEAP YEARS PER CENTURY REPORT:\n");

    //for loop inserts 0, or 1 in an array. 0 meaning the year checked is a leap year 1 meaning its not
        for (int i = 0; i <= NUM_OF_CENTURIES; i++) {
            printf("\nCentury #%i:", i + 1);
            for (int x = 0; x < YEARS_PER_CENTURY; x++) {
                boolTable[counter] = leapYearChecker(counter);
                if (boolTable[counter] == 0) {
                    printf(" %2i ", counter);
                } else if(counter>2022){
                    break;
                }
                counter += 1;
            }
        }

    return 0;
}
