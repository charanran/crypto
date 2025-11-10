#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenere(char text[], char key[], int mode) {
    int keyLen = strlen(key);
    for (int i=0,j=0;text[i];i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i])?'A':'a';
            int k = toupper(key[j%keyLen]) - 'A';
            if (mode==1)
                text[i] = (text[i]-base + k)%26 + base;
            else
                text[i] = (text[i]-base - k + 26)%26 + base;
            j++;
        }
    }
}

int main(){
    char text[100], key[50];
    int choice;
    printf("Enter text: "); scanf(" %[^\n]", text);
    printf("Enter key: "); scanf("%s", key);
    printf("1. Encrypt\n2. Decrypt\nChoice: "); scanf("%d",&choice);
    vigenere(text,key,choice);
    printf("Result: %s\n", text);
}

