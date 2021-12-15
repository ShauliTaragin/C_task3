#include <stdio.h>
#include <string.h>
#define WORD 30
#define TXT 1024

char words[WORD], paragraph[TXT];
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
char reverse_letter(char a ){
    if(a>='A' && a<='Z'){
        return (char)90-(a-65);
    }
    if(a>='a' && a<='z'){
        return (char)122-(a-97);
    }
    return a;
}

int isAlphabet(char c){
    if((c>='a' && c<='z') | (c>='A' && c<='Z')){
        return 1;
    }
    return 0;
}

void Atbash(){
    int sizeword = strlen(words);
    char atbrev[sizeword];
    for (int i = sizeword-1,j=0; j<sizeword | 0<=i; i--,j++){
        atbrev[j] = reverse_letter(words[i]);
    }
    char atb[sizeword];
    for (int i = 0; i < sizeword; i++){
        atb[i] = reverse_letter(words[i]);
    }
    int start = 0;
    int end =0;
    int counter1 =0;
    int counter2 =0;
    int lengthy = strlen(paragraph);
    char to_print[TXT];
    to_print[0]=0;
    int counter_for_arr=0;
    while (end<=lengthy) {
        if(paragraph[end]==' '){
            end++;
            continue;
        }
        if(counter1== sizeword){
            for (int i = start; i < end; i++){
                to_print[counter_for_arr] = paragraph[i];
                counter_for_arr++;
            }
            to_print[counter_for_arr] = '~';
            counter_for_arr++;
            start++;
            end=start;
            counter1=0;
            counter2=0;
            continue;
        }
        if(counter2 == sizeword){
            for (int i = start; i < end; i++){
                to_print[counter_for_arr] = paragraph[i];
                counter_for_arr++;
            }
            to_print[counter_for_arr] = '~';
            counter_for_arr++;
            start++;
            end=start;
            counter2=0;
            counter1=0;
            continue;
        }
        if(paragraph[end]==atb[counter1] | paragraph[end]==atbrev[counter2]){
            int counter_temp = counter1;
            if(paragraph[end]==atb[counter1]){
                if(paragraph[end]!=atbrev[counter2] & counter2!=0){
                    counter2=0;
                    start++;
                    end=start;
                    continue;
                }
                else{
                    counter1++;
                }
            }
            if(paragraph[end]==atbrev[counter2]){
                if(paragraph[end]!=atb[counter_temp] & counter_temp!=0){
                    counter1=0;
                    start++;
                    end=start;
                    continue;
                }
                else{
                    counter2++;
                }
            }
            end++;
        }
        else{
            counter1=0;
            counter2=0;
            start++;
            end=start;
        }
    }
    for(int i = counter_for_arr-1 ; i< sizeof(to_print)/sizeof(to_print[0]);i++){
        to_print[i] = '\0';
    }
    if(to_print[0]!=0){
        printf("%s\n" , to_print);
    }
    printf("\n");
}

void User(){
    for (int i = 0; i < WORD; ++i) {
        scanf("%[^\n]", words);
        if(words[i] == '\0'){
            break;
        }
        sumg += convertToGem(words[i]);
    }
    char temp = getchar();
    scanf("%[^~]", paragraph);
    int start = 0;
    int end =0;
    int temp_sum;
    int lengthy = strlen(paragraph);
    char to_print[TXT];
    to_print[0]=0;
    int counter_for_arr=0;
    while (end!=lengthy) {
        if(!isAlphabet(paragraph[start])){
            start++;
            end=start;
            continue;
        }
        temp_sum+=convertToGem(paragraph[end]);
        if(!isAlphabet(paragraph[end])){
            end++;
            continue;
        }
        if(temp_sum==sumg){
            for (int i = start; i <= end; i++){
                to_print[counter_for_arr] = paragraph[i];
                counter_for_arr++;
            }
            to_print[counter_for_arr] = '~';
            counter_for_arr++;
            start++;
            temp_sum=0;
            end=start;
        }
        else if(temp_sum>sumg){
            start++;
            temp_sum=0;
            end=start;
        }
        else{
            end++;
        }
    }
    for(int i = counter_for_arr-1 ; i< sizeof(to_print)/sizeof(to_print[0]);i++){
        to_print[i] = '\0';
    }
    if(to_print[0]!=0){
        printf("%s\n" , to_print);
    }

    // printf("%s", words);
    // printf("%s\n", paragraph);
}
void main(){
    User();
    Atbash();
    //printf("%d",smug);
}