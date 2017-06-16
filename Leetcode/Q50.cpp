//快速求A^n，A可以是数，也可以是矩阵。
//不是对A开方！
//注意n可正可负


double Pow(double a,int n)
{   
    if(n < 0) n = -n;
    int result = 1;
    while(n > 0)
    {
        if(n & 1 == 1) //奇数
            result *= a;
        a*=a;
        n >>= 1;
    }
    return result;
}


//
2.00000
-2147483648

//每次使用n= - n就要注意当n为负数最小的时候，-n表示的并不是最大。
//2147483648用long能表示


//矩阵快速幂乘计算Fabonacci序列
//
1,1,2,3,5
用a,b表示不断递推的两个数

初始化a=1,b=1;
b = a+b;
a = b;

[b,a]^T = [a+b,b]^T

//可以推广到各种线性递推式上。