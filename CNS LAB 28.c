#include <stdio.h>
#include <ctype.h>
#include <string.h>

int mod26(int x){ return (x%26+26)%26; }

int main(){
    char text[100];
    int key[3][3];

    printf("Enter Plaintext: ");
    scanf(" %[^\n]", text);

    printf("Enter 3x3 Key Matrix:\n");
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            scanf("%d", &key[i][j]);

    printf("Ciphertext: ");

    for(int i=0; text[i]; i+=3){
        int p[3] = {0,0,0};
        for(int j=0;j<3;j++)
            p[j] = (isalpha(text[i+j]) ? toupper(text[i+j]) - 'A' : 23);

        for(int r=0;r<3;r++){
            int sum = 0;
            for(int c=0;c<3;c++)
                sum += key[r][c] * p[c];
            printf("%c", mod26(sum) + 'A');
        }
    }
}
