#include <stdio.h>
#include <string.h>

void transpose(char text[], char key[]){
    int len = strlen(text), klen = strlen(key), idx=0;
    char mat[20][20], out[400];
    for(int i=0;i<klen;i++)
        for(int j=0;j<klen;j++)
            mat[i][j] = (idx<len)?text[idx++]:'X';

    idx=0;
    for(int c=1;c<=klen;c++)
        for(int col=0;col<klen;col++)
            if(key[col]-'0' == c)
                for(int r=0;r<klen;r++)
                    out[idx++] = mat[r][col];

    out[idx]='\0';
    strcpy(text,out);
}

int main(){
    char text[200], key1[10], key2[10];
    printf("Enter Text: ");
    scanf(" %[^\n]", text);
    printf("Enter Row Key: ");
    scanf("%s", key1);
    printf("Enter Column Key: ");
    scanf("%s", key2);

    transpose(text,key1);
    transpose(text,key2);

    printf("\nDouble Transposition Encrypted: %s\n", text);
}
