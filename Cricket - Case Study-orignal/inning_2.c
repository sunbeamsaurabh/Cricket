#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"

int ch1,ch2,ch3;// for chase team 1
void second_inning(void)
{
    if(x == 1 || x == 4)
    {
        printf("[%s Need To %d in %.1f Overs To Win...]\n",team2,Target,over);
        select_batsman_2(); // T2 BATSMAN
        select_runner_2();  // T2 RUNNER
        select_bowlwer_2(); // T1 BOWLER
        chase_2();
    }
    else if(x == 2 || x == 3)
    {
        printf("%s Need To %d in %.1f Overs To Win..\n",team1,Target,over);
        select_batsman(); // T1 BATSMAN
        select_runner();  // T1 RUNNER
        select_bowlwer(); // T2 BOWLER
        chase_1();
    }
    getchar(); 
    getchar();
}

void result(char *team)
{
    printf("*************************************************\n");
    if(sc2.score > Target)
    {
        printf("%s win by %d Wicket....\n",team,10-sc2.wk);

    }
    else if(sc2.score < Target)
    {
         printf("%s loose by %d runs....\n",team,Target - sc2.score);
    }
    else if(sc2.score == Target)
    {
        printf("Match Is Tie......\n");
    }
    printf("*************************************************\n");
}
//--------------------------------------------------------------
//If Team-1 chase
void chase_1()
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
                    ++sc2.score;
                    ++bl1.bol_run;
                    if(sc2.score > Target)
                    {
                        printf("%s win by %d Wicket....\n Congratulation team %s \n",team1,10-sc2.wk,team1);
                        goto win;
                    }
                    int run;
                    if(strcmp(br,"NB") == 0)
                    {
                        printf("Runs : ");
                        scanf("%d",&run);
                        if(run == 1 || run == 3 )
                        {
                            sc2.score = sc2.score + run;
                            
                            bl1.bol_run = bl1.bol_run + run;
                            cb.run = cb.run + run;
                            update();
                            --cb.bt_ball;
                            if(sc2.score > Target)
                            {
                                printf("%s win by %d Wicket....\n Congratulation team %s \n",team1,10-sc2.wk,team1);
                                goto win;
                            }
                            swap_strike();
                        }
                        else if( run == 2 ||run == 4 ||run == 6)
                        {
                            cb.run = cb.run + run;
                            update();
                            --cb.bt_ball;
                            sc2.score = sc2.score + run;
                            bl1.bol_run = bl1.bol_run + run;
                            if(sc2.score > Target)
                            {
                                printf("%s win by %d Wicket....\n Congratulation team %s \n",team1,10-sc2.wk,team1);
                                goto win;
                            }
                        }
                    }
                }
                else if(strcmp(br,"1") == 0 || strcmp(br,"3") == 0 )
                {
                    if( strcmp(br,"1") == 0)
                    {
                        bl1.bol_run = bl1.bol_run + 1;
                        sc2.score = sc2.score + 1;
                        cb.run = cb.run + 1;
                        update();
                        if(sc2.score > Target)
                        {
                            printf("%s win by %d Wicket....\nCongratulation team %s \n",team1,10-sc2.wk,team1);
                            goto win;
                        }
                        swap_strike();
                    }
                    if( strcmp(br,"3") == 0)
                    {
                        sc2.score = sc2.score + 3;
                        bl1.bol_run = bl1.bol_run + 3;
                        cb.run = cb.run + 3;
                        update();
                        if(sc2.score > Target)
                        {
                            printf("%s win by %d Wicket....\n Congratulation team %s \n",team1,10-sc2.wk,team1);
                            goto win;
                        }
                        swap_strike();
                    }
                }
                else if( strcmp(br,"2") == 0 || strcmp(br,"4") == 0 || strcmp(br,"6") == 0 || strcmp(br,"0") == 0 )
                {
                    if( strcmp(br,"2") == 0)
                    {
                        cb.run = cb.run + 2; 
                        update();              
                        sc2.score = sc2.score + 2;
                        bl1.bol_run = bl1.bol_run + 2;
                        if(sc2.score > Target)
                        {
                            printf("%s win by %d Wicket....\n Congratulation team %s \n",team1,10-sc2.wk,team1);
                            goto win;
                        }
                    }
                    else if( strcmp(br,"4") == 0)
                    {
                        cb.run = cb.run + 4;
                        update();
                        sc2.score = sc2.score + 4;
                        bl1.bol_run = bl1.bol_run + 4 ;
                        if(sc2.score > Target)
                        {
                            printf("%s win by %d Wicket....\n Congratulation team %s \n",team1,10-sc2.wk);
                            goto win;
                        }
                    }  
                    else if( strcmp(br,"6") == 0)
                    {   
                        cb.run = cb.run + 6;
                        update();
                        sc2.score = sc2.score + 6;
                        bl1.bol_run = bl1.bol_run + 6 ;
                        if(sc2.score > Target)
                        {
                            printf("%s win by %d Wicket....\n",team1,10-sc2.wk);
                            goto win;
                        }      
                    }
                    else if(strcmp(br,"0") == 0)
                    {
                        cb.run = cb.run + 0;
                        update();
                        sc2.score = sc2.score + 0;
                        bl1.bol_run = bl1.bol_run + 0 ;
                        if(sc2.score > Target)
                        {
                            printf("%s win by %d Wicket....\n",team1,10-sc2.wk);
                            goto win;
                        }
                    }      
                }
                else if(strcmp(br,"WK") == 0)
                {
                    sc2.wk++;
                    bl1.wkt++;
                    //bl1.ov   = ball;
                    //bl1.eco  = bl1.bol_run /bl1.ov ;
                    //T2[ch3-1]= bl1;
                    update();
                    T1[ch1-1] = bt1;
                    T1[ch2-1] = bt2;
                    if(sc2.wk < 10)
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
                        printf("%s Team All Out at %d \n",team1,sc2.score);
                        result(team1);
                        getchar();
                        display_Score_card_sc2();
                        goto label;
                    }
                }

            sc2.over = ball;
            bl1.eco  = bl1.bol_run /bl1.ov ;
            display_Score_card_sc2();
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
        sc2.over = temp;
        printf("Over Completed : %.1f \n",sc2.over);
        //--------------------------------------
        swap_strike();
        display_Score_card_sc2();
        if( temp == over)
            break;
        select_bowlwer();  
    }
   //------------------------------------------
   label:
        printf("Inning 2nd is over...\n");
   win :
        T2[ch3-1] = bl1;
        T1[ch1-1] = bt1;
        T1[ch2-1] = bt2;
        result(team1);
        getchar(); 
        getchar();      
}

