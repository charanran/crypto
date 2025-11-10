#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char cipher[200];
    int freq[26] = {0};
    printf("Enter Cipher Text: ");
    scanf(" %[^\n]", cipher);

    for(int i=0; cipher[i]; i++){
        if(isalpha(cipher[i]))
            freq[toupper(cipher[i]) - 'A']++;
    }

    printf("\nFrequency of Letters:\n");
    for(int i=0;i<26;i++)
        printf("%c = %d\n", 'A'+i, freq[i]);

    printf("\nUse this frequency to manually map letters to plaintext.\n");
    printf("Hint: Most frequent letters: E, T, A, O, I, N\n");
    return 0;
}



