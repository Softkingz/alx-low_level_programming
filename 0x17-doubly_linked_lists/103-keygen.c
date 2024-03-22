#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * generate_key - Generates a key based on the given username
 *
 * @username: The username to generate the key for
 * @length: The length of the username
 * Return: The generated key
 */
char *generate_key(char *username, int length) {
    static char keygen[7];
    int i;
    long alph[] = {
        0x3877445248432d41, 0x42394530534e6c37, 0x4d6e706762695432,
        0x74767a5835737956, 0x2b554c59634a474f, 0x71786636576a6d34,
        0x723161513346655a, 0x6b756f494b646850
    };

    // f1
    keygen[0] = ((char *)alph)[(length ^ 59) & 63];

    // f2
    int sum = 0;
    for (i = 0; i < length; i++)
        sum += username[i];
    keygen[1] = ((char *)alph)[(sum ^ 79) & 63];

    // f3
    int product = 1;
    for (i = 0; i < length; i++)
        product *= username[i];
    keygen[2] = ((char *)alph)[(product ^ 85) & 63];

    // f4
    srand(*username ^ 14);
    int rand_num = rand() & 63;
    keygen[3] = ((char *)alph)[rand_num];

    // f5
    sum = 0;
    for (i = 0; i < length; i++)
        sum += username[i] * username[i];
    keygen[4] = ((char *)alph)[(sum ^ 239) & 63];

    // f6
    rand_num = rand();
    for (i = 0; i < *username; i++)
        rand_num = rand();
    keygen[5] = ((char *)alph)[(rand_num ^ 229) & 63];

    keygen[6] = '\0';

    return keygen;
}

/**
 * main - Entry point
 *
 * @argc: Arguments count
 * @argv: Arguments vector
 * Return: Always 0
 */
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <username>\n", argv[0]);
        return 1;
    }

    char *username = argv[1];
    int length = 0;
    while (username[length])
        length++;

    char *key = generate_key(username, length);

    printf("%s\n", key);

    return 0;
}

