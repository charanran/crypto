#include <stdio.h>
#include <ctype.h>

int modInverse(int a){
    for(int i=1;i<26;i++) if((a*i)%26==1) return i;
    return -1;
}

void affine(char text[], int a, int b, int mode){
    for(int i=0;text[i];i++){
        if(isalpha(text[i])){
            char base=isupper(text[i])?'A':'a';
            int x=text[i]-base;
            if(mode==1)
                text[i]=(a*x+b)%26+base;
            else{
                int inv=modInverse(a);
                text[i]=(inv*(x-b+26))%26+base;
            }
        }
    }
}

int main(){
    char text[100]; int a,b,choice;
    printf("Enter text: "); scanf(" %[^\n]",text);
    printf("Enter keys a,b: "); scanf("%d %d",&a,&b);
    printf("1. Encrypt\n2. Decrypt\nChoice: "); scanf("%d",&choice);
    affine(text,a,b,choice);
    printf("Result: %s\n",text);
}

