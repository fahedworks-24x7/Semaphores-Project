#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/sem.h>
#include "mysemops-IMT2019079.h"
#define MAX 10
#include "configs-IMT2019079.h"
int main()
{
    int semid = get_existing_sem(SEM_KEY_VAL);

    struct timeval startTime,endTime;

    for(int i = 0;i < 3;i++)
    {
        free_up(semid);
        printf("DOC AVAILABLE\n");

        // get time of day
        gettimeofday(&startTime,NULL);
        sleep(10);

        // check if sem is available
        while(1)
        {
            if(get_val_sem(semid) == 1)
            {
                break;
            }
        }
        lock_down(semid);
        printf("DOC TIRED\n");
        printf("DOC UNAVAILABLE\n");
        gettimeofday(&endTime,NULL);
        printf("DOC RESTS, worked %ld\n",(endTime.tv_sec - startTime.tv_sec));
        sleep(rand()%10);
    }

    remove_sem(semid);
    return 0;
}