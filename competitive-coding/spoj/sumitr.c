#define I int
#define M(a,b) (a>b?a:b)
#define S(x) scanf("%d",&x)
I main(){I t,n,i,j,A[128][128];S(t);while(t--){S(n);for(i=0;i<n;++i)for(j=0;j<=i;++j)S(A[i][j]);for(i=n-1;i>0;--i)for(j=0;j<i;++j)A[i-1][j]+=M(A[i][j],A[i][j+1]);printf("%d\n",A[0][0]);}}