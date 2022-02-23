#include<stdio.h>
#include<math.h>

int main(void)
{
    int m, n, x, y, z, sum = 0;
    
    scanf("%d %d", &m, &n);

    for (z = m; z <= n; z++)
    {
        for (y = m; y <= n; y++)
        {
            for (x = m; x <= n; x++)
            {
                if (x * x * z * z + y * y * z * z == x * x * y * y)
                {
                    //printf("%d %d %d\n", x, y, z);
                    sum++;
                }
            }
        }
    }

    printf("%d", sum / 2);
    
    return 0;
}