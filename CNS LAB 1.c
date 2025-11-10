#include <stdio.h>
#include <ctype.h>
#include <string.h>

void caesarCipher(char text[], int key, int mode) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            if (mode == 1) // Encrypt
                ch = (ch - base + key) % 26 + base;
            else           // Decrypt
                ch = (ch - base - key + 26) % 26 + base;
        }
        text[i] = ch;
    }
}

int main() {
    char text[100];
    int key, choice;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    printf("Enter key (1–25): ");
    scanf("%d", &key);
    printf("1. Encrypt\n2. Decrypt\nChoose: ");
    scanf("%d", &choice);

    caesarCipher(text, key, choice);
    printf("Result: %s\n", text);
    return 0;
}
