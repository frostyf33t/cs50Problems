#include <stdio.h>
#include <cs50.h>

int main(void)
{
    
    //Gets the users name
    string name = get_string("What is your name?");
    
    //Greets the user
    printf("hello, %s\n", name);
}