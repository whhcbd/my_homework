#include <stdio.h>

// 定义获胜状态
#define WHITE_WIN 1
#define BLACK_WIN 2
#define NO_WINNER 0

// 判断胜负的函数
int checkWinner(char board[10][11]) {
    // 检查水平方向
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= 5; j++) {
            // 检查白棋是否连成五子
            if (board[i][j] == 'W' && board[i][j+1] == 'W' &&
                board[i][j+2] == 'W' && board[i][j+3] == 'W' &&
                board[i][j+4] == 'W') {
                return WHITE_WIN;
            }
            // 检查黑棋是否连成五子
            if (board[i][j] == 'B' && board[i][j+1] == 'B' &&
                board[i][j+2] == 'B' && board[i][j+3] == 'B' &&
                board[i][j+4] == 'B') {
                return BLACK_WIN;
            }
        }
    }

    // 检查垂直方向
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i <= 5; i++) {
            // 检查白棋是否连成五子
            if (board[i][j] == 'W' && board[i+1][j] == 'W' &&
                board[i+2][j] == 'W' && board[i+3][j] == 'W' &&
                board[i+4][j] == 'W') {
                return WHITE_WIN;
            }
            // 检查黑棋是否连成五子
            if (board[i][j] == 'B' && board[i+1][j] == 'B' &&
                board[i+2][j] == 'B' && board[i+3][j] == 'B' &&
                board[i+4][j] == 'B') {
                return BLACK_WIN;
            }
        }
    }

    // 检查主对角线（左上到右下）
    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= 5; j++) {
            // 检查白棋是否连成五子
            if (board[i][j] == 'W' && board[i+1][j+1] == 'W' &&
                board[i+2][j+2] == 'W' && board[i+3][j+3] == 'W' &&
                board[i+4][j+4] == 'W') {
                return WHITE_WIN;
            }
            // 检查黑棋是否连成五子
            if (board[i][j] == 'B' && board[i+1][j+1] == 'B' &&
                board[i+2][j+2] == 'B' && board[i+3][j+3] == 'B' &&
                board[i+4][j+4] == 'B') {
                return BLACK_WIN;
            }
        }
    }

    // 检查副对角线（右上到左下）
    for (int i = 0; i <= 5; i++) {
        for (int j = 4; j < 10; j++) {
            // 检查白棋是否连成五子
            if (board[i][j] == 'W' && board[i+1][j-1] == 'W' &&
                board[i+2][j-2] == 'W' && board[i+3][j-3] == 'W' &&
                board[i+4][j-4] == 'W') {
                return WHITE_WIN;
            }
            // 检查黑棋是否连成五子
            if (board[i][j] == 'B' && board[i+1][j-1] == 'B' &&
                board[i+2][j-2] == 'B' && board[i+3][j-3] == 'B' &&
                board[i+4][j-4] == 'B') {
                return BLACK_WIN;
            }
        }
    }

    // 没有获胜者
    return NO_WINNER;
}

int main() {
    char board[10][11];
    for (int i = 0; i < 10; i++) {
        scanf("%s", board[i]);
    }

    int result=NO_WINNER;
    result=checkWinner(board);
    if (result==WHITE_WIN){
        printf("N");
    return 0;
    }

    for (int i = 0;i<10;i++) {
        for (int j= 0;j<10;j++) {
            if (board[i][j]=='.') {
                board[i][j]='B';
                result = checkWinner(board);
                if (result == BLACK_WIN) {
                    printf("Y");
                    return 0;
                }
                board[i][j]='.';
            }
        }
    }

    printf("N");
    return 0;
}

/*描述
你在和人下五子棋，下一步轮到你执黑落子，请判断黑棋是否已经输了，若没有，下一步黑棋能否获胜
输入为10×10的棋盘，.代表未落子，B代表黑子，W代表白子
输出为Y或N，Y代表能够获胜，N已经输了或者下一步不能获胜


输入描述
10×10的棋盘

输出描述
一个字母*/