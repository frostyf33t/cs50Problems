#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (isalpha(argv[1]) != true)
    {
        printf("only letters allowed\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("not correct length\n");
        return 1;
    }
    else
    {
        for (int i = 0;i < (strlen(argv[1])-1); i++){
            for (int n = 0 + i; n < (strlen(argv[1])) ; n++){
                if (argv[1][i] == argv[1][n])

                {
                    printf("doesnt have unique values\n");
                    return 1;
                }
            }


        }
    }

    string texttoencrypt = get_string ("Plaintext:");

    string newstring = " ";
    
    for (int i = 0; i<strlen(texttoencrypt);i++)
    {
        ///need to make sure first is checking if alpha
        if(isalpha(texttoencrypt[i]) != true)
        {
            newstring += texttoencrypt[i];
        }
        else
        {
            if (isupper(texttoencrypt[i])==true)
            {
                if (isupper(argv[1][i])==true)
                {
                newstring+=argv[1][i];
                }
                else
                {

                //check if need to add c striahgt to newstring
                    char c = toupper(argv[1][i]);
                    newstring += c;
                }
            }
            else
            {
                if (islower(argv[1][i])==true)
            {
                newstring+=argv[1][i];
            }
            else
            {
                char c = tolower(argv[1][i]);
                newstring += c;
            }
            }
        }
    }
    printf("Ciphertext:%s\n", newstring);
    return 0;
}
