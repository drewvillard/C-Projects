#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../inc/crypt.h"

int main() {
    setbuf(stdout, 0);
    char input[ARRAY_SIZE];
    int choice = 0;
//    printf("What operation would you like to perform (1 -Encrypt, 2 Decrypt)?\n\n");
    scanf("%i", &choice);
    if (choice == 1) {
        ENCRYPTING;
//        printf("\nSo, you want to encrypt the message!");
//        printf("\nPlease Enter your message:");
        //scan in line
        scanf(" %[^'\n']s", input);

        int len= strlen(input);
        //for loop capitalizes input
        for(int i=0;i<len;i++){
            input[i]= toupper(input[i]);
        }
        encrypt(input);
    } else if (choice == 2) {
        DECRYPTING;
        printf("\n\nSo, you want to decrypt the message!");
        printf("\nPlease Enter your message:");
        scanf(" %[^'\n']s", input);
        decrypt(input);

    }else{
        printf("\nSo, you do not know what you want!");
        return 1;
    }
    return 0;
}
