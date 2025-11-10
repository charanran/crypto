#include <stdio.h>
#include <string.h>

int main(){
    char text[100], key[10];
    int i, j, len, klen;

    printf("Enter Text: ");
    scanf(" %[^\n]", text);
    printf("Enter Key (e.g., 3142): ");
    scanf("%s", key);

    len = strlen(text);
    klen = strlen(key);

    char mat[10][10]; int idx = 0;

    for(i=0;i<klen;i++)
        for(j=0;j<klen;j++)
            mat[i][j] = (idx < len) ? text[idx++] : 'X';

    printf("\nEncrypted: ");
    for(int c=1;c<=klen;c++)
        for(int col=0; col<klen; col++)
            if(key[col]-'0' == c)
                for(int r=0;r<klen;r++)
                    printf("%c", mat[r][col]);

    return 0;
}
