#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void foo(void);

/* handle signal SIGINT(CTRL + C)*/
void sint(void){
    printf("\x1b[0;31m" "Ctrl + C entered!\n" "\x1b[0m");
    sleep(2);
    printf("exit!\n");
    exit(1) ;
}

/* setup signal handler, instead of using default handler*/
void setup_signal_handler(void){
    struct sigaction sa;
    sa.sa_handler = sint;
    sigaction(SIGINT, &sa, NULL);
}


int main()
{
    setup_signal_handler();
    foo();
    return 0;
}

void foo(void){
    while(1){
        printf("in function foo()\n");
        sleep(2);
    }
}
