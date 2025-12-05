#include <stdio.h>
#include <string.h>

int main(void) {
    // 哈布历19个月份（按顺序排列，前18个各20天，最后1个5天）
    char haab_months[19][20] = {
        "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen",
        "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"
    };
    // 卓金历20个日期名称（按循环顺序排列）
    char tzolkin_names[20][20] = {
        "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat",
        "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban",
        "eznab", "canac", "ahau"
    };

    int n;
    scanf("%d", &n);
    printf("%d\n", n); // 输出结果个数（与输入n一致）

    for (int i = 0; i < n; i++) {
        int haab_day, haab_year;
        char haab_month[20];
        // 解析哈布历输入：日数. 月份 年份（%d. 直接忽略小数点）
        scanf("%d. %s %d", &haab_day, haab_month, &haab_year);

        // 步骤1：找到输入月份在哈布历数组中的索引（0-18）
        int month_idx = -1;
        for (int j = 0; j < 19; j++) {
            if (strcmp(haab_month, haab_months[j]) == 0) {
                month_idx = j;
                break;
            }
        }

        // 步骤2：计算从世界开端到该日期的总天数
        int days_in_current_year = month_idx * 20 + haab_day; // 当年已过天数
        long long total_days = (long long)haab_year * 365 + days_in_current_year; // 总天数（用long long避免溢出）

        // 步骤3：用总天数计算卓金历日期
        int tzolkin_year = total_days / 260; // 卓金历每年260天（13×20）
        int cycle_day = total_days % 260;    // 在卓金历260天周期内的位置（0-259）
        int tzolkin_number = (cycle_day % 13) + 1; // 数字1-13循环（+1是因为从1开始）
        int name_idx = cycle_day % 20;       // 日期名称20个循环

        // 步骤4：输出卓金历日期
        printf("%d %s %d\n", tzolkin_number, tzolkin_names[name_idx], tzolkin_year);
    }

    return 0;
}
/*在他上一次休假期间，M. A. Ya 教授对古老的玛雅历法有了一个惊人的发现。从一条古老的绳结信息中，教授发现玛雅文明使用一种名为 哈布历（Haab） 的历年，每年 365 天，分为 19 个月。前 18 个月每月均为 20 天，月份名称依次为：pop、no、zip、zotz、tzec、xul、yoxkin、mol、chen、yax、zac、ceh、mac、kankin、muan、pax、koyab、cumhu。这些月份的日期以数字 0 至 19 表示（无名称）。哈布历的最后一个月名为 uayet（乌耶特月），仅有 5 天，日期以数字 0 至 4 表示。玛雅人认为这个月是不祥之月：法庭休庭、贸易停滞，人们甚至不会扫地。
出于宗教目的，玛雅人还使用另一种名为 卓金历（Tzolkin，神圣年） 的历法。卓金历每年分为 13 个周期，每个周期 20 天。每一天由 “一个数字 + 一个日期名称” 的组合唯一标识：数字循环使用 1 至 13（共 13 个），日期名称循环使用 20 个固定名称：imix、ik、akbal、kan、chicchan、cimi、manik、lamat、muluk、ok、chuen、eb、ben、ix、mem、cib、caban、eznab、canac、ahau。
需注意，每一天的标识都是唯一的。例如，卓金历一年开始时的日期依次为：1 imix、2 ik、3 akbal、4 kan、5 chicchan、6 cimi、7 manik、8 lamat、9 muluk、10 ok、11 chuen、12 eb、13 ben、1 ix、2 mem、3 cib、4 caban、5 eznab、6 canac、7 ahau，下一个周期又从 8 imix、9 ik、10 akbal…… 开始。
两种历法的年份均以数字 0、1、…… 表示，其中年份 0 代表世界的开端。因此，第一天在两种历法中的表示为：
哈布历：0 pop 0（pop 月 0 日，年份 0）
卓金历：1 imix 0（1 imix 日，年份 0）
请帮助 M. A. Ya 教授编写一个程序，将哈布历的日期转换为卓金历的日期。
输入描述
哈布历的日期格式如下：日数. 月份 年份
输入文件的第一行是输入日期的总个数 n；接下来 n 行，每行包含一个哈布历日期（每行一个日期）。输入的年份均小于 5000。
输出描述
卓金历的日期格式如下：数字 日期名称 年份
输出文件的第一行是输出日期的总个数（与输入 n 一致）；接下来 n 行，每行对应一个转换后的卓金历日期，顺序与输入日期一一对应。*/