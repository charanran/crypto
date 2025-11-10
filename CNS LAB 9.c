#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char key[50], matrix[5][5];
    int used[26]={0}, k=0;

    printf("Enter Keyword: ");
    scanf("%s", key);

    used['J'-'A'] = 1; // Treat I and J as same

    for(int i=0; key[i]; i++){
        char c = toupper(key[i]);
        if(c=='J') c='I';
        if(!used[c-'A']){
            used[c-'A']=1;
            matrix[k/5][k%5]=c;
            k++;
        }
    }

    for(char c='A'; c<='Z'; c++){
        if(!used[c-'A']){
            used[c-'A']=1;
            matrix[k/5][k%5]=c;
            k++;
        }
    }

    printf("\nPlayfair 5x5 Matrix:\n");
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }
}




