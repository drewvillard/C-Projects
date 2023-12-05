//
// Created by drew on 2022-11-23.
//

#ifndef ASSIGN4_CRYPT_H
#define ASSIGN4_CRYPT_H
//constant array size
#define ARRAY_SIZE  256
//constant encryption bitmask
#define MASK 0xa5
//en and de-cryption macro used for bitwise XOR
#define CRYPTION(number)(number^MASK)

//starting map
static const char START_CIPHER[] = {'0','1','2','3','4','5','6','7','8','9','A',
                             'B','C','D','E','F','G','H','I','J','K',
                             'L','M','N','O','P','Q','R','S','T','U',
                             'V','W','X','Y','Z','!','@','#','$','%',
                             '^','&','*','(',')',':',';','?','.',',',
                             '/',' '};
//sub-map
static const char SUB_CIPHER[] = {':', ';', '?', '.', ',', '/', '0','1','2','3',
                           '4', '5', '6', '7', '8', '9', 'A', 'B', 'C',
                           'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                           'M', 'N','O', 'P','Q', 'R', 'S', 'T', 'U',
                           'V', 'W','X', 'Y', 'Z', '!', '@', '#', '$','%'
        ,'^', '&', '*', '(', ')', ' '};

enum direction{
    ENCRYPTING,
    DECRYPTING
};
//prototype declaration of encrypt and decrypt functions
void encrypt(char[]);
void decrypt(char[]);
#endif //ASSIGN4_CRYPT_H
