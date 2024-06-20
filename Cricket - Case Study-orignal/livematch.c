#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"
//-----------------------------------------------------
void init(void)
{
    sc1.over = over;
    sc1.over = 0.0f;
    sc2.over = over;
    sc2.over = 0.0f;
}
//-----------------------------------------------------
int ch1,ch2,ch3;
void select_batsman(void)
{
    printf("Select Batsman : \n");
    bat_list(T1); 
    printf("Choice : ");
    scanf("%d",&ch1);
    T1[ch1-1].mark = 1;
    bt1 = T1[ch1-1];
}
void select_runner(void)
{
    printf("Select Runner : \n");
    bat_list(T1); 
    printf("Choice : ");
    scanf("%d",&ch2);
    T1[ch2-1].mark = 1;
    bt2 = T1[ch2-1];
    
}

void select_bowlwer(void)
{
    printf("\n-----------------------------------------------------------\n");
    printf("Select Bowler : \n");
    bat_list_bl(T2); 
    printf("Choice : ");
    scanf("%d",&ch3);
    bl1 = T2[ch3-1];
    bl1.ball=0.0f;
    printf("\n-----------------------------------------------------------\n");
}

void bat_list_bl(team arr[])
{
    printf("-----------------------------------------------------------\n");  
    for(int i = 0 ; i <= 10 ; i++)
    {
        //if(arr[i].mark == 0)
            printf("%s",arr[i].name);
    }
    printf("\n-----------------------------------------------------------\n");
}

void bat_list(team arr[])
{
    printf("-----------------------------------------------------------\n");  
    for(int i = 0 ; i <= 10 ; i++)
    {
        if(arr[i].mark == 0)
            printf("%s",arr[i].name);
    }
    printf("\n-----------------------------------------------------------\n");
}

void display_Score_card(void)
{
    printf("\n-----------------------------------------------------------\n");
    printf("Batting Team: %s\n",team1);
    printf("%.22s  \t%d(%d)  \t\t%.2f\n",bt1.name,bt1.run, bt1.bt_ball ,bt1.bstr);
    printf("%.22s  \t%d(%d)  \t\t%.2f\n",bt2.name,bt2.run,bt2.bt_ball,  bt2.bstr);

    printf("Runs :  %d-%d       \t\tOver : %.1f \n",sc1.score,sc1.wk,sc1.over);
    printf("Bowling Team : %s \n",team2);
    printf("%.22s  \t%.1f(%d)\t\t%.2f\n",bl1.name,bl1.ov,bl1.bol_run,bl1.eco);
    printf("-----------------------------------------------------------\n");
}

