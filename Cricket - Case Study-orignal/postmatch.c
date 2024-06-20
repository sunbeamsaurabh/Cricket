#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"

void after_match()
{   
    int ch;
    while(1)
    {
        printf("0.Exit\n");
        printf("1.%s Batting\n",team1);
        printf("2.%s Batting\n",team2);
        printf("3.%s Bowling\n",team1);
        printf("4.%s Bowling\n",team2);
        printf("Enter Choice  : ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 0 :printf("Bye....\n");
                    exit(1);
                    break;
            case 1 :bat_score_card(T1);
                    break;
            case 2 :bat_score_card(T2);
                    break;
            case 3 :bowling_score_card(T1);
                    break;
            case 4 :bowling_score_card(T2);
                    break;
            default:printf("Invalid Option...\n");
                    break;
        }  
    }
    printf("Bye!!!!\n");
}

void bat_score_card(team arr[])
{
    printf("-----------------------------------------------------------\n");
    printf("Name                     Run     Strike Reate\n");
    for(int i = 0 ; i <= 10 ; i++)
    {
        printf("%.22s",arr[i].name);
        if(arr[i].bt_ball > 0 || arr[i].mark == 1)
        {
            printf("  %d(%d) ",arr[i].run,arr[i].bt_ball);
            printf("    %.2f",arr[i].bstr);
        }
        printf("\n");
    }
    printf("-----------------------------------------------------------\n");
}

void bowling_score_card(team arr[])
{
    printf("Name                   Over    Run  Wicket  Economy\n");
    printf("-----------------------------------------------------------\n");
    for(int i = 0 ; i <= 10 ; i++)
    {
        printf("%.22s",arr[i].name);
        if(arr[i].ov > 0.1F)
        {
            printf("  %.1f    %d    %d      %.2f",arr[i].ov,arr[i].bol_run,arr[i].wkt,arr[i].eco);
        }
        printf("\n");
    }
    printf("-----------------------------------------------------------\n");
}








