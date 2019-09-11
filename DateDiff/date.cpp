/*
 * Date:2019-08-31
 * Description:计算两个时间的时间差（以天为单位）
 *
 */
#include "date.h"

int main()
{
    foo();
    return 0;
}

void foo(void){
    unsigned diff = 0;
    Date date1, date2;
    date1.showinfo();
    date2.showinfo();

    diff = datediff(date1, date2);
    cout << "the date diff is: " << diff << endl;
}

bool isleap(unsigned y){
    if( (y%4 ==0 && y%100 != 0) || y%400 == 0 )
        return 1;
    else
        return 0;
}

unsigned datediff(const Date &d1, const Date &d2){
    unsigned c1 = d1.getcountday();
    unsigned c2 = d2.getcountday();
    if(c1 >= c2)
        return c1 - c2;
    else 
        return c2 - c1;

}
