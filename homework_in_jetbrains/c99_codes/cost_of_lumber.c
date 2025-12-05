#include <stdio.h>
#define P 0.89
#define F 1.09
#define C 2.26
#define M 4.50
#define O 3.10
#define INCH_TO_FEET (1/12.0)

double calculate(char type ,int amount,int width,int height,int length) {
    double price, board_foot = amount*width*height*length*INCH_TO_FEET;
    if (type=='P')
        price=board_foot*P;
    else if (type=='F')
        price=board_foot*F;
    else if (type=='C')
        price=board_foot*C;
    else if (type=='M')
        price=board_foot*M;
    else
        price=board_foot*O;
    return price;
}

int main() {
    char type,c;
    int amount ,height,width,length,i=0;
    double price[100], total = 0.0;
    while (scanf(" %c", &type) == 1) {
        if (type == 'T') {  // 输入 T，结束订单读取
            break;
        }

        scanf("%d %d %d %d", &amount, &width, &height, &length);

        price[i] = calculate(type, amount, width, height, length);
        total += price[i];
        i++;  // 索引自增，准备存储下一笔订单
    }int j = 0;
    while (j<i) {
        printf("%.2f\n",price[j]);
        j++;
    }printf("%.2f\n",total);
}
/*描述

你正在为一家木材（家具）公司工作，他们希望你编写一个程序来计算订单的木材费用。公司销售的木材种类包括：松木（Pine）、杉木（Fir）、雪松（Cedar）、枫木（Maple）和橡木（Oak）。木材的价格按 板尺（board foot） 计算。一个板尺等于 1 平方英尺面积，厚度为 1 英寸。各类木材的单价如下表：
木材种类 单价 （美元/板尺）
松木 (Pine) 0.89
杉木 (Fir) 1.09
雪松 (Cedar) 2.26
枫木 (Maple) 4.50
橡木 (Oak) 3.10
木材以不同的尺寸出售（宽度和高度以英寸为单位，长度以英尺为单位），需要转换为板尺。 例如：一块 2×4×8 的木材，宽度为 2 英寸，高度为 4 英寸，长度为 8 英尺，相当于 5.333 板尺
用户输入的格式为：一个字母加上四个整数。
四个整数分别表示：木材数量、宽度（英寸）、高度（英寸）和长度（英尺）。
字母表示木材种类：P（松木）、F（杉木）、C（雪松）、M（枫木）、O（橡木）。
特殊字母 T 表示 Total（总价），此时输入行中不再跟随整数。
程序应当输出每一项的费用，并在输入 T 后输出总费用，如下例所示
输入
P 10 2 4 8
M 1 1 12 8
T
输出
47.47
36.00
83.47*/