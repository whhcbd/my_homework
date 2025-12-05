#include <stdio.h>

int array[201];

int change_position(int index,int num,int array[],int total) {
    for (int i=total;i>index;i-- )
        array[i]=array[i-1];
    array[index]=num;
    return total+1;
}

int clear_positon(int i ,int array[],int n ) {
    for (int k = i;k<n-1;k++)
        array[k]=array[k+1];
    return n-1;
}

int clear_number(int num,int array[],int n) {
    int i = 0,count=0;
    while (i<n) {
        if (array[i]==num) {
            n = clear_positon(i, array, n);
            count++;
        }else
            i++;
    }
    if (count==0) {
        printf("Invalid Operation!");
    }
    return n;
}

void exchange_position(int i,int j,int array[]) {
    int temp=array[i];
    array[i]=array[j];
    array[j]=temp;
}

int main() {
    int n , k ;
    scanf("%d",&n);
    for (int i =0;i<n;i++)
        scanf("%d",&array[i]);
    scanf("%d",&k);
    getchar();

    char operation_type;
    int i,num;
    for (int j = 0;j<k;j++) {
        scanf(" %c",&operation_type);
        switch (operation_type) {
            case 'U': //更新
                scanf("%d %d", &i, &num);
                if (i < 0 || i >= n)
                    printf("Invalid Operation!\n");
                else
                    array[i] = num;
                break;

            case 'I': //插入
                scanf("%d %d", &i, &num);
                if (i < 0 || i > n)
                    printf("Invalid Operation!\n");
                else
                    n = change_position(i, num, array, n);
                break;

            case 'D':  // 删除：下标i的元素
                scanf("%d", &i);
                if (i < 0 || i >= n)
                    printf("Invalid Operation!\n");
                else
                    n = clear_positon(i, array, n);
                break;

            case 'C':  //清除等于num的数
                scanf("%d", &num);
                n = clear_number(num, array, n);
                break;

            case 'S':  // 交换：下标i和下标num的元素
                scanf("%d %d", &i, &num);
                if (i < 0 || i >= n || num < 0 || num >= n)
                    printf("Invalid Operation!\n");
                else
                    exchange_position(i, num, array);
                break;

            case 'Q':  // 查询：下标i的元素值
                scanf("%d", &i);
                if (i < 0 || i >= n)
                    printf("Invalid Operation!\n");
                else
                    printf("%d\n", array[i]);
                break;

            default:
                printf("Invalid Operation!\n");
                while (getchar() != '\n');
                break;
        }
    }
    return 0;
}

/*描述
对一个数组进行增删改查等操作，并输出对应结果。输入保证数组大小不超过200。
输入第一行为n，代表数组初始n个数字。
第二行输入n个数字，代表数组c初始元素。
第三行输入k，代表后面有k个操作。
后面k行，以字符开头，代表一个操作，请注意操作的位置，确定操作合法性。
若开头字符为U，代表更新，该行后面跟两个数字，第一个为需要更新的元素的下标，第二个为更新的数字。操作成功，则无需输出，若操作非法，则输出"Invalid Operation!"。
若开头字符为I，代表插入，该行后面跟两个数字，第一个为插入下标，第二个为插入的数字。若操作成功，则无需输出，若操作非法，则输出"Invalid Operation!"。
若开头字符为D，代表删除，该行后面跟一个数字，代表需要删除的元素的下标。若操作成功，则无需输出，若操作非法，则输出"Invalid Operation!"。
若开头字符为C，代表清除，该行后面跟一个数字，代表需要清除的数字，请清除数组中所有该数字。若操作成功，则无需输出，若无该数字，则输出"Invalid Operation!"。
若开头字母为S，代表交换，该行后面跟两个数字，代表需要交换的两个元素的下标，请将两个元素位置交换。若操作成功，则无需输出，若操作非法，则输出"Invalid Operation!"。
若开头字母为Q，代表查询，该行后面跟一个数字，代表需要查询的元素下标。若查询成功，请直接输出元素值，若查询非法，请输出"Invalid Operation!"。

请根据操作进行相应的输出，每个输出占一行。


用例输入 1
5
10 20 30 40 50
6
U 0 88
I 2 99
Q 2
S 0 5
D 10
C 20

用例输出 1
99
Invalid Operation!

提示

注意插入操作允许的下标范围和其余操作不一样。
注意读入字符时换行符的影响
样例解释：
初始状态: [10, 20, 30, 40, 50]
U 0 88 : 数组变为 [88, 20, 30, 40, 50]
I 2 99 : 数组变为 [88, 20, 99, 30, 40, 50]
Q 2 : 输出 99
S 0 5 : 数组变为 [50, 20, 99, 30, 40, 88]
D 10 : 输出 Invalid Operation! (下标越界)
C 20 : 数组变为 [50, 99, 30, 40, 88]
*/