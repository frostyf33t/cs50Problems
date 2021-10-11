#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Get a value from the user that much be positive
    int totalcoin = 0;
    
    float change;
    
    do
    {
        
        change = get_float("How much change is there?\n");
        
    }
    
    while (change < 0);
    
    //Change in cents
    int changeincents = round(change * 100);
    
    //value of a quarter
    int quarter = 25;
    
    //value of a dime
    int dime = 10;
    
    //value of a nickel
    int nickel = 5;
    
    //value of a penny
    int penny = 1;
    
    //Loop to add to totalcoins
    while (changeincents >= 1)
    {
        
        if (changeincents >= quarter)
        {
            changeincents -= quarter;
            totalcoin++;
        }
        else if (changeincents >= dime)
        {
            changeincents -= dime;
            totalcoin++;
        }
        else if (changeincents >= nickel)
        {
            changeincents -= nickel;
            totalcoin++;
        }
        else
        {
            totalcoin += changeincents;
            
            changeincents -= changeincents;
        }
    }
    
    //prints total number of coins
    printf("%i\n", totalcoin);
    
    
    
    
    
    
}