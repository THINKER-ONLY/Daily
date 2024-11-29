/*（函数）把一个十进制整数转换成任意进制数输出。要求：从键盘输入十进制数，再输入要转换成的进制数。*/
#include <stdio.h>
//声明函数
void tran(int num,int x,char number[],char new[]);
void reback(char number[],int i,char new[]);
int main()
{
    //声明变量
    int num,x;
    char number[100];
    char new[100];
    printf("请输入想要转化的数字和想要转换的进制：");
    scanf("%d %d",&num,&x);
    //调用函数
    tran(num,x,number,new);
    printf("你想要将%d转换为%d进制,转换后的数为%s",num,x,new);
    return 0;
}
void tran(int num,int x,char number[],char new[])
{
    int i=0;
    //判断是否为负数
    int real = num < 0;
    if (real)
        num = -num;
        //循环进行转化
    while(num != 0)
    {
        int temp = num % x ;
        number[i] = (temp < 10) ? ('0' + temp) : ('A' + temp - 10);
        i ++ ;
        num /= x;
    }
    number[i] = '\0';
    reback(number,i,new);
}
void reback(char number[],int i,char new[])
{
    //头尾调转，使其能输出正确的数
    int k = 0;
    for (int j = (i-1); j>=0;j--)
    {
        new[k] = number[j];
        k++;
    }
    new[k] = '\0';
}