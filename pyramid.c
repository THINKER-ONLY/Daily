#include<stdio.h>
int main(void)
{
    //声明变量
    int i,j,k;
    //循环行数
    for(i=0;i<11;i++)
    {
        //循环空格数
        for(j=(40-3*i);j>0;j--)
            printf(" ") ;
        for(k=1;k<=(2*i-1);k+=2)
            if(k<10)
                printf("%d  ",k) ;
            else
                printf("%d ",k) ;
        for(k;k>=1;k-=2)
            if(k<10)
                printf("%d  ",k) ;
            else
                printf("%d ",k) ;
        printf("\n") ;
    }
    return 0;
}