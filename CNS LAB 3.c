#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keySquare[5][5];

void generateKeySquare(char key[]) {
    int used[26] = {0};
    used['J'-'A'] = 1;
    int k = 0;
    for (int i = 0; key[i]; i++) {
        char c = toupper(key[i]);
        if (c == 'J') c = 'I';
        if (!used[c-'A']) {
            keySquare[k/5][k%5] = c;
            used[c-'A'] = 1;
            k++;
        }
    }
    for (char c='A'; c<='Z'; c++) {
        if (!used[c-'A']) {
            keySquare[k/5][k%5] = c;
            used[c-'A'] = 1;
            k++;
        }
    }
}

void findPos(char c, int *row, int *col) {
    if (c=='J') c='I';
    for (int i=0;i<5;i++)
        for (int j=0;j<5;j++)
            if (keySquare[i][j]==c) {*row=i; *col=j; return;}
}

void playfairEncrypt(char text[]) {
    char out[100]; int k=0;
    for (int i=0;text[i];) {
        char a=toupper(text[i++]);
        if(!isalpha(a)) continue;
        char b;
        if (text[i]) { b=toupper(text[i]); if(!isalpha(b)) {i++; continue;} }
        else b='X';
        if (a==b) b='X';
        else i++;
        int r1,c1,r2,c2;
        findPos(a,&r1,&c1); findPos(b,&r2,&c2);
        if(r1==r2){ out[k++]=keySquare[r1][(c1+1)%5]; out[k++]=keySquare[r2][(c2+1)%5]; }
        else if(c1==c2){ out[k++]=keySquare[(r1+1)%5][c1]; out[k++]=keySquare[(r2+1)%5][c2]; }
        else{ out[k++]=keySquare[r1][c2]; out[k++]=keySquare[r2][c1]; }
    }
    out[k]='\0'; printf("Ciphertext: %s\n", out);
}

int main(){
    char key[50], text[100];
    printf("Enter key: "); scanf("%s", key);
    generateKeySquare(key);
    printf("Enter text: "); scanf(" %[^\n]", text);
    playfairEncrypt(text);
}
