#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char text[], char key[]) {
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            int idx = toupper(text[i]) - 'A';
            text[i] = isupper(text[i]) ? toupper(key[idx]) : tolower(key[idx]);
        }
    }
}

void decrypt(char text[], char key[]) {
    char rev[26];
    for (int i = 0; i < 26; i++)
        rev[toupper(key[i]) - 'A'] = 'A' + i;
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            int idx = toupper(text[i]) - 'A';
            text[i] = isupper(text[i]) ? rev[idx] : tolower(rev[idx]);
        }
    }
}

int main() {
    char text[100], key[27];
    int choice;
    printf("Enter 26-letter key: ");
    scanf("%s", key);
    printf("Enter text: ");
    scanf(" %[^\n]", text);
    printf("1. Encrypt\n2. Decrypt\nChoice: ");
    scanf("%d", &choice);
    if (choice == 1) encrypt(text, key);
    else decrypt(text, key);
    printf("Result: %s\n", text);
}
