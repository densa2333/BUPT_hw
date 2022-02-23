#include<stdio.h>
#include<math.h>

int main(void)
{
    double x;
    scanf("%lf", &x);
    
    double ex = 0;
    double i = 1.0;
    double an = 1.0;
    while (fabs(an) >= 1e-8) //注意思想：应该把每一项增量通过递推公式集成到循环里去
    {                        //而不是只知道每一次循环内现求通项再加到总和上
        ex += an;
        an *= x / i; //有递推公式：a[n] = a[n-1] * x / n!
        i++;
    }

    //printf("%.4f\n", exp(x));
    printf("%.4f\n", ex);

    return 0;
}

/*
#include<stdio.h>
#include<math.h>

int main(void)
{
    double x;
    scanf("%lf", &x);
    
    double ex = 1.0;
    double n = 1.0;
    double fact;
    while (fabs(pow(x, n) / fact) >= 1e-8)  *不采用每一次都求一次通项的老办法
    {
        fact = 1.0;
        for (int i = 1; i <= (int)n; i++)
        {
            fact *= i;
        }
        ex += fabs(pow(x, n) / fact);
        n += 1.0;
    }

    //printf("%.4f\n", exp(x));
    printf("%.4f\n", ex);

    return 0;
}
*/