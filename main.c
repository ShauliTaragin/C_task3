#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORD 30
#define TXT 1024

char words[WORD], paragraph[TXT];
static int sumg = 0;

int convertToGem(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 96;
    }
    if (c >= 'A' && c <= 'Z') {
        return c - 64;
    }
    return 0;
}

char reverse_letter(char a) {
    if (a >= 'A' && a <= 'Z') {
        return (char) 90 - (a - 65);
    }
    if (a >= 'a' && a <= 'z') {
        return (char) 122 - (a - 97);
    }
    return a;
}

int isAlphabet(char c) {
    if ((c >= 'a' && c <= 'z') | (c >= 'A' && c <= 'Z')) {
        return 1;
    }
    return 0;
}


int ascii(char c) {
    int temp = (int) c;
    return temp;
}

int isEqual(char *array1) {
    int counter = 0;
    int Array1[128] = {0};
    for (int i = 0; i < strlen(words); ++i) {
        Array1[ascii(words[i])] += 1;
    }
    int Array2[128] = {0};
    for (int i = 0; i < strlen(array1); ++i) {
        Array2[ascii(array1[i])] += 1;
    }
    for (int i = 0; i < 128; ++i) {
        if (i == 32) { continue; }
        else {
            if (Array1[i] != 0 && Array2[i] != 0) {
                if (Array1[i] == Array2[i]) {
                    counter += Array1[i];
                }
            }
        }
    }
    if (counter == strlen(words)) {
        return 1;
    }
    return 0;
}


void Anagram() {
    if (strlen(paragraph) != 0) {
        int start = 0;
        int end = 0;
        int count_for_print = 0;
        //char *temp_print = (char *) malloc(strlen(paragraph) + 1);
        char *temp_print = calloc(strlen(paragraph) + 1, sizeof(char ));
        //memset(temp_print, 0, strlen(paragraph) + 1);
        while (start < strlen(paragraph) - 1) {
            //char *temp_array = (char *) malloc(strlen(paragraph) + 1);
            //memset(temp_array, 0, strlen(paragraph) + 1);
            char *temp_array = calloc(strlen(paragraph) + 1, sizeof(char ));
            int flag3 = 0;
            int count_array = 0;
            if (start + strlen(words) < strlen(paragraph)) {
                for (int i = start; i < strlen(paragraph); ++i) {
                    for (int j = 0; j < strlen(words); ++j) {
                        if (paragraph[i] == words[j]) {
                            start = i;
                            flag3 = 1;
                            break;
                        }
                    }
                    if (flag3) { break; }
                }
            }
            if (flag3) {
                int counter2 = 0;
                int counter3 = start;
                int spaces = 0;
                while (counter2 < strlen(words)) {
                    if (paragraph[counter3] != ' ') {
                        counter2++;
                        counter3++;
                    } else {
                        spaces++;
                        counter3++;
                    }
                }
                if (counter2 == strlen(words)) {
                    end = spaces + counter2 + start;
                    if (end <= strlen(paragraph)) {
                        for (int i = start; i < end; ++i) {
                            temp_array[count_array] = paragraph[i];
                            count_array++;
                        }
                    }
                    if (isEqual(temp_array)) {
                        for (int i = 0; i < strlen(temp_array); ++i) {
                            temp_print[count_for_print] = temp_array[i];
                            count_for_print++;
                        }
                        temp_print[count_for_print] = '~';
                        count_for_print++;
                        start += 1;
                    } else {
                        start += 1;
                    }
                } else {
                    start += 1;
                }
            } else {
                start+=1;
            }
        }
        if (strlen(temp_print) > 0) {
            char *tempy = (char *) calloc(strlen(temp_print), sizeof(char));
            strncpy(tempy, temp_print, count_for_print - 1);
            tempy[strlen(temp_print) - 1] = '\0';
            printf("%s\n", tempy);
            if (strlen(tempy) == 0) {
                printf("\n");
            }
        }
    }
}


