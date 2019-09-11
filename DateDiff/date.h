#ifndef __DATE_H__
#define __DATE_H__

#include <iostream>
#include <cstring>
#include <string>

using namespace std;
unsigned int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date{
public:
    Date();
    void setdate(void);
    void showinfo(void);
    void checkcorrect(void);
    void countofday(void);
    unsigned getcountday() const { return countday; }
private:
    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int countday;
};

unsigned datediff(const Date &d1, const Date &d2);
bool isleap(unsigned);
void foo(void);

Date::Date(){                                                                   
    setdate();
}

void Date::setdate(void){
    char buf[128] = {0};
    char *tmp = buf;
    const char *p = buf;
    cout << "Please enter date(yy-mm-dd, eg:1970-01-01)" << endl;
    cin >> buf; 
    //判断输入长度是否大于最大输入长度
    if( strlen(buf) > 10 ){
        cout << "enter too long" << endl;
        exit(1);
    }
    //将输入中的"-"替换成空格
    for(int i = 0; i < 2; i++){
        if( !(tmp =  const_cast<char *>(strstr(p, "-")) )){
            cout << "the input does't follow the format yy-mm-dd" << endl;
            exit(1);
        }
        *tmp = ' ';
        tmp++;
        p = tmp;
    }
    //将输入赋值给year, month, day
    if ( sscanf(buf, "%d %d %d", &year, &month, &day) != 3 ){
        perror("Initialize class Date error!");
        exit(1);
    }
    checkcorrect();
    countofday();
}

void Date::showinfo(void){
    cout << "year: " << year << endl;
    cout << "month: " << month << endl;
    cout << "day: " << day << endl;
}

void Date::checkcorrect(void){
    //年份限制在3000年以内
    if( year > 3000 ){
        cout << "out of year" << endl;                                          
        exit(1);
    }
    
    //月份1~12月
    if( month > 12 || month == 0 ){
        cout << "out of month" << endl;
        exit(2);
    }

    //判断day和month, year是否相符
    if( day < 31 && day > 0 ){
        //只有1, 3, 5, 7, 8, 10, 12月有31日
        if( day == 31 ){
            if( month == 1 || month == 3 || month == 5  ||
                month == 7 || month == 8 || month == 10 ||
                month == 12)
                ;//正确，什么都不做
            else{
                goto out_of_day;
            }
        }
        if( day > 29 ){
            if( month == 2 ){
                goto out_of_day;
            }
        }

        //判断2月最大天数
        if( day == 29 ){
            if( month == 2 )
                if( !isleap(year) )
                    goto out_of_day; // 平年的2月不能超过28天
        }
    }
    return;
out_of_day:
    cout << "out of day" << endl;
    exit(3);
}

void Date::countofday(void){
    unsigned count = 0;
    unsigned i;
    count = year * 365;
    for(i = 0; i < year; i++){
        if( isleap(i) )
            count++;
    }
    for(i = 1; i < month; i++){
        count += m[i];
    }
    count += day;
    //判断输入的年份year是否是闰年
    if( isleap(year) && month > 2 )
        count++;

    countday = count;
    return;
}

#endif
