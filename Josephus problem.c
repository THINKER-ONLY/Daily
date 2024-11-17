/* 已知t个人围坐在一张圆桌周围，他们每个人都有编号，编号依座位顺序从1到t。从编号为k的人开始报数，数到m的那个人出列;
他的下一个人又从1开始报数，数到m的那个人又出列;
依此规律重复下去，直到圆桌周围的人全部出列。
请编程输出所有人出列的顺序。要求：从键盘分别输入k和m。*/
#include<stdio.h>
#include<stdlib.h>
int main() 
{
    //声明变量
    int t, m, k;
    int count = 0,step = 0; ;
    printf("请输入总人数t：");
    scanf("%d", &t);
    printf("请输入m：");
    scanf("%d", &m);
    printf("请输入开始报数的人的编号k：");
    scanf("%d", &k);
    //判断是否为正确输入
    if (k < 1 || k > t) 
    {
        printf("编号k必须在1到%d之间。\n", t);
        return 1;
    }
    //在堆上显式声明内存来存放数组，可不提前定义数组的大小
    int *people = (int *)malloc(t * sizeof(int));
    for (int i = 0; i < t; i++) 
    {
        people[i] = 1;
    }
    int num = k - 1; 
    //循环进行游戏
    while (count < t) 
    {
        for (int i = 0; i < m; i++) 
        {
            while (people[num] == 0) 
            { 
                num = (num + 1) % t; 
            }
            step++; 
            if (step == m) 
            { 
                // 标记为出列
                people[num] = 0; 
                printf("%d出列\t", num + 1);
                step = 0; 
                num = (num + 1) % t; 
                count++; 
                break; 
            }
            num = (num + 1) % t; 
        }
    }
    // 释放内存
    free(people); 
    return 0;
}