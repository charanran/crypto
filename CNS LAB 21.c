#include <stdio.h>
#include <string.h>

int main() {
    char text[100], key[100], result[100];
    int i;

    printf("Enter Text: ");
    scanf(" %[^\n]", text);
    printf("Enter Key (same length): ");
    scanf(" %[^\n]", key);

    if(strlen(text) != strlen(key)) {
        printf("Key and text must be same length!");
        return 0;
    }

    for(i = 0; text[i] != '\0'; i++)
        result[i] = text[i] ^ key[i]; // XOR

    result[i] = '\0';

    printf("\nEncrypted (XOR bytes): ");
    for(i = 0; result[i]; i++)
        printf("%d ", result[i]);

    return 0;
}

