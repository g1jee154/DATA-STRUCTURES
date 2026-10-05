#include <stdio.h>
#include <string.h>

void reversePrefix(char word[], char ch)
{
    int i, pos = -1;
    int len = strlen(word);
    for (i = 0; i < len; i++)
    {
        if (word[i] == ch)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        printf("Character not found\n");
        return;
    }

    for (i = 0; i <= pos / 2; i++)
    {
        char temp = word[i];
        word[i] = word[pos - i];
        word[pos - i] = temp;
    }
}

int main()
{
    char word[100];
    char ch;
    printf("Enter a word: ");
    scanf("%s", word);
    printf("Enter a character: ");
    scanf(" %c", &ch);
    printf("Original word: %s\n", word);
    reversePrefix(word, ch);
    printf("After reversing: %s\n", word);
    return 0;
}