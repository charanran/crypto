#include <stdio.h>
#include <ctype.h>

int main(){
    FILE *fin, *fout;
    char ch;
    int key;

    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");

    if(!fin || !fout){
        printf("Error opening file!");
        return 0;
    }

    printf("Enter Key: ");
    scanf("%d", &key);

    while((ch = fgetc(fin)) != EOF){
        if(isalpha(ch)){
            char base = isupper(ch) ? 'A' : 'a';
            ch = (ch - base + key) % 26 + base;
        }
        fputc(ch, fout);
    }

    fclose(fin);
    fclose(fout);
    printf("Encrypted output saved to output.txt\n");
}
