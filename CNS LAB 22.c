#include <stdio.h>
#include <ctype.h>

int main(){
    char text[200];
    printf("Enter Cipher Text: ");
    scanf(" %[^\n]", text);

    for(int k=1;k<26;k++){
        printf("Key %d: ", k);
        for(int i=0;text[i];i++){
            if(isalpha(text[i])){
                char base = isupper(text[i])?'A':'a';
                printf("%c", (text[i]-base - k + 26)%26 + base);
            } else printf("%c", text[i]);
        }
        printf("\n");
    }
    return 0;
}


