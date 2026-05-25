#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Encrypts a string using the Vigenère cipher.
 * Operates in-place for memory efficiency.
 *
 * @param text The null-terminated string to encrypt. It is possible to use Latin characters.
 * @param key  The null-terminated key string. Use the english alphabet only.
 * For enhanced security, change the secret key everyday,
 * or use a random sequence of letters, like "kqpyodrebcuaxzsln"
 */
void vigenere_encrypt(unsigned char* text, const char* key) {
    if (!text || !key || !*text || !*key) return;

    const char* key_ptr = key;

    for (; *text; text++) {
        unsigned char c = *text;

        // Handle Uppercase letters (A-Z)
        if (c >= 'A' && c <= 'Z') {
            // Determine key shift value (0-25) handling case insensitivity of key
            unsigned char k = (unsigned char)((*key_ptr >= 'a') ? *key_ptr - 'a' : *key_ptr - 'A');

            // Apply shift: (Char + Key) % 26
            *text = (unsigned char)(((c - 'A' + k) % 26) + 'A');

        advance_key:
            // Move key pointer, wrapping around if necessary
            key_ptr++;
            if (*key_ptr == '\0') key_ptr = key;
        }
        // Handle Lowercase letters (a-z)
        else if (c >= 'a' && c <= 'z') {
            unsigned char k = (unsigned char)((*key_ptr >= 'a') ? *key_ptr - 'a' : *key_ptr - 'A');

            // Apply shift
            *text = (unsigned char)(((c - 'a' + k) % 26) + 'a');

            goto advance_key;
        }
        // Non-alphabetic characters are ignored (key not advanced)
    }
}

/**
 * Decrypts a string encrypted with the Vigenère cipher.
 * Operates in-place.
 *
 * @param text The null-terminated string to decrypt.
 * @param key  The null-terminated key string.
 */
void vigenere_decrypt(unsigned char* text, const char* key) {
    if (!text || !key || !*text || !*key) return;

    const char* key_ptr = key;

    for (; *text; text++) {
        unsigned char c = *text;

        if (c >= 'A' && c <= 'Z') {
            unsigned char k = (unsigned char)((*key_ptr >= 'a') ? *key_ptr - 'a' : *key_ptr - 'A');

            // Reverse shift: (Char - Key + 26) % 26
            // We add 26 to ensure the result is positive before modulo
            *text = (unsigned char)((((c - 'A' - k) + 26) % 26) + 'A');

        advance_key:
            key_ptr++;
            if (*key_ptr == '\0') key_ptr = key;
        } else if (c >= 'a' && c <= 'z') {
            unsigned char k = (unsigned char)((*key_ptr >= 'a') ? *key_ptr - 'a' : *key_ptr - 'A');

            *text = (unsigned char)((((c - 'a' - k) + 26) % 26) + 'a');

            goto advance_key;
        }
    }
}

    /* --- Helper for CLI demonstration --- */
void print_usage(const char* prog_name) {
    fprintf(stderr, "Usage: %s [-e|-d] [-k key] \"text\"\n", prog_name);
    fprintf(stderr, "  -e Encrypt (default)\n");
    fprintf(stderr, "  -d Decrypt\n");
    fprintf(stderr, "  -k Key (required)\n");
}

int main(int argc, char* argv[]) {
    unsigned char mode = 0;  // 0 = encrypt, 1 = decrypt
    char* key = NULL;
    char* text = NULL;

    // Simple argument parsing
    if (argc < 4) {
        print_usage(argv[0]);
        return 1;
    }

    for (unsigned char i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-d") == 0){
            mode = 1;
        }
        else if (strcmp(argv[i], "-e") == 0){
            mode = 0;
        }
        else if (strcmp(argv[i], "-k") == 0){
            if (i + 1 < argc) key = argv[++i];
        } else {
            text = argv[i];
        }
    }

    if (!key || !text) {
        print_usage(argv[0]);
        return 1;
    }

    // Allocate a copy of text because we modify it in-place
    // (In a real high-performance scenario, you might pass a mutable buffer directly)
    char* buffer = strdup(text);
    if (!buffer) {
        perror("Memory allocation failed");
        return 1;
    }

    if (mode == 1) {
        vigenere_decrypt((unsigned char*)buffer, key);
        printf("Decrypted: %s\n", buffer);
    } else {
        vigenere_encrypt((unsigned char*)buffer, key);
        printf("Encrypted: %s\n", buffer);
    }

    free(buffer);
    return 0;
}