void display_Score_card_sc2(void)
{
    printf("\n-----------------------------------------------------------\n");
    printf("Batting Team: %s\n",team1);
    printf("%.22s  \t%d(%d)  \t\t%.2f\n",bt1.name,bt1.run, bt1.bt_ball ,bt1.bstr);
    printf("%.22s  \t%d(%d)  \t\t%.2f\n",bt2.name,bt2.run,bt2.bt_ball,  bt2.bstr);

    printf("Runs :  %d-%d       \t\tOver : %.1f \n",sc2.score,sc2.wk,sc2.over);
    printf("Bowling Team : %s \n",team2);
    printf("%.22s  \t%.1f(%d)\t\t%.2f\n",bl1.name,bl1.ov,bl1.bol_run,bl1.eco);
    printf("-----------------------------------------------------------\n");
}


//--------------------------------------------------------------
//If Team-2 chase
void display_Score_card_2_2(void)
{
    printf("\n-----------------------------------------------------------\n");
    printf("Batting Team: %s\n",team2);
    printf("%.22s  \t%d(%d)  \t\t%.2f\n",bt1.name,bt1.run, bt1.bt_ball ,bt1.bstr);
    printf("%.22s  \t%d(%d)  \t\t%.2f\n",bt2.name,bt2.run,bt2.bt_ball,  bt2.bstr);

    printf("Runs :  %d-%d       \t\tOver : %.1f \n",sc2.score,sc2.wk,sc2.over);
    printf("Bowling Team : %s \n",team1);
    printf("%.22s  \t%.1f(%d)\t\t%.2f\n",bl1.name,bl1.ov,bl1.bol_run,bl1.eco);
    printf("-----------------------------------------------------------\n");
}

