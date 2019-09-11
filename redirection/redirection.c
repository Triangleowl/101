/*
    使用dup2()将标准输入重定向到文件"input"
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void foo(void){
    int a;
    int fd = open("input", O_RDWR);
    dup2(fd, 0);
    scanf("%d", &a);

    printf("a is: %d\n", a);
}


int main(){

    foo();
    return 0;
}
