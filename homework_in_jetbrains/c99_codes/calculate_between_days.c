#include <stdio.h>

int is_leap_year(int year) {
    return(year%4==0&&year%100!=0||year%400==0);
}

int date_to_total_days(int year, int month, int day) {
    int total_days = 0;
    for (int i = 0; i < year; i++) {
        total_days += is_leap_year(i) ? 366 : 365;
    }
    int days_per_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    for (int m = 1 ; m < month ; m++) {
        total_days += days_per_month[m];
        if (m==2&&is_leap_year(year)) {
            total_days ++;
        }
    }
    total_days += day;
    return total_days;
}

int main() {
    int startYear,startMonth,startDay,endYear,endMonth,endDay;
    scanf("%d %d %d",&startYear,&startMonth,&startDay);
    scanf("%d %d %d",&endYear,&endMonth,&endDay);
    int start = date_to_total_days(startYear,startMonth,startDay);
    int end = date_to_total_days(endYear,endMonth,endDay);
    int diff = end-start;
    printf("%d",diff);
    return 0;
}
/*描述
蒜头君给定两个日期，请计算相差的天数。比如 2010-1-1 和 2010-1-3 相差 2 天。
输入描述
共两行：
第一行含三个整数 startYear，startMonth，startDay，分别是起始年、月、日。
第二行包含三个整数 endYear，endMonth，endDay，分别是结束年、月、日。
相邻两个整数之间用单个空格隔开。
年份范围在 1∼3000。保证日期正确且结束日期不早于起始日期。
输出描述
输出一个整数，即是两个日期相差的天数。*/