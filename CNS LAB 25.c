#include <stdio.h>
#include <string.h>

int main(){
    char cipher[100], rail[100][100];
    int key, len, i,j,dir,row;

    printf("Enter Cipher Text: ");
    scanf(" %[^\n]", cipher);

    printf("Enter Key (No. of Rails): ");
    scanf("%d", &key);

    len = strlen(cipher);
    for(i=0;i<key;i++)
        for(j=0;j<len;j++)
            rail[i][j]='\n';

    dir = 0; row = 0;
    for(i=0,j=0;j<len;j++){
        rail[row][j]='*';
        if(row==0) dir=1;
        else if(row==key-1) dir=0;
        row += dir?1:-1;
    }

    int index=0;
    for(i=0;i<key;i++)
        for(j=0;j<len;j++)
            if(rail[i][j]=='*')
                rail[i][j]=cipher[index++];

    printf("\nDecrypted Text: ");
    dir=0; row=0;
    for(i=0,j=0;j<len;j++){
        printf("%c", rail[row][j]);
        if(row==0) dir=1;
        else if(row==key-1) dir=0;
        row += dir?1:-1;
    }
}

