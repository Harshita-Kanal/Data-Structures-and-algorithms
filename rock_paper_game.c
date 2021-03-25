// ROCK PAPER SESSIOR GAME:::::::
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// printing random values
int game(int n)
{
    srand(time(NULL));
    return rand() % n;
}

// comparing two values
int compare(int a, int b)
{
    if (a == 1 && b == 0)
        return 1;
    else if (a == 1 && b == 1)
        return 2;
    else if (a == 1 && b == 2)
        return 3;
    else if (a == 2 && b == 0)
        return 4;
    else if (a == 2 && b == 1)
        return 5;
    else if (a == 2 && b == 2)
        return 6;
    else if (a == 3 && b == 0)
        return 7;
    else if (a == 3 && b == 1)
        return 8;
    else if (a == 3 && b == 2)
        return 9;
}

// working of main function
int main()
{
    int i, j, c, d, k;
    printf("~~...Welcome to GAME Rock ,Paper Secssoir...~~~\n\nEnter how many times you want to play this game:");
    scanf("%d", &k);
    for (j = 1; j <= k; j++)
    {
        printf("\nYour turn:  ");
        printf("\nPress 1 for rock:\nPress 2 for paper:\nPress 3 for secssior\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("YOU choose : Rock");
            break;
        case 2:
            printf("YOU choose : Paper");
            break;
        case 3:
            printf("YOU choose : Secssoir");
            break;
        }
        printf("\n....\n...CUP turn....\n");
        c = game(3);
        switch (c)
        {
        case 0:
            printf("CPU choose : Rock");
            break;
        case 1:
            printf("CPU choose : Paper");
            break;
        case 2:
            printf("CPU choose : Secssoir");
            break;
        }
        d = compare(i, c);
        switch (d)
        {
        case 1:
            printf("\n~~No one Win~~");
            break;
        case 2:
            printf("\n~~CPU Win~~");
            break;
        case 3:
            printf("\n~~Wow YOU  Win~~");
            break;
        case 4:
            printf("\n~~Wow YOU  Win~~");
            break;
        case 5:
            printf("\n~~No one Win~~");
            break;
        case 6:
            printf("\n~~CPU Win~~");
            break;
        case 7:
            printf("\n~~CPU Win~~");
            break;
        case 8:
            printf("\n~~Wow YOU  Win~~");
            break;
        case 9:
            printf("\n~~No one Win~~");
            break;
        }
    }
    printf("\n\n~~BYE GOOD LUCK~~");
    return 0;
}