#include <stdio.h>
#include <ctype.h>

int main(){
    char text[500];
    int freq[26]={0};
    printf("Enter Text: ");
    scanf(" %[^\n]", text);

    for(int i=0;text[i];i++)
        if(isalpha(text[i]))
            freq[toupper(text[i])-'A']++;

    printf("\nLetter Frequency:\n");
    for(int i=0;i<26;i++)
        printf("%c : %d\n", 'A'+i, freq[i]);

    printf("\nUse this to guess mapping.\n");
    return 0;
}
https://www.onlinegdb.com/#tab-stdin