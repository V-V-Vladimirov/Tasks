#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
{
    printf("\nsignal caught: %d", signo);
}

int main(void)
{
    for( int i = -1; i<40; i++)
    {
        if ((i == 9)||(i == 19))
        {
            continue;    
        }
        signal(i, sig_handler);
        raise (i);
    }
    return 0;
}