void inning_one()
{
    float temp = 0.0f;
    cb=bt1;
    //-------------------------------
    while( temp < over) // Looping till Overs not finish
    {
        float ball = temp;
        //------------------------------------------
        int k = 0;
        while(k < 6)
        {  
            ball = ball + 0.1f;
            bl1.ov = bl1.ov + 0.1f;
            //printf("bl1.ball = %.1f\n",bl1.ball);
            
                char br[3];
                printf("Ball %.1f  :Enter Runs  :  ",ball);
                scanf("%s",br);
                if(strcmp(br,"NB") == 0 || strcmp(br,"WD") == 0)
                {
                    bl1.ov = bl1.ov - 0.1f;
                    k = k - 1;
                    ball = ball - 0.1f;
                    ++sc1.score;
                    ++bl1.bol_run;
                    int run;
                    if(strcmp(br,"NB") == 0)
                    {
                        printf("Runs : ");
                        scanf("%d",&run);
                        if(run == 1 || run == 3 )
                        {
                            sc1.score = sc1.score + run;
                            bl1.bol_run = bl1.bol_run + run;
                            cb.run = cb.run + run;
                            update();
                            --cb.bt_ball;
                            swap_strike();
                        }
                        else if( run == 2 ||run == 4 ||run == 6)
                        {
                            cb.run = cb.run + run;
                            update();
                            --cb.bt_ball;
                            sc1.score = sc1.score + run;
                            bl1.bol_run = bl1.bol_run + run;
                        }
                    }
                }
                else if(strcmp(br,"1") == 0 || strcmp(br,"3") == 0 )
                {
                    if( strcmp(br,"1") == 0)
                    {
                        bl1.bol_run = bl1.bol_run + 1;
                        sc1.score = sc1.score + 1;
                        cb.run = cb.run + 1;
                        update();
                        swap_strike();
                    }
                    if( strcmp(br,"3") == 0)
                    {
                        sc1.score = sc1.score + 3;
                        bl1.bol_run = bl1.bol_run + 3;
                        cb.run = cb.run + 3;
                        update();
                        swap_strike();
                    }
                }
                else if( strcmp(br,"2") == 0 || strcmp(br,"4") == 0 || strcmp(br,"6") == 0 || strcmp(br,"0") == 0 )
                {
                    if( strcmp(br,"2") == 0)
                    {
                        cb.run = cb.run + 2; 
                        update();              
                        sc1.score = sc1.score + 2;
                        bl1.bol_run = bl1.bol_run + 2;

                    }
                    else if( strcmp(br,"4") == 0)
                    {
                        cb.run = cb.run + 4;
                        update();
                        sc1.score = sc1.score + 4;
                        bl1.bol_run = bl1.bol_run + 4 ;
                    }  
                    else if( strcmp(br,"6") == 0)
                    {
                       
                        cb.run = cb.run + 6;
                        update();
                        sc1.score = sc1.score + 6;
                        bl1.bol_run = bl1.bol_run + 6 ;      
                    }
                    else if(strcmp(br,"0") == 0)
                    {
                        cb.run = cb.run + 0;
                        update();
                        sc1.score = sc1.score + 0;
                        bl1.bol_run = bl1.bol_run + 0 ;
                    }      
                }
                else if(strcmp(br,"WK") == 0)
                {
                    sc1.wk++;
                    bl1.wkt++;
                    //bl1.ov   = ball;
                    //bl1.eco  = bl1.bol_run /bl1.ov ;
                    //T2[ch3-1]= bl1;
                    update();
                    T1[ch1-1] = bt1;
                    T1[ch2-1] = bt2;
                    if(sc1.wk < 10)
                    {

                        if( strcmp(cb.name,bt1.name) == 0)
                        {
                            select_batsman();
                            cb = bt1;
                            
                        }
                        else if( strcmp(cb.name,bt2.name) == 0)
                        {
                            bat_list(T1); 
                            printf("Choice : ");
                            scanf("%d",&ch2);
                            T1[ch2-1].mark = 1;
                            bt2 = T1[ch2-1];
                            cb = bt2;
                        }                      
                    }
                    else
                    {
                        T2[ch3-1] = bl1;
                        printf("%s Team All Out at %d \n",team1,sc1.score);
                        getchar();
                        display_Score_card();
                        goto label;
                    }
                }

            sc1.over = ball;
            bl1.eco  = bl1.bol_run /bl1.ov ;
            display_Score_card();
            k++;
        }
        //-------------------------------------------
        temp = temp + 1 ;
        //----------------------------------
        int x = ++bl1.ov;
        bl1.ov = x;
        bl1.eco  = bl1.bol_run /(bl1.ov);
        
        //------------------------------------------------
        T2[ch3-1] = bl1;
        T1[ch1-1] = bt1;
        T1[ch2-1] = bt2;
        //------------------------------------------------
        sc1.over = temp;
        printf("Over Completed : %.1f \n",sc1.over);
        //--------------------------------------
        swap_strike();
        display_Score_card();
        if( temp == over)
            break;
        select_bowlwer();  
    }
   //------------------------------------------
   label:
        printf("Inning 1 is over...\n");
        getchar(); 
        getchar();      
}

