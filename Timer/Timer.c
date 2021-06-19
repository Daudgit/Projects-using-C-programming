#include <stdio.h>
#include <time.h> //for sleep() function

#include <stdlib.h>
#include <stdbool.h>
int main()
{
    int hour, minute, second;
    int x = 1;
    hour = minute = second = 0;
again:
    printf("Start Timer by pressing 1");
    scanf("%d", &x);
    if (x == 1)
    {
        while (x)
        {
            //clear output screen
            system("cls");
            //print time in HH : MM : SS format
            printf("%02d : %02d : %02d ", hour, minute, second);
            //clear output buffer in gcc
            fflush(stdout);
            //increase second
            second++;
            //update hour, minute and second
            if (second == 60)
            {
                minute += 1;
                second = 0;
            }
            if (minute == 60)
            {
                hour += 1;
                minute = 0;
            }
            if (hour == 24)
            {
                hour = 0;
                minute = 0;
                second = 0;
            }
            sleep(1); //wait till 1 second
        }
    }

    else
        goto again;
    return 0;
}
