#include <stdio.h>
#include <stdlib.h>
//声明函数
int out(int *ptr,int number);
void take(int n,int *ptr);
int main()
{
    int n;
    //在堆上分配一个内存，使其无限存储
    int *ptr = (int*)malloc(((n+1) * ((n+1) + 1)) / 2 * sizeof(int));
    printf("请输入一个n的值：");
    scanf("%d",&n);
    //调用函数
    take((n+1),ptr);
    out(ptr,n);
    free(ptr);
    return 0;
}
int out(int *ptr,int number)
{
    int num = number;
    int count = 1;
    int j =0;
    //循环直到结束
    while(num >= 0)
    {
        for (int i = 0;i < num*2; i++)
            printf(" ");
        for (int i = 0;i < count; i++)
        {
            printf("%d   ",ptr[j]);
            j++;
        }
        for (int i = 0;i < num*2; i++)
            printf(" ");
        count ++;
        num --;
        printf("\n");
    }
}
void take(int n,int *ptr)
{
    //通过公式进行计算
    ptr[0] = 1;
    for (int i=0; i< n;i++)
    {
        ptr[i * (i + 1) / 2] = 1;
        for (int j=1; j< i; j++)
            ptr[i * (i + 1) / 2 + j] = ptr[(i - 1) * i / 2 + j - 1] + ptr[(i - 1) * i / 2 + j];
        ptr[i * (i + 1) / 2 + i] = 1;
    }
}