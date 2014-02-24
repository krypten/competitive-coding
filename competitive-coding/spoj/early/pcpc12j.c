#include<stdio.h>
int main()
{ int i,j,max,k,tc,a[10001],c,n;
 tc=0;    
    scanf("%d",&tc);
    while(tc--)   
    {  c=10001;max=0;fflush(stdin);
       for(k=1;k<10001;k++)
       a[k]=0;
       scanf("%d",&n);    
       for(i=1;i<=n;i++) 
       {
           scanf("%d",&j);
           a[j]++;       
       }        
       for(i=1;i<=n;i++)
       {if((a[i]%i)==0&&(a[i]>(max))&&(a[i]>0))
       {c=i;
       max=a[i];}}
       if(c==10001)
       printf("-1\n");
       else
       printf("%d\n",c); 
    }
 return 0;
}
