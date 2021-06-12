#include <stdio.H>
#include <stdlib.h>
#include <time.h> //for random number generator seed
//main function
int main()
{
    int RandomNumber = 0;
    int guess = 0;
    int NumberOfGuesses;
    time_t t;

    //Initialization of Random Number generator
    srand((unsigned)time(&t));
    //get the random number
    RandomNumber = rand() % 21;
    printf("\n This is the guessing game");
    printf("\n I have choosen a number between 0 and 20 , now you will guess \n");
    for (NumberOfGuesses = 5; NumberOfGuesses > 0; --NumberOfGuesses)
    {
        printf("You have %d tr%s left", NumberOfGuesses, NumberOfGuesses == 1 ? "y" : "ies");
        printf("\n Enter a guess: ");
        scanf("%d", &guess);

        if (guess == RandomNumber)
        {
            printf("Congratulation !! you guessed it :) \n");

            goto jump;
        }
        else if (guess < 0 || guess > 20) //checking for invalid guess
            printf("I said the number is between 0 and 20 :(");

        else if (RandomNumber > guess)
            printf("Sorry My number is greater than %d :,( ", guess);
        else if (RandomNumber < guess)
            printf("Sorry My number is lesser than %d :,( ", guess);
    }

    printf(" \n You have had 5 tries and failed.The Number was %d :~(", RandomNumber);
jump:
    printf(" Game is Over !!! ");
    return 0;
}