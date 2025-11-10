#include <stdio.h>
#include <ctype.h>

int main(){
    char text[200];
    printf("Enter Text: ");
    scanf(" %[^\n]", text);

    for(int i=0;text[i];i++){
        if(isalpha(text[i])){
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - base + 13) % 26 + base;
        }
    }

    printf("Result: %s\n", text);
    return 0;
}

