#include <stdio.h>
#include <ctype.h>

int mod26(int x){ return (x%26+26)%26; }

int modInverse(int a){
    for(int i=0;i<26;i++)
        if((a*i)%26 == 1) return i;
    return -1;
}

int main(){
    char text[100];
    int a,b,c,d, det, invDet;

    printf("Enter Cipher Text: ");
    scanf(" %[^\n]", text);

    printf("Enter 2x2 Key Matrix (a b c d): ");
    scanf("%d %d %d %d",&a,&b,&c,&d);

    det = mod26(a*d - b*c);
    invDet = modInverse(det);

    if(invDet == -1){
        printf("Key matrix not invertible mod 26!");
        return 0;
    }

    int a2 = mod26(invDet * d);
    int b2 = mod26(invDet * -b);
    int c2 = mod26(invDet * -c);
    int d2 = mod26(invDet * a);

    printf("Plaintext: ");
    for(int i=0; text[i]; i+=2){
        char x = toupper(text[i])-'A';
        char y = isalpha(text[i+1]) ? toupper(text[i+1])-'A' : 'X'-'A';
        int p1 = mod26(a2*x + b2*y) + 'A';
        int p2 = mod26(c2*x + d2*y) + 'A';
        printf("%c%c", p1, p2);
    }
    return 0;
}


