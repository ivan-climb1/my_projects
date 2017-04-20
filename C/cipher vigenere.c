#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
// ШИФР ВИЖЕНЕРА!

bool isKeyValid(string key);
char ChipText(char key, char text, int number);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: /home/cs50/pset2/vigenere <keyword>\n");
        return 1;
    }
    string key = argv[1];
    if (!isKeyValid(key))
    {
        printf("Keyword must only contain letters A-Z and a-z\n");
        return 1;
    }
    string text = GetString();
    for (int i = 0, j = 0, n = strlen(text), len = strlen(key); i < n; i++, j++) // i - индекс итераций текста, j - индекс ключа
    {
        if (isupper(text[i])) // если символ в верхнем РЕГИСТРЕ
        {
            j %= len; // повтор ключа
            text[i] = ChipText(key[j], text[i], 65); // шифровка символа
        }
        else if (islower(text[i])) // если символ в нижнем РЕГИСТРЕ
        {
            j %= len; // повтор ключа
            text[i] = ChipText(key[j], text[i], 97); // шифровка символа
        }
        else // если в тексте встречается не буква, то индекс ключа не должен изменяться, поэтому отнимаем 1
        {
            j -= 1;
        }
    }
    printf("%s\n", text);
    return 0;
}

bool isKeyValid(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i])) // если встречается не буква, то выходим их функции TeseKey()
        {
            return false;
        }
    }
    return true;
}

char ChipText(char key, char text, int number)
{
    if (isupper(key)) // если символ ключа в верхнем РЕГИСТРЕ
    {
        key -= 65;
    }
    else if (islower(key)) // если символ ключа в нижнем РЕГИСТРЕ
    {
        key -= 97;
    }
    text -= number;
    text = (text + key) % 26; // алгоритм сдвига буквы
    text += number;
    return text;
}