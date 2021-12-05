#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#define MAX 100
#define SIGEOF 16

// Signal Handler for SIGTSTP
void sighandlerZ(int sig_num)
{
    printf("You handle Ctrl + Z\n");
}
void ctrl_z_handler()
{
    signal(SIGTSTP, sighandlerZ);
}
void sighandlerC(int sig_num)
{
    printf("You handle Ctrl + C\n");
}
void ctrl_C_handler()
{
    signal(SIGINT, sighandlerC);
}
void sighandlerD(int sig_num)
{
    printf("You handle Ctrl + D\n");
    exit(-1);
}
void ctrl_D_handler()
{
    signal(SIGEOF, sighandlerD);    
}

int main()
{
    char string[MAX];
    char a;
    int index;
    ctrl_z_handler();
    ctrl_C_handler();
    ctrl_D_handler();

    while (1)
    {
        printf("\n>");
        a = getchar();
        while (1)
        {
            if (a == EOF)
            {                
                raise(SIGEOF);
            }
        }
    }
    return 0;
}