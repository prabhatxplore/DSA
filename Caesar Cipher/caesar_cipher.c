#include <stdio.h>
// Simple Program to implement Caesar Cipher

int main()
{
    char text[100], cipher[100];
    int key, i;

    printf("Enter  the message: ");
    scanf("%s", text);

    printf("Enter the key (shift): ");
    scanf("%d", &key);

    // Encryption
    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            cipher[i] = (text[i] - 'a' + key) % 26 + 'a';
        }
        else
        {
            cipher[i] = (text[i] - 'A' + key) % 26 + 'A';
        }
        printf("%c ", cipher[i]);
    }
    return 0;
}