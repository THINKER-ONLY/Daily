/*键盘上输入一个四位不全相同的四位数X，当X不等于6174时，执行： 

     1）把构成这四位数的四个数位从大到小排列，构成一个最大的四位数MAX； 

     2）把构成这个四位数的四个数位从小到大排列，构成一个最小的四位数MIN（当有效数位为0时，MIN可能不是四位数了） 

     3）X＝MAX-MIN；当X不等于6174时，转回1）继续执行，经过有限步后，X最终能达到6174 */

//不使用数组的解法
#include <stdio.h>
int main(void)
{
    int X ,temp ;
    printf("请输入一个四位不全相同的四位数：") ;
    scanf("%d",&X) ;
    int a,b,c,d;
    int MAX , MIN ;
    //先切片，分别判断各位是否相等
    d = X%10 ;
    c = (X/10)%10 ;
    b = (X/100)%10 ;
    a = X/1000 ;
    if (X<1000||X>10000)
    {
        printf("输入错误，请重新输入") ;
    }
    else if(a==b&&a==c&&a==d)
    {
        printf("输入错误，请重新输入") ;
    }
    else
    {
        //进入死循环，如果无发法得到6147就会一直循环
        while(1)
        {
            d = X%10 ;
            c = (X/10)%10 ;
            b = (X/100)%10 ;
            a = X/1000 ;
            //进行排序
            if (a <= b) { temp = a ; a = b ; b = temp ;} 
            if (a <= c) { temp = a ; a = c ; c = temp ;} 
            if (a <= d) { temp = a ; a = d ; d = temp ;} 
            if (b <= c) { temp = b ; b = c ; c = temp ;} 
            if (b <= d) { temp = b ; b = d ; d = temp ;} 
            if (c <= d) { temp = c ; c = d ; d = temp ;}
            MAX = a * 1000 + b * 100 + c * 10 + d ;
            //对MIN的最小值千位可能为0的情况进行补丁
            if (d==0)
                MIN =c * 1000 + b * 10 + a ;
            else
                MIN = d * 1000 + c * 100 + b * 10 + a ;
            X = MAX - MIN ;
            if (X == 6174)
                break ;
            else 
                continue ;
        }
        printf("成功\n") ; 
        printf("最终的MAX为%d,MIN为%d",MAX,MIN) ;
    }
    return 0 ;
}
