#include <stdio.h>
#include <ctype.h>

int modInverse(int a){
    for(int i=1;i<26;i++) if((a*i)%26==1) return i;
    return -1;
}

void decryptAffine(char text[], int a, int b){
    int inv = modInverse(a);
    if(inv == -1) return;
    for(int i=0;text[i];i++){
        if(isalpha(text[i])){
            char base = isupper(text[i]) ? 'A' : 'a';
            int x = text[i] - base;
            text[i] = (inv * (x - b + 26)) % 26 + base;
        }
    }
}

int main(){
    char cipher[100];
    printf("Enter Cipher Text: ");
    scanf(" %[^\n]", cipher);

    printf("\nTrying all possible keys...\n");
    for(int a=1;a<26;a++){
        int inv = modInverse(a);
        if(inv == -1) continue;
        for(int b=0;b<26;b++){
            char temp[100];
            for(int i=0;i<=100;i++) temp[i] = cipher[i];
            decryptAffine(temp, a, b);
            printf("a=%d, b=%d → %s\n", a, b, temp);
        }
    }
    return 0;
}


