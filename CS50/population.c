#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    
    //variable designating number of years to reach end population
    int numberofyears = 0;
    
    //variable designating starting population size
    int startsize;
    
    //variable designating ending population size
    int endsize;
    
    //Asking user for starting size.  The size needs to be atleast 9
    do
    {
        startsize = get_int("Start size:  ");
    }
    while (startsize < 9);
    
    //Asking user for end size.  Must be atleast as big as starting size.
    do
    {
        endsize = get_int("End size:  ");
    }
    while (endsize<startsize);
    
    //Variable containing the population year by year
    int currentpopulation = startsize;
    
    //Loop adding and subtracting by year
    while (currentpopulation < endsize)
    {
        int yearlycount = 0;
        yearlycount += (currentpopulation / 3);
        yearlycount -= (currentpopulation / 4);
        currentpopulation += yearlycount;
        numberofyears++;
    }
    
    //printing number of years
    printf("Years: %i\n", numberofyears);
    
}