#include <stdio.h>
#include <string.h>

int main(){
    char cipher[200], key[20];
    int klen, len, i,j,k=0;

    printf("Enter Cipher Text: ");
    scanf(" %[^\n]", cipher);

    printf("Enter Key (e.g., 3142): ");
    scanf("%s", key);

    klen = strlen(key);
    len = strlen(cipher);

    char mat[20][20];

    for(int c=1; c<=klen; c++)
        for(int col=0; col<klen; col++)
            if(key[col]-'0' == c)
                for(int row=0; row<klen; row++)
                    mat[row][col] = cipher[k++];

    printf("\nDecrypted: ");
    for(i=0;i<klen;i++)
        for(j=0;j<klen;j++)
            printf("%c", mat[i][j]);

    return 0;
}