void swap_strike( void )
{
    if( strcmp(cb.name,bt1.name) == 0)
    {
        bt1 = cb;
        cb = bt2;
        printf("On strike : %s \n",cb.name);
    }
    else if( strcmp(cb.name,bt2.name) == 0)
    {
        bt2 = cb;
        cb = bt1;
        printf("On strike : %s \n",cb.name);
    }
}

void update( void )
{
    if( strcmp(cb.name,bt1.name) == 0)
    {
        ++cb.bt_ball;
        float f = (float)cb.run/cb.bt_ball;
        f *= 100;
        cb.bstr = f ;
        bt1 = cb;
    }
    else if( strcmp(cb.name,bt2.name) == 0)
    {
        ++cb.bt_ball;
        float f = (float)cb.run/cb.bt_ball;
        f *= 100;
        cb.bstr = f ;
        bt2 = cb;
    }
}

//==========================================================================
//If team 2 win the toss and choose the bat

int ch4,ch5,ch6;
void select_batsman_2(void)
{
    printf("Select Batsman : \n");
    bat_list(T2); 
    printf("Choice : ");
    scanf("%d",&ch4);
    T2[ch4-1].mark = 1;
    bt1 = T2[ch4-1];
}
void select_runner_2(void)
{
    printf("Select Runner : \n");
    bat_list(T2); 
    printf("Choice : ");
    scanf("%d",&ch5);
    T2[ch5-1].mark = 1;
    bt2 = T2[ch5-1];
    
}

void select_bowlwer_2(void)
{
    printf("\n-----------------------------------------------------------\n");
    printf("Select Bowler : \n");
    bat_list_bl(T1); 
    printf("Choice : ");
    scanf("%d",&ch6);
    bl1 = T1[ch6-1];
    bl1.ball=0.0f;
    printf("\n-----------------------------------------------------------\n");
}

void display_Score_card_2(void)
{
    printf("\n-----------------------------------------------------------\n");
    printf("Batting Team: %s\n",team2);
    printf("%.22s  \t%d(%d)  \t\t%.2f\n",bt1.name,bt1.run, bt1.bt_ball ,bt1.bstr);
    printf("%.22s  \t%d(%d)  \t\t%.2f\n",bt2.name,bt2.run,bt2.bt_ball,  bt2.bstr);

    printf("Runs :  %d-%d       \t\tOver : %.1f \n",sc1.score,sc1.wk,sc1.over);
    printf("Bowling Team : %s \n",team1);
    printf("%.22s  \t%.1f(%d)\t\t%.2f\n",bl1.name,bl1.ov,bl1.bol_run,bl1.eco);
    printf("-----------------------------------------------------------\n");
}

