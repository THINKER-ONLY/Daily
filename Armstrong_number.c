//水仙花数（Armstrong number）是一个n（n>=3）位数字的数，它等于每位数字的n次幂的和。例如153是水仙花数（具有3位数字且等于13+33+53）。试编写一个程序，求解给定的n位数字内的所有水仙花数。
#include <stdio.h>

void number(int B,int N )
{
    int num_1 , sum = 0 , y = B ;
    //定义一个变量用于盛放原始的num_1的值
    int i ;
    //循环遍历每一位上的数字
    while(B != 0)
    {
        num_1 = B % 10 ;
        i = num_1 ;
        //循环确定幂的值
        for(int temp = 1 ; temp < N ; temp ++)
        {
            i *= num_1 ;
        }
        sum += i ;
        B /= 10 ;        
    }
    if (sum == y)
        printf("%d\n",y) ;
}

int main(void)
{
    int n ;
    printf("请给定位数：") ;
    scanf("%d",&n) ;
    //判断位数
    if (n<3)
        printf("你输入的位数不正确") ;
    else 
    {
        int a = 1 ,x = 10 ;
        int b = 100 ;
        //循环确定水仙花数的具体范围
        for (a ; a < n ; a++)
            x *= 10 ;
        for (b ; b < x ; b++)
            number(b,n) ;
    }
}

