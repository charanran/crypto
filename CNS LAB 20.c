#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char text[], char key[]){
    int j=0, klen=strlen(key);
    for(int i=0;text[i];i++){
        if(isalpha(text[i])){
            if(j>=klen) key[j] = text[i-1];
            char base='A';
            int t = toupper(text[i])-'A';
            int k = toupper(key[j])-'A';
            text[i] = (t+k)%26 + base;
            j++;
        }
    }
}

void decrypt(char text[], char key[]){
    int j=0, klen=strlen(key);
    for(int i=0;text[i];i++){
        if(isalpha(text[i])){
            char base='A';
            int c = toupper(text[i])-'A';
            int k = toupper(key[j])-'A';
            int p = (c-k+26)%26;
            text[i] = p + base;
            key[klen++] = text[i];
            j++;
        }
    }
}

int main(){
    char text[200], key[200];
    int choice;
    printf("Enter Text: ");
    scanf(" %[^\n]", text);
    printf("Enter Key: ");
    scanf("%s", key);
    printf("1. Encrypt\n2. Decrypt\nChoose: ");
    scanf("%d", &choice);
    if(choice==1) encrypt(text,key);
    else decrypt(text,key);
    printf("Result: %s\n", text);
}
