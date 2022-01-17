#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{


    if (argc != 2)
    {
        return 1;
    }


    int key = atoi(argv[1]);
    //if it is int
    if (key > 0)
    {
        char pt[256];
        printf("plaintext: ");
        scanf("%s",pt);
        char Cipher[strlen(pt)];

        //for encrypting
        for (int i = 0, n = strlen(pt); i < n; i++)
        {
            //is alpha
            if (isalpha(pt[i]))
            {
                //is upper
                if (isupper(pt[i]))
                {
                    char a = tolower(pt[i]);
                    int index = a - 97;

                    int c = (index + key) % 26;
                    Cipher[i] = c + 65;
                }
                //lower
                else if (islower(pt[i]))
                {
                    int index = pt[i] - 97;

                    int c = (index + key) % 26;
                    Cipher[i] = c + 97;
                }

            }
            //not alpha
            else
            {
                printf("else\n");
                Cipher[i] = pt[i];
            }

        }
        printf("ciphertext: %s\n", Cipher);

    }
    //if it is not int
    else
    {
        printf("Usage: ./caesar key \n");
    }

}

