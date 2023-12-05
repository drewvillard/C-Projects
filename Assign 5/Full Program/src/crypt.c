//
// Created by drew on 2022-11-23.
//

#include "../inc/crypt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**Encrypt function takes user input and substitutes characters for those in the sub Cipher it then casts that character
 * as an int and then uses that int to  perform bitwise XOR with our defined mask 0xa5 and that gives us a 3 digit
 * integer for each character.*/
void encrypt(char *input) {
    //array to store the casted input
    unsigned int subArray[ARRAY_SIZE];
    //array to store the result of the bitwise XOR between inputs and mask
    unsigned int results[ARRAY_SIZE];
    //length of input string as len
    int len = strlen(input);
    //for loop replaces inputs with sub cipher equivalent
    for (int i = 0; i < len; i++) {
        for (int c = 0; c < sizeof START_CIPHER; c++) {
            if (input[i] == START_CIPHER[c]) {
                input[i] = SUB_CIPHER[c];
            }
        }
    }
    //for loop casts input as int and saves in alternative array
    for (int i = 0; i < len; i++) {
        subArray[i] = (int) input[i];
    }

    //printf("The encrypted message is \n");
    //for loop performs the universal "cryption" macro which is just bitwise XOR
    for (int x = 0; x < len; x++) {
        results[x] = CRYPTION(subArray[x]);
    }
    //prints encrypted message
    printf("\'%3i",results[0]);
    for (int i = 1; i < len; i++) {
        printf("%4i", results[i]);
    }
    putchar('\'');
}
/**Decrypt function takes in string of ints (representing individual letters) and groups by spaces while changing
 * it to an integer then it casts it to a character and matches it with the Sub cipher to be replaced by the original
 * in the Starting cipher and finally printed as entire words*/
void decrypt(char *toDec) {
    unsigned int messageAsInt[ARRAY_SIZE];
    char decrypted[ARRAY_SIZE];
    int len = strlen(toDec);
    char *stringSplitter = strtok(toDec, " ");
    int p = 0;

    /**while loop uses token to segment string and loop through it while performing bitwise
     XOR on each segment and storing in array */
    while (stringSplitter != NULL) {
        messageAsInt[p] = CRYPTION(atoi(stringSplitter));
        stringSplitter = strtok(NULL, " ");
        p++;
    }
    p = 0;
    //for loop casts previous array as a character into alternative array
    for (int i = 0; i < len; i++) {
        decrypted[i] = (char) messageAsInt[i];
    }
    /**nested loop goes through entire sub cipher table and compares each character to each element in the table
     * then on matching instances it replaces that character with the corresponding starting character thereby
     * decrypting it*/
    for (int i = 0; i < len; i++) {
        for (int x = 0; x < sizeof SUB_CIPHER; x++) {
            if (decrypted[i] == SUB_CIPHER[x]) {
                decrypted[i] = START_CIPHER[x];
                break;
            }
        }
    }
    char *decryptSplit = strtok(decrypted, " ");
    //for loop uses token to separate array and print individual words
    for (int i = 0; i < len; i++) {
        printf("%s ", decryptSplit);
        decryptSplit = strtok(NULL, " ");
        if(decryptSplit==NULL){
            break;
        }
    }

}
