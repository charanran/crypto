#include <stdio.h>
#include <string.h>

int main(){
    char cipher[200], key[20];
    int i, j, k=0, len, klen;

    printf("Enter Cipher Text: ");
    scanf(" %[^\n]", cipher);
    printf("Enter Key (e.g., 31452): ");
    scanf("%s", key);

    len = strlen(cipher);
    klen = strlen(key);

    char mat[20][20];

    for(int c=1;c<=klen;c++)
        for(int col=0;col<klen;col++)
            if(key[col]-'0' == c)
                for(int row=0;row<klen;row++)
                    mat[row][col] = cipher[k++];

    printf("\nDecrypted Text: ");
    for(i=0;i<klen;i++)
        for(j=0;j<klen;j++)
            printf("%c", mat[i][j]);
}