int ch4,ch5,ch6;
void chase_2()
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
                    ++sc2.score;
                    ++bl1.bol_run;
                    if(sc2.score > Target)
                    {
                        printf("%s win by %d Wicket....\n",team2,10-sc2.wk);
                        goto win;
                    }
                    int run;
                    if(strcmp(br,"NB") == 0)
                    {
                        printf("Runs : ");
                        scanf("%d",&run);
                        if(run == 1 || run == 3 )
                        {
                            sc2.score = sc2.score + run;
                            bl1.bol_run = bl1.bol_run + run;
                            cb.run = cb.run + run;
                            update();
                            --cb.bt_ball;
                            if(sc2.score > Target)
                            {
                                printf("%s win by %d Wicket....\n",team2,10-sc2.wk);
                                goto win;
                            }
                            swap_strike();
                        }
                        else if( run == 2 ||run == 4 ||run == 6)
                        {
                            cb.run = cb.run + run;
                            update();
                            --cb.bt_ball;
                            sc2.score = sc2.score + run;
                            bl1.bol_run = bl1.bol_run + run;
                            if(sc2.score > Target)
                            {
                                printf("%s win by %d Wicket....\n",team2,10-sc2.wk);
                                goto win;
                            }
                        }
                    }
                }
                else if(strcmp(br,"1") == 0 || strcmp(br,"3") == 0 )
                {
                    if( strcmp(br,"1") == 0)
                    {
                        bl1.bol_run = bl1.bol_run + 1;
                        sc2.score = sc2.score + 1;
                        cb.run = cb.run + 1;
                        update();
                        if(sc2.score > Target)
                        {
                            printf("%s win by %d Wicket....\n",team2,10-sc2.wk);
                            goto win;
                        }
                        swap_strike();
                    }
                    if( strcmp(br,"3") == 0)
                    {
                        sc2.score = sc2.score + 3;
                        bl1.bol_run = bl1.bol_run + 3;
                        cb.run = cb.run + 3;
                        update();
                        if(sc2.score > Target)
                        {
                            printf("%s win by %d Wicket....\n",team2,10-sc2.wk);
                            goto win;
                        }
                        swap_strike();
                    }
                }
                else if( strcmp(br,"2") == 0 || strcmp(br,"4") == 0 || strcmp(br,"6") == 0 || strcmp(br,"0") == 0 )
                {
                    if( strcmp(br,"2") == 0)
                    {
                        cb.run = cb.run + 2; 
                        update();              
                        sc2.score = sc2.score + 2;
                        bl1.bol_run = bl1.bol_run + 2;
                        if(sc2.score > Target)
                        {
                            printf("%s win by %d Wicket....\n",team2,10-sc2.wk);
                            goto win;
                        }

                    }
                    else if( strcmp(br,"4") == 0)
                    {
                        cb.run = cb.run + 4;
                        update();
                        sc2.score = sc2.score + 4;
                        bl1.bol_run = bl1.bol_run + 4 ;
                        if(sc2.score > Target)
                        {
                            printf("%s win by %d Wicket....\n",team2,10-sc2.wk);
                            goto win;
                        }
                    }  
                    else if( strcmp(br,"6") == 0)
                    {
                       
                        cb.run = cb.run + 6;
                        update();
                        sc2.score = sc2.score + 6;
                        bl1.bol_run = bl1.bol_run + 6 ; 
                        if(sc2.score > Target)
                        {
                            printf("%s win by %d Wicket....\n",team2,10-sc2.wk);
                            goto win;
                        }     
                    }
                    else if(strcmp(br,"0") == 0)
                    {
                        cb.run = cb.run + 0;
                        update();
                        sc2.score = sc2.score + 0;
                        bl1.bol_run = bl1.bol_run + 0 ;
                        if(sc2.score > Target)
                        {
                            printf("%s win by %d Wicket....\n",team2,10-sc2.wk);
                            goto win;
                        }
                    }      
                }
                else if(strcmp(br,"WK") == 0)
                {
                    sc2.wk++;
                    bl1.wkt++;
                    //bl1.ov   = ball;
                    //bl1.eco  = bl1.bol_run /bl1.ov ;
                    //T2[ch3-1]= bl1;
                    update();
                    T2[ch4-1] = bt1;
                    T2[ch5-1] = bt2;
                    if(sc2.wk < 10)
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
                        printf("%s Team All Out at %d \n",team2,sc2.score);
                        getchar();
                        display_Score_card_2_2();
                        result(team2);
                        goto label;
                    }
                }

            sc2.over = ball;
            bl1.eco  = bl1.bol_run /bl1.ov ;
            display_Score_card_2_2();
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
        sc2.over = temp;
        printf("Over Completed : %.1f \n",sc2.over);
        //--------------------------------------
        swap_strike();
        display_Score_card_2_2();
        if( temp == over)
            break;
        select_bowlwer_2();  
    }
   //------------------------------------------
   label:
        printf("Inning 2nd is over...\n");
    win :
        T1[ch6-1] = bl1;
        T2[ch4-1] = bt1;
        T2[ch5-1] = bt2;
        result(team2);
        getchar(); 
        getchar();      
}



