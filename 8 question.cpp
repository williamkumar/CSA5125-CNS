#include <stdio.h>

// Function to calculate gcd of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate modular inverse
int mod_inverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return 1;
}

int main() {
    int p = 5; // prime number
    int q = 11; // prime number
    int n, phi, e, d;

    // Calculate n
    n = p * q;
    // Calculate Phi(n)
    phi = (p - 1) * (q - 1);

    // Choose a suitable value for e such that 1 < e < f(n) and gcd(e, f(n)) = 1
    for (e = 27; e < phi; e++) {
        if (gcd(e, phi) == 1)
            break;
    }

    // Calculate d (modular multiplicative inverse of e modulo phi)
    d = mod_inverse(e, phi);

    printf("p = %d\n", p);
    printf("q = %d\n", q);
    printf("n = %d\n", n);
    printf("Phi(n) = %d\n", phi);
    printf("Encryption Exponent (e) = %d\n", e);
    printf("Decryption Exponent (d) = %d\n", d);

    return 0;
}
