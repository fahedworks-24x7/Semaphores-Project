#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "mysemops-IMT2019079.h"
#define MAX 10
#include "configs-IMT2019079.h"

int main()
{
    remove_sem(get_existing_sem(SEM_KEY_VAL));
    create_new_sem(SEM_KEY_VAL);
    return 0;
}