#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char text[200], key[200];
    int choice;

    printf("Enter Text: ");
    scanf(" %[^\n]", text);
    printf("Enter Initial Key: ");
    scanf("%s", key);

    printf("1. Encrypt\n2. Decrypt\nChoice: ");
    scanf("%d", &choice);

    int len = strlen(text), klen = strlen(key);

    if(choice == 1){ // Encryption
        for(int i=0;i<len;i++){
            int t = toupper(text[i])-'A';
            int k = toupper(key[i])-'A';
            text[i] = (t+k)%26 + 'A';
            key[i+1] = text[i]; // Extend key
        }
    } 
    else { // Decryption
        for(int i=0;i<len;i++){
            int c = toupper(text[i])-'A';
            int k = toupper(key[i])-'A';
            int p = (c-k+26)%26;
            text[i] = p + 'A';
            key[i+1] = text[i]; // Extend key
        }
    }

    printf("Result: %s\n", text);
    return 0;
}


