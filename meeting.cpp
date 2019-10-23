#include "cstdio"
#include <climits>

long long min(long long a, long long b)
{
    return (a < b )? a : b;
}


int main()
{
    int n;
    scanf("%d\n", &n);
    long long d[n][n];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i == j)
                d[i][j] = 0;
            else
                d[i][j] = INT_MAX;
        }
    }

    for(int k = 0; k < n - 1; ++k)
    {
        int i, j, w;
        scanf("%d %d %d", &i, &j, &w);
        d[i-1][j-1] = w;
        d[j-1][i-1] = w;
    }


    for (int k=0; k<n; ++k)
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                d[i][j] = min (d[i][j], d[i][k] + d[k][j]);

    long long sum = 0;
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            sum += d[i][j];
            //printf("i = %d j = %d, w = %d\n", i, j, d[i][j]);
    printf("%d",sum);
    return 0;
}
