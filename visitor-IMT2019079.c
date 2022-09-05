
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "mysemops-IMT2019079.h"
#define MAX 10
#include "configs-IMT2019079.h"
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Enter the visitor name");
    }

    printf("------VISITOR %s WAITS\n",argv[1]);

    int semid = get_existing_sem(SEM_KEY_VAL);
    lock_down(semid);

    printf("------VISITOR %s TALKS\n",argv[1]);
    sleep(2);

    free_up(semid);
    printf("------VISITOR %s LEAVES\n",argv[1]);

    return 0;
}   