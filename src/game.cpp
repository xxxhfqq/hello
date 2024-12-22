#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3 // 3x3 华容道

// 打印游戏面板
void printBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0)
                printf("   "); // 空白方块
            else
                printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

// 检查游戏是否已完成（方块是否按顺序排列）
int isSolved(int board[SIZE][SIZE]) {
    int correct[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != correct[i][j]) {
                return 0; // 未完成
            }
        }
    }
    return 1; // 已完成
}

// 查找空白方块的位置
void findEmptySpot(int board[SIZE][SIZE], int *row, int *col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// 交换两个位置的数字
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 移动方块
int move(int board[SIZE][SIZE], char direction) {
    int row, col;
    findEmptySpot(board, &row, &col);
    
    if (direction == 'w' && row > 0) {
        swap(&board[row][col], &board[row - 1][col]);
    } else if (direction == 's' && row < SIZE - 1) {
        swap(&board[row][col], &board[row + 1][col]);
    } else if (direction == 'a' && col > 0) {
        swap(&board[row][col], &board[row][col - 1]);
    } else if (direction == 'd' && col < SIZE - 1) {
        swap(&board[row][col], &board[row][col + 1]);
    } else {
        return 0; // 无效移动
    }
    return 1; // 移动成功
}

// 打乱方块的排列
void shuffleBoard(int board[SIZE][SIZE]) {
    srand(time(0)); // 设置随机种子
    for (int i = 0; i < 1000; i++) {
        char directions[] = {'w', 'a', 's', 'd'};
        char moveDir = directions[rand() % 4];
        move(board, moveDir); // 随机进行1000次移动
    }
}

int main() {
    int board[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };
    
    shuffleBoard(board); // 打乱游戏方块

    while (1) {
        printBoard(board); // 显示当前游戏面板

        if (isSolved(board)) {
            printf("恭喜你，游戏完成！\n");
            break;
        }

        printf("请输入移动指令 (w = 上, s = 下, a = 左, d = 右): ");
        char moveDir;
        scanf(" %c", &moveDir);

        if (!move(board, moveDir)) {
            printf("无效的移动，请重新输入。\n");
        }
    }

    return 0;
}
