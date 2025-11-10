#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    FILE *fin, *fout;
    char ch, key[100];
    int j=0;

    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");

    if(!fin || !fout){
        printf("File error!");
        return 0;
    }

    printf("Enter Key: ");
    scanf("%s", key);
    int klen = strlen(key);

    while((ch = fgetc(fin)) != EOF){
        if(isalpha(ch)){
            char base = isupper(ch) ? 'A' : 'a';
            int shift = toupper(key[j % klen]) - 'A';
            ch = (ch - base + shift) % 26 + base;
            j++;
        }
        fputc(ch, fout);
    }

    fclose(fin);
    fclose(fout);
    printf("Encrypted text saved to output.txt\n");
}
