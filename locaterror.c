/*
    功能：
         1.定位程序出错的地方，用到了三个宏定义：__FILE__, __FUNCTION__, __LINE__
         2.能够彩色显示，设置前景色和背景色等。
*/

#include <stdio.h>
#include <stdlib.h>

#define E_RED "\x1b[0;31m"
#define E_CLR "\x1b[0m"

#define SAYF(x...) fprintf(stderr, x)
#define PFATA(x...) do{ \
    SAYF(E_RED "[!] error\n" E_CLR "file: %s, function: %s(), line: %d\n", __FILE__, __FUNCTION__, __LINE__); \
    exit(1);\
}while(0)


void diserr(int n)
{
    if(n > 0)
    {
        PFATA("n must be minus!");
    }
}

int main()
{
    diserr(3);
    return 0;
}
