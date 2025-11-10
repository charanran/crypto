#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char text[100], key[100];
    int choice;

    printf("Enter Text: ");
    scanf(" %[^\n]", text);
    printf("Enter Key (Same Length): ");
    scanf(" %[^\n]", key);

    printf("1. Encrypt\n2. Decrypt\nChoose: ");
    scanf("%d",&choice);

    for(int i=0; text[i]; i++){
        if(isalpha(text[i])){
            char base = isupper(text[i]) ? 'A' : 'a';
            int t = toupper(text[i]) - 'A';
            int k = toupper(key[i]) - 'A';
            int r = (choice==1) ? (t+k)%26 : (t-k+26)%26;
            text[i] = r + base;
        }
    }

    printf("\nResult: %s\n", text);
    return 0;
}

