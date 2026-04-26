// Implemetation of Affine cipher in c program
// It uses two keys for the encryption
// It is same as the caesar cipher but uses two keys and the math is different from the caesar. uses the same table alphabet and numbers two generate encrypted data

#include <stdio.h>

int main()
{
    int a, b;
    printf("Enter the key (a,b)");
    scanf("%d %d", &a, &b);

    char text[100], cipher[100];
    printf("Enter the message");
    scanf("%s", text);

    for (int i = 0; text[i] != '\0'; i++)
    {

        if (text[i] >= 'a' && text[i] <= 'z')
        {

            cipher[i] = (a * (text[i] - 'a') + b) % 26 + 'a';
        }
    }
    printf("Cipher text %s", cipher);

    // decrypt
    for(int i = 0 ; cipher[i] != '\0' ;i++){

        
    }

    return 0;
}