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
    printf("Enter the message : ");
    scanf("%s", text);
    int i = 0;
    for (i; text[i] != '\0'; i++)
    {

        if (text[i] >= 'a' && text[i] <= 'z')
        {

            cipher[i] = (a * (text[i] - 'a') + b) % 26 + 'a';
        }
        else
        {
            cipher[i] = (a * (text[i] - 'A') + b) % 26 + 'A';
        }
    }
    cipher[i] = '\0';
    printf("Cipher text %s\n", cipher);

    char msg[100];
    int inv, flag;

    for (i = 0; i < 26; i++)
    {
        flag = (a * i) % 26;
        printf("flag : %d\n", flag);
        if (flag == 1)
        {
            inv = i;
            break;
        }
    }

    if (flag != 1)
    {
        printf("Selected value a doesnot have inverse");
        return 0;
    }

    for (i = 0; cipher[i] != '\0'; i++)
    {

        if (cipher[i] >= 'a' && cipher[i] <= 'z')
        {
            msg[i] = (inv * (((cipher[i] - 'a') - b + 26)) % 26) % 26 + 'a';
        }
        else
        {

            msg[i] = (inv * (((cipher[i] - 'A') - b + 26)) % 26) % 26 + 'A';
        }
    }

    printf("\nEncrypted : %s \t Decrypted : %s", cipher, msg);

    return 0;
}