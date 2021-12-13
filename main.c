#include <stdio.h>
#include <string.h>
#define WORD 30
#define TXT 1024

static int sumg = 0;

int convertToGem(char c){
    if(c >='a' && c<='z'){
        return c-96;
    }
    if(c>='A' && c<='Z'){
        return c-64;
    }
    return 0;
}
void User(){
    char words[WORD], paragraph[TXT];
    for (int i = 0; i < WORD; ++i) {
        scanf("%[^\n]", words);
        if(words[i] == '\0'){
            break;
        }
        sumg += convertToGem(words[i]);
    }
    scanf("%[^~]", paragraph);
    paragraph[strlen(paragraph)]='~';
    int pointer_for_text = 0;
    for (int i = 0; i < TXT; ++i) {
        int temp [TXT];
    }
    


    printf("%s", words);
    printf("%s\n", paragraph);
}

void main(){
    User();
    //printf("%d",smug);
}
