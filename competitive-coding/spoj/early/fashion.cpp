#include<stdio.h>
#include<conio.h>
#include<iostream.h>
int main()
{ int x[128];
  int y[128];
  int sum; int i,j,n,t;
  scanf("%d",&t);
    for(i=0;i<t;i++)
    {  n=0;
       sum=0;
       scanf("%d",&n);
       for(j=0;j<n;j++)
       {scanf("%d",&x[j]);               
        }
       
        for(j=0;j<n;j++)
       { scanf("%d",&y[j]);
       
       }
       
       for(j=0;j<n;j++)
       { sum+=x[j]*y[j];   
       }            
    printf("%d",sum);
    }
    getch();
    return 0;
}
