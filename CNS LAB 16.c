#include <stdio.h>
#include <ctype.h>
#include <string.h>

char engFreq[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

int main(){
    char text[500];
    int freq[26]={0};

    printf("Enter Cipher Text: ");
    scanf(" %[^\n]", text);

    for(int i=0;text[i];i++)
        if(isalpha(text[i]))
            freq[toupper(text[i])-'A']++;

    int used[26]={0};
    char map[26];

    for(int k=0;k<26;k++){
        int max=0, pos=0;
        for(int i=0;i<26;i++){
            if(!used[i] && freq[i] > max){
                max=freq[i];
                pos=i;
            }
        }
        used[pos]=1;
        map[pos] = engFreq[k];
    }

    printf("\nSuggested Mapping:\n");
    for(int i=0;i<26;i++)
        printf("%c -> %c\n",'A'+i, map[i]);

    return 0;
}
