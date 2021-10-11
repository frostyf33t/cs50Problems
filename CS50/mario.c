#include <cs50.h>
#include <stdio.h>

int main(void)
{
    
    //creates a variable for the number of rows of stairs
    int numberofrows;
    
    //prompts the user on how many rows to have--need between 1 and 8
    do
    {

        numberofrows = get_int("How many rows?  Pick a number between 1 and 8\n");

    }
    
    //do while loop to make sure between 1 and 8
    while (numberofrows < 1 || numberofrows > 8);

    //creates the space before the stairs
    char emptychar = ' ';
    
    //creates the space between the two staircases
    string emptystring = "  ";

    //letter designating stairs
    char stair = '#';
    
    //for loop to create stairs and spaces
    for (int n = 1; n <= numberofrows; n++)
    {
        int i = n;
        
        int r = (numberofrows - n);
        
        //creates the spaces before the stairs
        while (i < numberofrows)
        {
            printf("%c", emptychar);
            i++;
        }
        
        //creates the stairs
        while (r < numberofrows)
        {
            printf("%c", stair);
            
            r++;
        }
        
        printf("%s", emptystring);
        
        //reinitializes r which is used for the stairs
        r = (numberofrows - n);
        
        //creates the second stairscase
        while (r < numberofrows)
        {
            printf("%c", stair);
            r++;
        }
        
        //creates the new line before next loop
        printf("\n");

    }

}