void Atbash() {
    int sizeword = strlen(words);
    char atbrev[sizeword];
    for (int i = sizeword - 1, j = 0; (j < sizeword) | (0 <= i); i--, j++) {
        atbrev[j] = reverse_letter(words[i]);
    }
    char atb[sizeword];
    for (int i = 0; i < sizeword; i++) {
        atb[i] = reverse_letter(words[i]);
    }
    int start = 0;
    int end = 0;
    int counter1 = 0;
    int counter2 = 0;
    int lengthy = strlen(paragraph);
    char to_print[TXT];
    to_print[0] = 0;
    int counter_for_arr = 0;
    while (end <= lengthy) {
        if (paragraph[end] == ' ') {
            end++;
            continue;
        }
        if (counter1 == sizeword) {
            for (int i = start; i < end; i++) {
                to_print[counter_for_arr] = paragraph[i];
                counter_for_arr++;
            }
            to_print[counter_for_arr] = '~';
            counter_for_arr++;
            start++;
            end = start;
            counter1 = 0;
            counter2 = 0;
            continue;
        }
        if (counter2 == sizeword) {
            for (int i = start; i < end; i++) {
                to_print[counter_for_arr] = paragraph[i];
                counter_for_arr++;
            }
            to_print[counter_for_arr] = '~';
            counter_for_arr++;
            start++;
            end = start;
            counter2 = 0;
            counter1 = 0;
            continue;
        }
        if ((paragraph[end] == atb[counter1]) | (paragraph[end] == atbrev[counter2])) {
            int counter_temp = counter1;
            if (paragraph[end] == atb[counter1]) {
                if (((paragraph[end]) != atbrev[counter2]) & (counter2 != 0)) {
                    counter2 = 0;
                    start++;
                    end = start;
                    continue;
                } else {
                    counter1++;
                }
            }
            if (paragraph[end] == atbrev[counter2]) {
                if (((paragraph[end]) != atb[counter_temp]) & (counter_temp != 0)) {
                    counter1 = 0;
                    start++;
                    end = start;
                    continue;
                } else {
                    counter2++;
                }
            }
            end++;
        } else {
            counter1 = 0;
            counter2 = 0;
            start++;
            end = start;
        }
    }
    for (int i = counter_for_arr - 1; i < sizeof(to_print) / sizeof(to_print[0]); i++) {
        to_print[i] = '\0';
    }
    if (to_print[0] != 0) {
        printf("%s\n", to_print);
    }
    if (strlen(to_print) == 0) {
        printf("\n");
    }
}

void User() {
    int start = 0;
    int end = 0;
    int temp_sum = 0;
    int lengthy = strlen(paragraph);
    int tilda_mark = 0;
    char *to_print = (char *) malloc(TXT);
    memset(to_print, 0, strlen(to_print));
    to_print[0] = 0;
    int counter_for_arr = 0;
    while (end != lengthy) {
        if (!isAlphabet(paragraph[start])) {
            start++;
            end = start;
            continue;
        }
        temp_sum += convertToGem(paragraph[end]);
        if (!isAlphabet(paragraph[end])) {
            end++;
            continue;
        }
        if (temp_sum == sumg) {
            if (tilda_mark != 0) {
                to_print[counter_for_arr++] = '~';
            }
            tilda_mark++;
            for (int i = start; i <= end; i++) {
                to_print[counter_for_arr] = paragraph[i];
                counter_for_arr++;
            }
            start++;
            temp_sum = 0;
            end = start;
        } else if (temp_sum > sumg) {
            start++;
            temp_sum = 0;
            end = start;
        } else {
            end++;
        }
    }
/*    for (int i = counter_for_arr - 1; i < sizeof(to_print); i++) {
        to_print[i] = '\0';
    }*/
    if (strlen(to_print) > 0) {
        char *tempy = (char *) calloc(strlen(to_print), sizeof(char));
        strncpy(tempy, to_print, counter_for_arr);
        tempy[strlen(to_print)] = '\0';
        printf("%s\n", tempy);
        if (strlen(tempy) == 0) {
            printf("\n");
        }
    }
/*    char *temp_array2 = (char *) malloc(counter_for_arr);
    strncpy(temp_array2, to_print, counter_for_arr);*/
/*    if (to_print[0] != 0) {
        printf("%s\n", to_print);
    }*/
    if (strlen(to_print) == 0) {
        printf("\n");
    }
}

int main() {
    for (int i = 0; i < WORD; ++i) {
        scanf("%[^\n]", words);
        if (words[i] == '\0') {
            break;
        }
        sumg += convertToGem(words[i]);
    }
    getchar();
    scanf("%[^~]", paragraph);
    printf("Gematria Sequences: ");
    User();
    printf("Atbash Sequences: ");
    Atbash();
    printf("Anagram Sequences: ");
    Anagram();
    return 1;
}