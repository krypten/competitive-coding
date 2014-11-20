#include<stdio.h>
int main()
{
        int t,n,i,max;
        float ans[100000];
        scanf("%d",&t);
        ans[0]=1;
        for(i=1; i<100000; i++)
        ans[i] = ans[i-1] + 1.0/(i+1);
        while(t--)
        {
                scanf("%d",&n);
                printf("%.3f\n",ans[n-1]);
        }
        return 0;
}
