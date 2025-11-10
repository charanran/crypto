#include <stdio.h>
#include <string.h>

int main(){
    char text[100], rail[100][100];
    int key, i, j, len, dir=0, row=0;

    printf("Enter Text: ");
    scanf(" %[^\n]", text);
    printf("Enter Key (number of rails): ");
    scanf("%d", &key);

    len = strlen(text);
    for(i=0;i<key;i++)
        for(j=0;j<len;j++)
            rail[i][j] = '\n';

    for(i=0,j=0;j<len;j++){
        rail[row][j] = text[j];
        if(row==0) dir=1;
        else if(row==key-1) dir=0;
        row += dir?1:-1;
    }

    printf("Encrypted Text: ");
    for(i=0;i<key;i++)
        for(j=0;j<len;j++)
            if(rail[i][j] != '\n')
                printf("%c", rail[i][j]);
}
