#include <stdio.h>
#include <ctype.h>
#include <string.h>

int mod26(int x){ return (x%26+26)%26; }

int main(){
    char text[100];
    int a,b,c,d;
    printf("Enter Plaintext: ");
    scanf(" %[^\n]", text);
    printf("Enter 2x2 key matrix (a b c d): ");
    scanf("%d %d %d %d", &a,&b,&c,&d);

    printf("Ciphertext: ");
    for(int i=0; text[i]; i+=2){
        char x = toupper(text[i])-'A';
        char y = isalpha(text[i+1]) ? toupper(text[i+1])-'A' : 'X'-'A';
        int c1 = mod26(a*x + b*y) + 'A';
        int c2 = mod26(c*x + d*y) + 'A';
        printf("%c%c", c1, c2);
    }
    return 0;
}




