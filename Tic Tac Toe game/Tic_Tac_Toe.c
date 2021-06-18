// Tic Tac Toe Game

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int choice, player;

int checkforwin();
void dispayBoard();
void markBoard(char mark);

char str1[50];
char str2[50];

int main()
{
    int gamestatus;
    char mark;
    printf("Enter player 1 Name \t");
    gets(str1);
    printf("Enter player 2 Name \t");
    gets(str2);
    player = 1;
    do
    {
        dispayBoard();
        //change turns
        player = (player % 2) ? 1 : 2;
        //get input
        if (player == 1)
            printf("%s enter a Number: ", str1);
        else
            printf("%s enter a Number: ", str2);
        scanf("%d", &choice);
        //set the correct character based on correct player
        mark = (player == 1) ? 'X' : 'O';
        //set board based on user choice
        markBoard(mark);
        dispayBoard();
        gamestatus = checkforwin();
        player++;

    } while (gamestatus == -1);
    if (gamestatus == 1)
    {
        --player;
        if (player == 1)
            printf("Congratulation !!! %s is won :)", str1);
        else
            printf("Congratulation !!! %s is won :) ", str2);
    }
    else
        printf("The game is draw");

    return 0;
}

int checkforwin()
{
    int returnValue = 0;
    if (square[1] == square[2] && square[2] == square[3])
        returnValue = 1;
    else if (square[4] == square[5] && square[5] == square[6])
        returnValue = 1;
    else if (square[7] == square[8] && square[8] == square[9])
        returnValue = 1;
    else if (square[1] == square[4] && square[4] == square[7])
        returnValue = 1;
    else if (square[2] == square[5] && square[5] == square[8])
        returnValue = 1;
    else if (square[3] == square[6] && square[6] == square[9])
        returnValue = 1;
    else if (square[1] == square[5] && square[5] == square[9])
        returnValue = 1;
    else if (square[3] == square[5] && square[5] == square[7])
        returnValue = 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' &&
             square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
        returnValue = 0;
    else
        returnValue = -1;

    return returnValue;
}
/******************************************************
Function to create Board of Tic Tac Toe with player mark
*******************************************************/
void dispayBoard()
{
    system("cls");
    printf("\n \n ******* TIC TAC TOE GAME ******** \n \n");
    printf("player 1 %s (X) - player 2 %s (O) \n \n ", str1, str2);
    printf("    |     |     \n");
    printf("  %c  |  %c  |  %c  \n", square[1], square[2], square[3]);
    printf("_____|_____|______\n");
    printf("     |     |      \n");
    printf("  %c  |  %c  |  %c  \n", square[4], square[5], square[6]);
    printf("_____|_____|______\n");
    printf("     |     |      \n");
    printf("  %c  |  %c  |  %c  \n", square[7], square[8], square[9]);
    printf("     |     |    \n\n");
}
/**********************************
Set the Board with correct character , X or O in correct spot of array
***********************************/
void markBoard(char mark)
{
    if (choice == 1 && square[1] == '1')
        square[1] = mark;
    else if (choice == 2 && square[2] == '2')
        square[2] = mark;
    else if (choice == 3 && square[3] == '3')
        square[3] = mark;
    else if (choice == 4 && square[4] == '4')
        square[4] = mark;
    else if (choice == 5 && square[5] == '5')
        square[5] = mark;
    else if (choice == 6 && square[6] == '6')
        square[6] = mark;
    else if (choice == 7 && square[7] == '7')
        square[7] = mark;
    else if (choice == 8 && square[8] == '8')
        square[8] = mark;
    else if (choice == 9 && square[9] == '9')
        square[9] = mark;
    else
    {
        --player;
        printf("invalid move");
        getch();
    }
}

/****************************
Function to return game status
1 for game is over with result
-1 for game is in progress
0 game is over and no result
*****************************/