#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"header.h"

void prematch(void)
{   
    printf("-----------------------------------------------------------\n");
    printf("Enter Team One : ");
    scanf("%s",team1);
    //puts(team1);
    printf("Enter Team Two : ");
    scanf("%s",team2);
    //puts(team2);
    
    printf("-----------------------------------------------------------\n");
    if(strcmp(team1,"IND") == 0)
    {
        printf("%s\n",team1);
        add_team_struc(IND,T1); 
    }
    else if(strcmp(team1,"AUS") == 0)
    {
        printf("%s\n",team1);
        add_team_struc(AUS,T1);
    }
    else if(strcmp(team1,"SA") == 0)
    {
        printf("%s\n",team1);
        add_team_struc(SA,T1);
    }
    else
    {
        printf("Invaid Team...\n");
        exit(1);
    }

    printf("\n-----------------------------------------------------------\n");
    

    //printf("Here-1\n");
    puts(team2);
    if(strcmp(team2,"IND") == 0)
    {
        printf("%s\n",team2);
        add_team_struc(IND,T2);
       
    }
    else if(strcmp(team2,"AUS") == 0)
    {
        printf("%s\n",team2);
        add_team_struc(AUS,T2);
       
    }
    else if(strcmp(team2,"SA") == 0)
    {
        printf("%s\n",team2);
        add_team_struc(SA,T2); 
    }
    else
    {
        printf("Invaid Team...\n");
        exit(1);
    }
    printf("\n-----------------------------------------------------------\n");
    
    printf("Number of Overs : ");
    scanf("%f",&over);
}

void add_team_struc(char *path,team T[])
{
    FILE *f1;
    char name[100];
    f1 = fopen(path,"r");
        if(f1 != NULL)
        {
            int i=0;
            while(fgets(name,30,f1) != NULL)
            {
                strcpy(T[i].name,name);
                T[i].mark = 0;
                printf("%s",T[i].name);
                i++;
            }
        }
        fclose(f1);
}

int toss_time(void)
{
    init();
    printf("\n-----------------------------------------------------------\n");
    printf("Toss Time ....\n");
    printf("H(0).%s\n",team1);
    printf("T(1).%s\n",team2);
    srand(time(NULL));
    toss = rand() % 2  ;
    printf("Toss = %d \n",toss);
    if(toss == 0 )
    {    
        printf("%s Won The Toss...\n",team1);
        printf("1.Bat\n2.Bowl\nSelect  :");
        scanf("%d",&t1);
        if(t1 == 1)
        {
            printf("%s Select to bat first..\n",team1);
            select_batsman(); // T1 BATSMAN
            select_runner();  // T1 RUNNER
            select_bowlwer(); // T2 BOWLER
            inning_one();  
            printf("\n-----------------------------------------------------------\n");
            Target = sc1.score;
            printf("%s Need To %d in %.1f Overs To Win..\n",team2,Target + 1,over);
            getchar();
            printf("\n-----------------------------------------------------------\n");
            x = 1;            
        }
        else
        {
            printf("%s Select to bowl first..\n",team1);
            select_batsman_2(); // T2 BATSMAN
            select_runner_2();  // T2 RUNNER
            select_bowlwer_2(); // T1 BOWLER
            inning_one_2();
            printf("\n-----------------------------------------------------------\n");
            Target = sc1.score;
            printf("%s Need To %d in %.1f Overs To Win..\n",team1,Target + 1,over);
            getchar();
            printf("\n-----------------------------------------------------------\n"); 
            x = 2;   
        }
    }
    else
    {   
        printf("%s Won The Toss...\n",team2);
        printf("1.Bat\n2.Bowl\nSelect  :");
        scanf("%d",&t2);
        if(t2 == 1)
        {
            printf("%s Select to bat first..\n",team2);
            select_batsman_2(); // T2 BATSMAN
            select_runner_2();  // T2 RUNNER
            select_bowlwer_2(); // T1 BOWLER
            inning_one_2();
            printf("\n-----------------------------------------------------------\n");
            Target = sc1.score;
            printf("%s Need To %d in %.1f Overs To Win..\n",team1,Target + 1,over);
            getchar();
            printf("\n---------=--------------------------------------------------\n");
            x = 3;
        }
        else
        {
            printf("%s Select to bowl first..\n",team2);
            select_batsman(); // T1 BATSMAN
            select_runner();  // T1 RUNNER
            select_bowlwer(); // T2 BOWLER
            inning_one();
            printf("\n-----------------------------------------------------------\n");
            Target = sc1.score;
            printf("%s Need To %d in %.1f Overs To Win..\n",team2,Target + 1,over);
            printf("\n-----------------------------------------------------------\n");
            getchar();
            x = 4;
        }
    }
}

// void second_inning(void)
// {
//     if(x == 1 || x == 4)
//     {
//         printf("[%s Need To %d in %.1f Overs To Win...]\n",team2,Target,over);
//     }
//     else if(x == 2 || x == 3)
//     {
//         printf("%s Need To %d in %.1f Overs To Win..\n",team1,Target,over);
//     }
//     getchar(); 
//     getchar();
// }


















