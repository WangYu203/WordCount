// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // 检查参数数量是否正确
    if (argc != 3) {
        printf("用法: %s [-c|-w] 输入文件名\n", argv[0]);
        return 1;
    }

    // 打开文件
    FILE* fp = fopen(argv[2], "r");
    if (fp == NULL) {
        perror("打开文件失败");
        return 1;
    }

    int count = 0;
    int ch;
    int in_word = 0; // 标记当前是否在单词中

    if (strcmp(argv[1], "-c") == 0) {
        // 统计字符数（包含空格、制表符、换行符）
        while ((ch = fgetc(fp)) != EOF) {
            count++;
        }
        printf("字符数：%d\n", count);
    }
    else if (strcmp(argv[1], "-w") == 0) {
        // 统计单词数（空格或逗号分隔）
        while ((ch = fgetc(fp)) != EOF) {
            if (isspace(ch) || ch == ',') {
                in_word = 0;
            }
            else if (!in_word) {
                in_word = 1;
                count++;
            }
        }
        printf("单词数：%d\n", count);
    }
    else {
        printf("无效参数！请使用 -c 或 -w\n");
        fclose(fp);
        return 1;
    }

    fclose(fp);
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
