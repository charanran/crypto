#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keySquare[5][5];

void generateKey(char key[]){
    int used[26]={0}, k=0;
    used['J'-'A']=1;

    for(int i=0; key[i]; i++){
        char c = toupper(key[i]);
        if(c=='J') c='I';
        if(!used[c-'A']){
            used[c-'A']=1;
            keySquare[k/5][k%5]=c;
            k++;
        }
    }

    for(char c='A'; c<='Z'; c++){
        if(!used[c-'A']){
            used[c-'A']=1;
            keySquare[k/5][k%5]=c;
            k++;
        }
    }
}

void findPos(char c, int* r, int* col){
    if(c=='J') c='I';
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(keySquare[i][j] == c){
                *r=i; *col=j; return;
            }
}

int main(){
    char text[200], key[50];
    printf("Enter Cipher Text: ");
    scanf(" %[^\n]", text);
    printf("Enter Key: ");
    scanf("%s", key);

    generateKey(key);

    printf("Decrypted Text: ");
    for(int i=0; text[i]; i+=2){
        char a = toupper(text[i]);
        char b = toupper(text[i+1]);

        int r1,c1,r2,c2;
        findPos(a,&r1,&c1);
        findPos(b,&r2,&c2);

        if(r1 == r2){
            printf("%c%c", keySquare[r1][(c1+4)%5], keySquare[r2][(c2+4)%5]);
        }
        else if(c1 == c2){
            printf("%c%c", keySquare[(r1+4)%5][c1], keySquare[(r2+4)%5][c2]);
        }
        else{
            printf("%c%c", keySquare[r1][c2], keySquare[r2][c1]);
        }
    }
    return 0;
}

