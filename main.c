#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORD 30
#define TXT 1024

char words[WORD], paragraph[TXT];
static int sumg = 0;

int convertToGem(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - 96;
    }
    if (c >= 'A' && c <= 'Z')
    {
        return c - 64;
    }
    return 0;
}

char reverse_letter(char a)
{
    if (a >= 'A' && a <= 'Z')
    {
        return (char)90 - (a - 65);
    }
    if (a >= 'a' && a <= 'z')
    {
        return (char)122 - (a - 97);
    }
    return a;
}

int isAlphabet(char c)
{
    if ((c >= 'a' && c <= 'z') | (c >= 'A' && c <= 'Z'))
    {
        return 1;
    }
    return 0;
}

int isAlphabet2(char c)
{
    if ((c >= 'a' && c <= 'z') | (c >= 'A' && c <= 'Z') | (c == ' '))
    {
        return 1;
    }
    return 0;
}

void Anagram(char *array) {
    if (strlen(array) != 0) {
        int start = 0;
        int end = 0;
        int tilda = 0;
        int endflag = 0;
        int count_for_print = 0;
        char *temp_print = (char *) malloc(sizeof(array));
        memset(temp_print, 0, strlen(temp_print));
        while (end <= strlen(array)) {
            int counter = 0;
            char *temp_array = (char *) malloc(sizeof(array));
            memset(temp_array, 0, strlen(temp_array));
            while ((array[end] != '~' )| (array[end] == strlen(array))) {
                temp_array[counter] = array[end];
                counter++;
                end++;
                if (array[end] == '~') {
                    tilda = end;
                }
                if (array[end] == '\0') {
                    endflag = 1;
                    tilda = end;
                    break;
                }
            }
            int flagi = 1;
            for (int i = 0; i < end - start; ++i) {
                if (!isAlphabet2(temp_array[i])) {
                    flagi = 0;
                }
            }
            if (!flagi) {
                start = tilda + 1;
                end = start;
            } else {
/*              char copy_array[strlen(words)];
                strcpy(copy_array, words);*/
                while (1) {
                    int* orgi = calloc(27, sizeof(int ));
                    for (int i = 0; i < strlen(words); ++i) {
                        orgi[convertToGem(words[i])] += 1;
                    }
                    int* checky  = calloc(27, sizeof(int ));
                    char* converty= calloc(end - start, sizeof(char ));
                    //strncpy(converty, temp_array, end - start);
                    for (int i = 0; i < end - start; ++i) {
                        converty[i] = temp_array[i];
                    }
                    for (int i = 0; i < strlen(converty); ++i) {
                        checky[convertToGem(temp_array[i])] += 1;
                    }
                    int countery = 0;
                    for (int i = 1; i < 27; ++i) {
                        if (orgi[i] != 0 && checky[i] != 0) {
                            if (orgi[i] == checky[i]) {
                                countery++;
                            }
                        }
                        if (countery == strlen(words)) {
                            for (int j = 0; j < end - start; ++j) {
                                temp_print[count_for_print] = temp_array[j];
                                count_for_print++;
                            }
                            temp_print[count_for_print] = '~';
                            count_for_print++;
                            break;
                        }
                    }
                    start = tilda + 1;
                    end = start;
                    break;
                }
            }
            if (endflag) {
                char tempy[strlen(temp_array)];
                strncpy(tempy, temp_print, count_for_print - 1);
                printf("%s", tempy);
                if (strlen(tempy) == 0) {
                    printf("\n");
                }
                break;
            }
        }
    }
}

void Atbash()
{
    int sizeword = strlen(words);
    char atbrev[sizeword];
    for (int i = sizeword - 1, j = 0; (j < sizeword) | (0 <= i); i--, j++)
    {
        atbrev[j] = reverse_letter(words[i]);
    }
    char atb[sizeword];
    for (int i = 0; i < sizeword; i++)
    {
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
    while (end <= lengthy)
    {
        if (paragraph[end] == ' ')
        {
            end++;
            continue;
        }
        if (counter1 == sizeword)
        {
            for (int i = start; i < end; i++)
            {
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
        if (counter2 == sizeword)
        {
            for (int i = start; i < end; i++)
            {
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
        if ((paragraph[end] == atb[counter1]) | (paragraph[end] == atbrev[counter2]))
        {
            int counter_temp = counter1;
            if (paragraph[end] == atb[counter1])
            {
                if (((paragraph[end]) != atbrev[counter2]) & (counter2 != 0))
                {
                    counter2 = 0;
                    start++;
                    end = start;
                    continue;
                }
                else
                {
                    counter1++;
                }
            }
            if (paragraph[end] == atbrev[counter2])
            {
                if (((paragraph[end]) != atb[counter_temp]) & (counter_temp != 0))
                {
                    counter1 = 0;
                    start++;
                    end = start;
                    continue;
                }
                else
                {
                    counter2++;
                }
            }
            end++;
        }
        else
        {
            counter1 = 0;
            counter2 = 0;
            start++;
            end = start;
        }
    }
    for (int i = counter_for_arr - 1; i < sizeof(to_print) / sizeof(to_print[0]); i++)
    {
        to_print[i] = '\0';
    }
    if (to_print[0] != 0)
    {
        printf("%s\n", to_print);
    }
    if (strlen(to_print) == 0)
    {
        printf("\n");
    }
}

char *User()
{
    int start = 0;
    int end = 0;
    int temp_sum = 0;
    int lengthy = strlen(paragraph);
    int tilda_mark = 0;
    char *to_print = (char *)malloc(TXT);
    memset(to_print, 0, strlen(to_print));
    to_print[0] = 0;
    int counter_for_arr = 0;
    while (end != lengthy)
    {
        if (!isAlphabet(paragraph[start]))
        {
            start++;
            end = start;
            continue;
        }
        temp_sum += convertToGem(paragraph[end]);
        if (!isAlphabet(paragraph[end]))
        {
            end++;
            continue;
        }
        if (temp_sum == sumg)
        {
            if (tilda_mark != 0)
            {
                to_print[counter_for_arr++] = '~';
            }
            tilda_mark++;
            for (int i = start; i <= end; i++)
            {
                to_print[counter_for_arr] = paragraph[i];
                counter_for_arr++;
            }
            start++;
            temp_sum = 0;
            end = start;
        }
        else if (temp_sum > sumg)
        {
            start++;
            temp_sum = 0;
            end = start;
        }
        else
        {
            end++;
        }
    }
    for (int i = counter_for_arr - 1; i < sizeof(to_print); i++)
    {
        to_print[i] = '\0';
    }
    char *temp_array2 = (char *)malloc(counter_for_arr);
    strncpy(temp_array2, to_print, counter_for_arr);
    if (to_print[0] != 0)
    {
        printf("%s\n", to_print);
    }
    if (strlen(to_print) == 0)
    {
        printf("\n");
    }
    free(temp_array2);
    return to_print;
}

int main()
{
    for (int i = 0; i < WORD; ++i)
    {
        scanf("%[^\n]", words);
        if (words[i] == '\0')
        {
            break;
        }
        sumg += convertToGem(words[i]);
    }
    getchar();
    scanf("%[^~]", paragraph);
    printf("Gematria Sequences: ");
    char *p = User();
    printf("Atbash Sequences: ");
    Atbash();
    printf("Anagram Sequences: ");
    Anagram(p);
    free(p);
    return 1;
}