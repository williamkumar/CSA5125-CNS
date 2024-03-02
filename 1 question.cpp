#include <stdio.h>

void caesar_cipher_encrypt(char message[], int key) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = 'a' + (message[i] - 'a' + key) % 26;
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = 'A' + (message[i] - 'A' + key) % 26;
        }
    }
}
void caesar_cipher_decrypt(char message[], int key) {
    caesar_cipher_encrypt(message, 26 - key);
}
int main() {
    char message[100];
    int key;
	printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter the key (an integer): ");
    scanf("%d", &key);
    caesar_cipher_encrypt(message, key);
    printf("Encrypted message: %s", message);
    caesar_cipher_decrypt(message, key);
    printf("Decrypted message: %s", message);
	return 0;
}
