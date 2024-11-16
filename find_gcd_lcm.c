#include<stdio.h>
//声明函数
int find(int a,int b);
int find0(int a,int b);
int main(void)
{
    //声明变量
    int arr[5]={16,2,4,8,32};
    int result=arr[0];
    int result_0=arr[0];
    //循环，利用辗转求余法求出最大公因子
    for(int i=1;i<5;i++)
    {
        result = find(result,arr[i]);
    }
    //求最小公倍数
    for(int i=1;i<5;i++)
    {
        result_0 = find0(result_0,arr[i]);
    }
    printf("%d\n",result);
    printf("%d\n",result_0);
}
//求公因子函数
int find(int a,int b)
{
    while(b!=0)
    {
        int temp=b;
        b = a%b;
        a = temp;
    }
    return a;
}
//求公倍数函数
int find0(int a,int b)
{
    return (a * b) / find(a,b);
}