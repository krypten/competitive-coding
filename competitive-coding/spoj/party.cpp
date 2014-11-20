#include<stdio.h>

int max(int a, int b){
    if(a > b){
        return a;
    } else {
        return b;
    }
}

void dpro(int budget, int num, int dp[101][501], int w[101], int b[101])
{
    int i, j, k;
    for(i = 1; i <= num; i++){
        for(j = 0; j <= budget; j ++){
            if(j >= w[i]){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + b[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
}

int main(){
    int m,n,i,j;
    scanf("%d%d",&m,&n);
    while(m != 0 || n != 0){
        if(m == 0 || n == 0){
            printf("0 0\n");
            scanf("%d%d",&m,&n);
            continue;
        }
        int w[101];
        int b[101];
        for(i = 1; i <= n; i++){
            scanf("%d%d",&w[i],&b[i]);
        }
        int dp[101][501];
        for(i = 0; i <= n; i++){
            for(j = 0; j <= m; j++){
                dp[i][j] = 0;
            }
        }
        int best;
        dpro(m, n ,dp ,w, b);
                for(i = m, best = dp[n][m]; i; i--)
                        if(dp[n][i] < best)
                        break;
        printf("%d %d\n", i + 1, best);
        scanf("%d%d",&m,&n);
    }
    return 0;
}