void inning_one_2()
{
    float temp = 0.0f;
    cb=bt1;
    //-------------------------------
    while( temp < over) // Looping till Overs not finish
    {
        float ball = temp;
        //------------------------------------------
        int k = 0;
        while(k < 6)
        {  
            ball = ball + 0.1f;
            bl1.ov = bl1.ov + 0.1f;
            //printf("bl1.ball = %.1f\n",bl1.ball);
            
                char br[3];
                printf("Ball %.1f  :Enter Runs  :  ",ball);
                scanf("%s",br);
                if(strcmp(br,"NB") == 0 || strcmp(br,"WD") == 0)
                {
                    bl1.ov = bl1.ov - 0.1f;
                    k = k - 1;
                    ball = ball - 0.1f;
                    ++sc1.score;
                    ++bl1.bol_run;
                    int run;
                    if(strcmp(br,"NB") == 0)
                    {
                        printf("Runs : ");
                        scanf("%d",&run);
                        if(run == 1 || run == 3 )
                        {
                            sc1.score = sc1.score + run;
                            bl1.bol_run = bl1.bol_run + run;
                            cb.run = cb.run + run;
                            update();
                            --cb.bt_ball;
                            swap_strike();
                        }
                        else if( run == 2 ||run == 4 ||run == 6)
                        {
                            cb.run = cb.run + run;
                            update();
                            --cb.bt_ball;
                            sc1.score = sc1.score + run;
                            bl1.bol_run = bl1.bol_run + run;
                        }
                    }
                }
                else if(strcmp(br,"1") == 0 || strcmp(br,"3") == 0 )
                {
                    if( strcmp(br,"1") == 0)
                    {
                        bl1.bol_run = bl1.bol_run + 1;
                        sc1.score = sc1.score + 1;
                        cb.run = cb.run + 1;
                        update();
                        swap_strike();
                    }
                    if( strcmp(br,"3") == 0)
                    {
                        sc1.score = sc1.score + 3;
                        bl1.bol_run = bl1.bol_run + 3;
                        cb.run = cb.run + 3;
                        update();
                        swap_strike();
                    }
                }
                else if( strcmp(br,"2") == 0 || strcmp(br,"4") == 0 || strcmp(br,"6") == 0 || strcmp(br,"0") == 0 )
                {
                    if( strcmp(br,"2") == 0)
                    {
                        cb.run = cb.run + 2; 
                        update();              
                        sc1.score = sc1.score + 2;
                        bl1.bol_run = bl1.bol_run + 2;

                    }
                    else if( strcmp(br,"4") == 0)
                    {
                        cb.run = cb.run + 4;
                        update();
                        sc1.score = sc1.score + 4;
                        bl1.bol_run = bl1.bol_run + 4 ;
                    }  
                    else if( strcmp(br,"6") == 0)
                    {
                       
                        cb.run = cb.run + 6;
                        update();
                        sc1.score = sc1.score + 6;
                        bl1.bol_run = bl1.bol_run + 6 ;      
                    }
                    else if(strcmp(br,"0") == 0)
                    {
                        cb.run = cb.run + 0;
                        update();
                        sc1.score = sc1.score + 0;
                        bl1.bol_run = bl1.bol_run + 0 ;
                    }      
                }
                else if(strcmp(br,"WK") == 0)
                {
                    sc1.wk++;
                    bl1.wkt++;
                    //bl1.ov   = ball;
                    //bl1.eco  = bl1.bol_run /bl1.ov ;
                    //T2[ch3-1]= bl1;
                    update();
                    T2[ch4-1] = bt1;
                    T2[ch5-1] = bt2;
                    if(sc1.wk < 10)
                    {

                        if( strcmp(cb.name,bt1.name) == 0)
                        {
                            select_batsman_2();
                            cb = bt1;
                            
                        }
                        else if( strcmp(cb.name,bt2.name) == 0)
                        {
                            bat_list(T2); 
                            printf("Choice : ");
                            scanf("%d",&ch5);
                            T2[ch5-1].mark = 1;
                            bt2 = T2[ch5-1];
                            cb = bt2;
                        }                      
                    }
                    else
                    {
                        T1[ch6-1] = bl1;
                        printf("%s Team All Out at %d \n",team1,sc1.score);
                        getchar();
                        display_Score_card_2();
                        goto label;
                    }
                }

            sc1.over = ball;
            bl1.eco  = bl1.bol_run /bl1.ov ;
            display_Score_card_2();
            k++;
        }
        //-------------------------------------------
        temp = temp + 1 ;
        //----------------------------------
        int x = ++bl1.ov;
        bl1.ov = x;
        bl1.eco  = bl1.bol_run /(bl1.ov);
        
        //------------------------------------------------
        T1[ch6-1] = bl1;
        T2[ch4-1] = bt1;
        T2[ch5-1] = bt2;
        //------------------------------------------------
        sc1.over = temp;
        printf("Over Completed : %.1f \n",sc1.over);
        //--------------------------------------
        swap_strike();
        display_Score_card_2();
        if( temp == over)
            break;
        select_bowlwer_2();  
    }
   //------------------------------------------
   label:
        printf("Inning 1 is over...\n");
        getchar(); 
        getchar();      
}













