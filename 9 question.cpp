#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Q 17 // Prime number
#define ALPHA 5  // Generator

// Function to calculate (base^exp) % modulus
int power(int base, int exp, int modulus) {
    int result = 1;
    base = base % modulus;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % modulus;
        exp = exp / 2;
        base = (base * base) % modulus;
    }
    return result;
}

int main() {
    int xa, xb, ya, yb, ka, kb;

    // Alice's private key
    xa = 4;
    // Bob's private key
    xb = 6;

    // Calculate Alice's public key
    ya = power(ALPHA, xa, Q);
    // Calculate Bob's public key
    yb = power(ALPHA, xb, Q);

    // Calculate shared key for Alice
    ka = power(yb, xa, Q);
    // Calculate shared key for Bob
    kb = power(ya, xb, Q);

    printf("Prime Number (Q): %d\n", Q);
    printf("Generator (Alpha): %d\n\n", ALPHA);

    printf("Alice's Private Key (xa): %d\n", xa);
    printf("Bob's Private Key (xb): %d\n\n", xb);

    printf("Alice's Public Key (ya): %d\n", ya);
    printf("Bob's Public Key (yb): %d\n\n", yb);

    printf("Shared Key for Alice (ka): %d\n", ka);
    printf("Shared Key for Bob (kb): %d\n", kb);

    return 0;
}
