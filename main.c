#include <stdio.h>
#define WORD 30
#define TXT 1024

int convertToGem(char c){
    if(c >='a' && c<='z'){
        return c-96;
    }
    if(c>='A' && c<='Z'){
        return c-64;
    }
    return 0;
}
int User(){
    char temp[WORD], temp2[TXT];
    int sumg =0;
    for (int i = 0; i < WORD; ++i) {
        scanf("%[^\n]", temp);

        if(temp[i] == '\0'){
            break;
        }
        sumg += convertToGem(temp[i]);
    }

    for (int i = 0; i < TXT; ++i) {
        scanf("%[^~]", temp2);
    }
    printf("%s", temp);
    printf("%s\n", temp2);
    return sumg;
}

void main(){
    int result = User();
    printf("the gemtria of the word is: %d\n",result);
}
