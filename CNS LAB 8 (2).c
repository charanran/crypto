#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char key[50], result[27];
    int used[26]={0}, k=0;

    printf("Enter Keyword: ");
    scanf("%s", key);

    for(int i=0; key[i]; i++){
        char c = toupper(key[i]);
        if(c=='J') c='I';
        if(!used[c-'A']){
            used[c-'A'] = 1;
            result[k++] = c;
        }
    }

    for(char c='A'; c<='Z'; c++){
        if(c=='J') continue;
        if(!used[c-'A']) result[k++] = c;
    }

    result[26] = '\0';
    printf("Generated Key: %s\n", result);
    return 0;
}



