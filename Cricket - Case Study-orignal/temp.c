
#include <stdio.h>

int main()
{
    float over = 2.0f;
    float temp = 0.0f;
    //-------------------------------
    while( temp < over)
    {
        float ball = temp;
        //------------------------------------------
        int k = 0;
        while(k < 6)
        {
            ball = ball + 0.1f;
            printf("%.1f\n",ball);
            k++;
        }
        //-------------------------------------------
        temp = temp + 1 ;
        printf("Over Completed : %.1f \n",temp);
        
    }

    return 0;
}
