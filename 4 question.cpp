#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenere_encrypt(char *message, const char *key) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < messageLength; ++i, ++j) {
        if (j == keyLength)
            j = 0;
        message[i] = ((toupper(message[i]) + toupper(key[j])) % 26) + 'A';
    }
}

void vigenere_decrypt(char *message, const char *key) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < messageLength; ++i, ++j) {
        if (j == keyLength)
            j = 0;
        message[i] = (((toupper(message[i]) - toupper(key[j])) + 26) % 26) + 'A';
    }
}

int main() {
    char message[1000];
    char key[100];
    char choice;

    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter 'E' for encryption or 'D' for decryption: ");
    scanf(" %c", &choice);

    if (toupper(choice) == 'E') {
        vigenere_encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    } else if (toupper(choice) == 'D') {
        vigenere_decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
