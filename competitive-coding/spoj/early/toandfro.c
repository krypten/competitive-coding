#include<stdio.h>
int main()
{ int l,i,j,k,n,u,a,b,flag,ctr;
char arr[256];
char arr1[256];
    
    while(1)   
    {  n=0;l=0;u=0; k=0; flag=1; ctr=0;
       scanf("%d",&n);
       if(n==0)
       break;
       scanf("\n");
       while(flag)
       { 
         for(a=0;a<n;a++)
         {
           scanf("%c",&arr[a+(2*ctr*n)]);
           if (arr[a+(2*ctr*n)]=='\n')
           { flag=0;
             break;  }
         l++;
         }
         if(flag)
         { for(b=0;b<n;b++)
           {
             scanf("%c",&arr[(((2*ctr)+1)*n)+n-b-1]); 
             if (arr[(((2*ctr)+1)*n)+n-b-1]=='\n')
             { flag=0;
               break;  }
             l++;
           }
          if(flag) 
          ctr++; 
         }
       }
       u=(l/n);
       for(i=0;i<n;i++)
       {
         for(j=0;j<u;j++,k++)
         { arr1[k]=arr[i+(j*n)];
           printf("%c",arr1[k]);
         }       
       }
       printf("\n");
    }

return 0;
}
                       
