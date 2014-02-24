#include<stdio.h>
#include<conio.h>
int main()
{ long long int c[10001], car[10001];
int n,i,flag;
signed int d;
    while(1)   
    { scanf("%d",&n);
      if(n==0)
      break;
      flag=0;
      for(i=1;i<=n;i++)
      car[i]=c[i]=0;
      for(i=1;i<=n;i++)
      {
          scanf("%d %d",&c[i],&d);
          if(d>=n)
          {flag=1;
          break; }
          car[i-d]=c[i];
      }  
      if(flag==1)
      printf("-1");
      else  
      for(i=1;i<=n;i++)
      printf("%d ",car[i]);
      printf("%d ",c[i]);
      printf("\n");
    }
getch();
return 0 ;
}
