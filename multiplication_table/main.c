#include <stdio.h>

/* Author - Drew Villard W0468787
 * Date - 02-10-2022
 * This program prints a product table of 'n' size and
 * then a second product table in reverse order*/

int main() {
    int n = 10;
    int reversedRows = n;
    int reversedColumns = n;

    //print table header and top left N character
    printf("TABLE OF PRODUCTS\n\n%4c", 'N');

    //for loop prints column headers
    for (int columns = 1; columns <= n; columns++) {
        printf("%4i", columns);
    }
    putchar('\n');

    //for loop idx prints row "headers" and nested jdx for loop prints bulk of the multiplication table
    for (int idx = 1; idx <= n; idx++) {
        printf("%4i", idx);

        for (int jdx = 1; jdx <= n; jdx++) {
            printf("%4i", jdx * idx);
        }
        putchar('\n');
    }
    putchar('\n');

    //top left "N" header for rows and columns and table header
    printf("REVERSED TABLE OF PRODUCTS \n\n%4c", 'N');

    //for loop prints column headers
    for (int columns = n; columns > 0; columns--) {
        printf("%4d", columns);
    }
    putchar('\n');

    //while loop prints reversedRows prints the row "header" and resets
    while (reversedRows > 0) {
        printf("%4i", reversedRows);
        while (reversedColumns > 0) {
            printf("%4i", reversedRows * reversedColumns);
            reversedColumns--;
        }
        putchar('\n');
        reversedColumns = n;
        reversedRows--;
    }
    return 0;
}