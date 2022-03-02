#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

//function to calculate reading level

int main(void)
{
    
    //variable to count letters
    int lettercounter = 0;
    
    //variable to count sentences.  Counts sentences by counting punctuation.
    int sentencecounter = 0;
    
    //variable to count number of words.  does it by counting spaces
    int wordcounter = 1;
    
    //space variable
    char space = ' ';
    
    //variables for punctuation
    char questionmark = '?';
    char exclamationmark = '!';
    char period = '.';
    
    //asks user for text
    string text = get_string("Text:");
    
    //loop to count spaces letters and punctuation
    for (int i = 0, n = strlen(text); i < n ; i++)
    {

        if (isalpha(text[i]))
        {
            lettercounter++;
        }
        else if (text[i] == space)
        {
            wordcounter++;
        }
        else if (text[i] == questionmark || text[i] == exclamationmark || text[i] == period)
        {
            sentencecounter++;
        }
    }

    //index variable calculates Coleman-Liau equation
    int index = round((0.0588 * (lettercounter / (((float) wordcounter) / 100))) - (.296 * (sentencecounter / (((
                          float) wordcounter) / 100))) - 15.8);

    //string that initializes gradelevel
    string gradelevel = " ";
    
    //if-else statement to prince out gradelevel
    if (index < 1)
    {

        gradelevel = "Before Grade 1";
        printf("%s\n", gradelevel);
    }
    else if (index >= 16)
    {
        gradelevel = "Grade 16+";
        printf("%s\n", gradelevel);
    }
    else
    {
        printf("Grade %i\n", index);

    }










}
