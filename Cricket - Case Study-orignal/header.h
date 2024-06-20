
#define IND "IND.txt"
#define SA "SA.txt"
#define AUS "AUS.txt"

//---------------------------------------
typedef struct cricket_team
{
    char mark;
    char name[50];    //Player name
    int run;          //Runs
    int bt_ball;      //How many balls played
    float bstr;       //Batting strike rate

    float ov;         //Over
    float ball;       //How many ball thrown
    int bol_run;      //How many Runs given
    int wkt;          //How many wickets get
    float eco;    //Bowling Economy
}team;
team T1[11],T2[11];
team bt1,bt2,cb,bl1;

//-----------------------------------------
typedef struct score_card 
{
    int score;  //Total Score
    int wk;     //Wickets
    float over; //Total Over
}sc_t;

sc_t sc1,sc2;



//--------------------------------------------

//---------------------------------------

float over;     //Number of overs in match
//------------------------------------------
int toss;          //Toss deside
int t1;           //Team 1 call
int t2;           //Team 2 call
//------------------------------------------
char team1[10];
char team2[10];

void prematch(void);
void add_team_struc(char *path,team T[]);
int toss_time(void);
void init(void);


//--------------------------------------------
void after_match();
void bat_score_card(team arr[]);
void bowling_score_card(team arr[]);

//----------------------------------------------------
//Live Score Card
//1st Innings
void select_batsman(void);
void select_runner(void);
void select_bowlwer(void);
void inning_one(void);
void display_Score_card(void);

void select_batsman_2(void);
void select_runner_2(void);
void select_bowlwer_2(void);
void inning_one_2(void);
void display_Score_card_2(void);
//-----------------------------------------------
void bat_list(team arr[]);
void swap_strike( void );
void update( void );
//-----------------------------------------------------
//2nd Innings Chase Target

int Target;
int x ;

void second_inning(void);
void result(char *team);

void display_Score_card_sc2(void);
void chase_1();

void bat_list_bl(team arr[]);//show bowler list


void chase_2();
void display_Score_card_2_2(void);
//-----------------------------------------------------